#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

void solve(){
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll x = n/m;
    ll ans = 1e18;
    for(ll i = x*m-m; i <= x*m+m+m; i += m){
        if(i >= 0){
            if(i == n){
                ans = 0;
            }else if(i > n){
                ans = min(ans, (i-n)*a);
            }else ans = min(ans, (n-i)*b);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    int tc = 1;
//    cin >> tc;
    while(tc--){
        solve();
    }
}
