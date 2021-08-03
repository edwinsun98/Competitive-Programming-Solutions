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


const int N = 1e5+3;
vector<int> adj[N];
vector<int> tin(N), tout(N);
vector<ll> enjoy(N);
vector<ll> bit(2*N);
vector<ll> arr(2*N);
void update(int id, int val){
    for(int i = id; i < 2*N; i += i&-i)
        bit[i] ^= val;
}
ll query(int id){
    ll sum = 0;
    for(int i = id; i > 0; i -= i&-i)
        sum ^= bit[i];
    return sum;
}
int tim;
struct lca{
    vector<int> h; 
    vector<vector<int>> dp;
    void dfs(int cur, int par){
        h[cur] = h[par]+1;
        dp[cur][0] = par;
        for(int i = 1; i < 20; i++){
            dp[cur][i] = dp[dp[cur][i-1]][i-1];
        }
        for(auto& i : adj[cur+1]){
            int to = i-1;
            if(to^par)dfs(to, cur);
        }
    }
    void init(int n){
        h.assign(n+1, 0);
        dp.assign(n+1, vector<int>(20));
        dfs(0, 0);
    }
    int anc(int a, int b){
        a--; b--; // 0 indexing
        if(h[a] < h[b])swap(a, b);
        int dif = h[a]-h[b];
        for(int i = 0; i < 20; i++){
            if(dif&(1<<i))a = dp[a][i];
        }
        if(a == b)return a+1;
        for(int i = 19; i >= 0; i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i]; b = dp[b][i];
            }
        }
        return dp[a][0]+1;
    }
};
void dfs(int cur, int par){
    tin[cur] = ++tim;
    for(auto& i : adj[cur]){
        if(i^par){
            dfs(i, cur);
        }
    }
    tout[cur] = ++tim;
}

lca datas;
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> enjoy[i];
    }
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, -1);
    datas.init(n);
    for(int i = 1; i <= n; i++){
        update(tin[i], enjoy[i]);
        update(tout[i], enjoy[i]);
        arr[tin[i]] = enjoy[i];
        arr[tout[i]] = enjoy[i];
    }
    for(int tc = 0; tc < q; tc++){
        int c, i, j; ll v;
        cin >> c;
        if(c == 1){
            cin >> i >> v;
            // reset
            update(tin[i], arr[tin[i]]);
            update(tout[i], arr[tin[i]]);

            update(tin[i], v);
            update(tout[i], v);
            arr[tin[i]] = v;
            arr[tout[i]] = v;
        }
        else{
            cin >> i >> j;
            int ancestor = datas.anc(i, j);
            ll ret = query(tin[i])^query(tin[j])^query(tin[ancestor])^query(tin[ancestor]-1);
            cout << ret << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
