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
    int n;
    cin >> n;
    vector<ll> a(2*n);
    for(int i = 0; i < 2*n; i++)cin >> a[i];
    sort(all(a));
    ll minv =  1e18;
    for(int i = 0; i < n; i++)minv = min(minv, a[i+n-1]-a[i]);
    cout << min((a[n-1]-a[0])*(a[n+n-1]-a[n]), minv*(a[2*n-1]-a[0])) << '\n';
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
