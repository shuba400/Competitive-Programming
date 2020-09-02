/*
Standard Subarray sum question but with the usage of map 
Thinking - If we know that sum of array upto certain element then keep storing the number of prefix
with same sum.
__TODO - update the logic part
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
typedef pair<ll,ll>     pll;
#define br "\n"
#define MAX  1000001
#define ff first
#define ss second
 
 
void solve(){
    ll n,k;
    cin >> n >> k;
    map<ll,ll> m;
    ll sum = 0,ans = 0;
    m[0]++;
    rep(i,0,n){
        ll x;
        cin >> x;
        sum += x;
        ans += m[sum - k];
        m[sum]++;
    }
    cout << ans;
 
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
 
}
