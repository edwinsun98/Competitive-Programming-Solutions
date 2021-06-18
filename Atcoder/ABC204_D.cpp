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
 
const int N = 1e5+3;
void solve(){
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    vector<bool> dp(N);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        for(int j = N-1; j >= a[i]; j--){
            if(dp[j-a[i]]){
                dp[j] = 1;
            }
        }
    }
    int ans = 2e9;
    for(int i = 0; i < N; i++){
        int a = i, b = sum-i;
        if(dp[a] && dp[b])
            ans = min(ans, max(a, b));
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
