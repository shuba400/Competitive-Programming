/*Amazing use of coordinate compression to reduce time complexity from O(n^2) to O(nlogn) 
  Question Link - https://cses.fi/problemset/task/1140
*/


#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
    
#define ll long long int
#define pb push_back
#define rep(i , j , n) for(ll i = j ; i < n ; i++)
#define pre(i , j , n) for(ll i = j ; i >= n ; i--)
#define all(x) x.begin(), x.end()
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<char>	vc;
typedef vector<bool>	vb;
typedef pair<ll,ll> 	pll;
#define br "\n"
#define ff first
#define ss second
ll MAX =  (ll)100005;
ll mod =  1e9 + 7;



void solve(){
    ll n;
    cin >> n;
    map<ll,ll> m;
    vll a(n),b(n),p(n);
    rep(i,0,n){
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        m[a[i]];
        m[b[i]];
    }
    ll cc = 0;
    for(auto &x:m){
        cc++;
        x.ss = cc;
    }
    cc++;
    vector<pll> v[cc];
    vll dp(cc,0);
    rep(i,0,n){
        v[m[b[i]]].pb({m[a[i]],p[i]});
    }
    rep(i,1,cc){
        dp[i] = dp[i - 1];
        for(auto x:v[i]){
            dp[i] = max(dp[i],dp[x.ff] + x.ss);
            // cout << i << " "<< x.ff << " " << x.ss << br;
        }
    }
    cout << dp[cc - 1];

}
	

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  

	ll t = 1;
	// cin >> t;
	rep(i,0,t){
		solve();
	}
    // cout << "Hello World";
 
}	
