#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    int k = n;
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    for(int i = 0; i <= n; i++)fill(all(dp[i]), n);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            for(int p = 1; p <= i; p++){
                int dif = 0, ptr = 0;
                for(int q = p; q <= i; q++){
                    if(ptr != a[q])dif++;
                    ptr++;
                }
                dp[i][j] = min(dp[i][j], dp[p-1][j-1]+dif);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << dp[n][i] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
