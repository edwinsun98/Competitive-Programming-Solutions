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


int n, k;
vector<vector<ll>> dp;
vector<ll> a;

void solve(){
    cin >> n >> k;
    ll sum = 0;
    dp.assign(n+1, vector<ll>(k+1));
    a.assign(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll rec = 0;
    for(int i = 1; i <= n; i++){
        rec = max(rec, a[i]);
        dp[i][0] = rec*i;
    }
    for(int i = 1; i <= k; i++)dp[0][i] = 0;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            ll mv = a[i];
            dp[i][j] = (ll)1e12;
            for(int p = i-1; p >= 0; p--){
                dp[i][j] = min(dp[i][j], dp[p][j-1]+(i-p)*mv);
                mv = max(mv, a[p]);
            }
        }
    }
    cout << dp[n][k]-sum << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("snakes.in", "r", stdin);
//    freopen("snakes.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
