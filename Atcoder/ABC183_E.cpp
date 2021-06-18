#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
using namespace std;
 
 
const int mod = (int)1e9+7;
 
int h, w;
bool ok(int x, int y){
    return x >= 1 && x <= h && y >= 1 && y <= w;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> h >> w;
    vector<vector<int>> g(h+1, vector<int> (w+1));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            char c;
            cin >> c;
            if(c == '.'){
                g[i][j] = 1;
            }
        }
    }
    vector<vector<ll>> dp(h+1, vector<ll> (w+1)), tp(h+1, vector<ll> (w+1)), lf(h+1, vector<ll> (w+1)),
    dg(h+1, vector<ll> (w+1));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(!g[i][j])continue;
            if(i == 1 && j == 1){
                dp[i][j] = 1;
                tp[i][j] = 1;
                lf[i][j] = 1;
                dg[i][j] = 1;
                continue;
            }
            dp[i][j] = tp[i-1][j]+lf[i][j-1]+dg[i-1][j-1];
            tp[i][j] = tp[i-1][j]+dp[i][j];
            lf[i][j] = lf[i][j-1]+dp[i][j];
            dg[i][j] = dg[i-1][j-1]+dp[i][j];
 
            dp[i][j]%=mod;
            tp[i][j]%=mod;
            lf[i][j]%=mod;
            dg[i][j]%=mod;
        }
    }
    cout << dp[h][w] << '\n';
}
