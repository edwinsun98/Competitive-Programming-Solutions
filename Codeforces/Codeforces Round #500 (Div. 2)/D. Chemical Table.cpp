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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n+m+1);
    vector<bool> vis(n+m+1);
    for(int i = 1; i <= q; i++){
        int r, c;
        cin >> r >> c;
        adj[r].pb(n+c);
        adj[n+c].pb(r);
    }
    function<void(int)> dfs = [&](int c){
        vis[c] = 1;
        for(auto& i : adj[c]){
            if(!vis[i]){
                dfs(i);
            }
        }
    };
    int cnt = 0;
    for(int i = 1; i <= n+m; i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt-1 << '\n';
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
