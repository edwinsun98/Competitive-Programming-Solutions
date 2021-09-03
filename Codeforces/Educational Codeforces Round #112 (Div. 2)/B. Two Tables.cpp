#include <bits/stdc++.h>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

void solve(){
    ll w, h, w2, h2, x1, y1, x2, y2;
    cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> w2 >> h2;
    ll ans = 1e18;
    ll over = (x1 >= w2 ? 0 : w2-x1);
    if(x2+over <= w)ans = min(ans, over);
    over = (x2 <= w-w2 ? 0 : x2-(w-w2));
    if(x1-over >= 0)ans = min(ans, over);
    over = (y1 >= h2 ? 0 : h2-y1);
  
    if(y2+over <= h)ans = min(ans, over);
    over = (y2 <= h-h2 ? 0 : y2-(h-h2));
    if(y1-over >= 0)ans = min(ans, over);
    cout << (ans == 1e18 ? -1 : ans) << '\n';
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
