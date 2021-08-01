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
    vector<double> dp(n+1);
    vector<int> a(n+1);
    vector<int> latest(n+1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    dp[n] = (a[n] == a[1] ? 1.0 : 0.0);
    latest[a[n]] = n;
    double sum = dp[n];
    for(int i = n-1; i >= 1; i--){
        if(a[i] == a[1])dp[i] = 1.0;
        else if(latest[a[i]] != 0)dp[i] = dp[latest[a[i]]];
        else dp[i] = (1.0+sum)/(n-i+1);
        sum += dp[i];
        latest[a[i]] = i;
    }
    cout << fixed << setprecision(9) << sum/n << '\n';
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
