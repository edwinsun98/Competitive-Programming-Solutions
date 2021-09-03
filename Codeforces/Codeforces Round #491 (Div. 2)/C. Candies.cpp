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
    ll n;
    cin >> n;
    ll l = 1, r = n, m, ans = -1;
    while(l <= r){
        m = (l+r)/2;
        ll s = n, x = 0, y = 0;
        while(s > 0){
            x += min(s, m);
            s -= min(s, m);
            if(s == 0)break;
            y += s/10;
            s -= s/10;
        }
        if(x >= y){
            ans = m;
            r = m-1;
        }else l = m+1;
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
