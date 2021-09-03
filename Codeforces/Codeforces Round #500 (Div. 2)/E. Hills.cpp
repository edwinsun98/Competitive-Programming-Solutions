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

const int N = 5003;
ll a[N], dp[N][N][2];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j][0] = dp[i][j][1] = (ll)1e15;
        }
    }
    dp[1][0][0] = 0;
    dp[1][1][1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= (i+1)/2; j++){
            // don't build on ith hill
            if(j == 0){
                dp[i][j][0] = dp[i-1][j][0];
                continue;
            }
            dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]+max(0LL, a[i]-(a[i-1]-1)));

            // build on ith hill
            if(i == 2){
                dp[i][j][1] = max(0LL, a[i-1]-(a[i]-1));
            }else{
                if(j >= 2){
                    dp[i][j][1] = min(dp[i-2][j-1][1]+max(0LL, a[i-1]-(min(a[i-2], a[i])-1)), dp[i-2][j-1][0]+max(0LL, a[i-1]-(a[i]-1)));
                }else{
                    dp[i][j][1] = max(0LL, a[i-1]-(a[i]-1));
                }
            }
        }
    }
    for(int j = 1; j <= (n+1)/2; j++){
        cout << min(dp[n][j][0], dp[n][j][1]) << " ";
    }
    cout << '\n';
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
