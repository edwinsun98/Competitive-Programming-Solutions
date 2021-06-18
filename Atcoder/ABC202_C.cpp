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
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1), f(n+1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        f[b[c[i]]]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)ans += f[a[i]];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
