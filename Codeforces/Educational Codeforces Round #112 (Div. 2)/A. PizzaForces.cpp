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
typedef pair<double, int> pdi;

void solve(){
    ll n;
    cin >> n;
    ll ans = 0, x;
    x = n/120;
    ans += x*300;
    n -= x*120;
    ll ans2 = 1e18;
    if(x >= 1)n += 120, ans -= 300;
    for(ll a = 0; ; a++){
        for(ll b = 0; ; b++){
            for(ll c = 0; ; c++){
                if(a*6+b*8+c*10 >= n)ans2 = min(ans2, a*15+b*20+c*25);
                if(a*6+b*8+c*10 >= n)break;
            }
            if(a*6+b*8 >= n)break;
        }
        if(a*6 >= n)break;
    }
    cout << ans+ans2 << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
}
