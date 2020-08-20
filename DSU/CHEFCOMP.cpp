/*Todo -  explain thought process*/

#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
    
#define ll long long int
#define pb push_back
#define rep(i , j , n) for(ll i = j ; i < n ; i++)
#define pre(i , j , n) for(ll i = j ; i >= n ; i--)
#define all(x) x.begin(), x.end()
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<char>	vc;
typedef vector<bool>	vb;
#define br "\n"
#define MAX  1000001
#define ff first
#define ss second

vll parent,size,perm,pop,flow,ans,prefsum,prefday,day;
vb vis;
ll n,mod = 1e9 + 7;
vector<vll> grid,decomp;

void make_set(ll v) {
    parent[v] = v;
    size[v] = 1;
}

ll find_set(ll v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}


void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    parent[b] = a;
    size[a] += size[b];
}
 
void make_graph(){
    pre(i,n,1){
        ll y = perm[i];
        for(auto x:grid[y]){
            if(vis[x]){
                decomp[y].pb(find_set(x));
                decomp[find_set(x)].pb(y);
                union_sets(y,x);
            }
        }
        vis[y] = true;
    }
}

void dfs(ll u,ll v){
    prefsum.pb(prefsum.back() + pop[u]);
    prefday.pb(day[u]);
    if(prefsum.back() >= flow[u]){
        ll ind = lower_bound(all(prefsum),flow[u]) - prefsum.begin();
        ans[u] = prefday[ind];
    }
    else ans[u] = -1;
    for(auto x:decomp[u]){
        if(x != v) dfs(x,u);
    }
    prefday.pop_back();
    prefsum.pop_back();
}
 
void solve(){ 
    cin >> n;
    parent.resize(n + 1);
    size.resize(n + 1);
    perm.resize(n + 1);
    pop.resize(n + 1);
    flow.resize(n + 1);
    vis.assign(n + 1,false);
    grid.resize(n + 1);
    decomp.resize(n + 1);
    prefday.pb(0);
    prefsum.pb(0);
    day.resize(n + 1);
    ans.resize(n + 1);
    rep(i,1,n + 1) make_set(i);
    rep(i,1,n){
        ll a,b;
        cin >> a >> b;
        grid[a].pb(b);
        grid[b].pb(a);
    }
    rep(i,1,n + 1){ 
        cin >> perm[i];
        day[perm[i]] = i;
    }
    rep(i,1,n + 1) cin >> pop[i];
    rep(i,1,n + 1) cin >> flow[i];
    make_graph();
    ll root = find_set(1);
    dfs(root,root);
    rep(i,1,n + 1) cout << ans[i] << " ";
    cout << br;

    parent.clear();
    size.clear();
    perm.clear();
    pop.clear();
    flow.clear();
    vis.clear();
    grid.clear();
    decomp.clear();
    prefday.clear();
    prefsum.clear();
    day.clear();
    ans.clear();
    
}
	
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  
 
    ll t = 1;
    cin >> t;
    rep(i,0,t){
        solve();
    }
 
}	
