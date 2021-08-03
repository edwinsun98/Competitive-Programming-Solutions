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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[i] = c-'a'+1;
    }
    vector<vector<ll>> dis(m+1, vector<ll>(m+1, 1e12));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cin >> dis[i][j];
        }
    }
    for(int k = 1; k <= m; k++){
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                if(dis[i][j] > dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                }
            }
        }
    }
    vector<vector<ll>> cost(m+1, vector<ll>(n+1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cost[i][j] = dis[a[j]][i]+cost[i][j-1];
        }
    }
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    for(int i = 0; i <= n; i++)fill(all(dp[i]), (ll)1e12);
    for(int i = 1; i <= m; i++)dp[0][i] = 0;
    for(int i = k; i <= n; i++){
        ll mv = (ll)1e12;
        for(int j = 1; j <= m; j++)mv = min(mv, dp[i-k][j]);
        for(int j = 1; j <= m; j++){
            if(i-k < k){
                dp[i][j] = min(dp[i][j], cost[j][i]);
                continue;
            }
            dp[i][j] = min(dp[i][j], mv+cost[j][i]-cost[j][i-k]);
            dp[i][j] = min(dp[i][j], dp[i-1][j]+dis[a[i]][j]);
        }

    }
    ll ret = (ll)1e12;
    for(int j = 1; j <= m; j++)
        ret = min(ret, dp[n][j]);
    cout << ret << '\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
