#include <bits/stdc++.h>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;


void solve(){
    int n;
    cin >> n;
    vector<double> a(n+2), b(n+1);
    for(int i = 1; i <= n+1; i++)cin >> a[i];
    double ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        ans += ((abs(a[i]-a[i+1]))*b[i])/2;
        ans += b[i]*min(a[i], a[i+1]);
    }
    cout << fixed << setprecision(15) << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
