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


const int N = 1e3+3;
vector<int> adj[N];
set<pair<ll,int>> st;
int n, m;
ll c, score[N];
ll dp[N][N];
vpii events;
void solve(){
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++)cin >> score[i];
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        events.pb({a, b});
    }
    memset(dp, -1, sizeof(dp));
    dp[0][1] = 0; ll ret = 0;
    for(int j = 1; j < N; j++){
        for(auto& i : events){
            if(dp[j-1][i.f] != -1){
                dp[j][i.s] = max(dp[j][i.s], dp[j-1][i.f]+score[i.s]);
            }
        }
        ret = max(ret, dp[j][1]-c*j*j);
    }
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
