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
vector<int> type[N];
vector<int> tin(N), tout(N);
vector<int> bit(2*N);
int tim;

void update(int id, int val){
    for(int i = id; i < 2*N; i += i&-i)
        bit[i]+=val;
}
int query(int id){
    int sum = 0;
    for(int i = id; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}
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
struct event{
    int a, b, id;
};
vector<event> events[N];
void dfs(int cur, int par){
    tim++;
    tin[cur] = tim;
    for(auto& i : adj[cur]){
        if(i^par){
            dfs(i, cur);
        }
    }
    tout[cur] = ++tim;
}

lca datas;
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        type[x].pb(i);
    }
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> ans(m);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        events[c].pb(event{a, b, i});
    }
    datas.init(n);
    dfs(1, -1);
    for(int c = 1; c <= n; c++){
        if(events[c].empty())continue;
        for(int& i : type[c]){
            update(tin[i], 1);
            update(tout[i], -1);
        }
        for(event& e : events[c]){
            int a = e.a, b = e.b;
            int ancestor = datas.anc(a, b);
            int favs = query(tin[a])+query(tin[b])-query(tin[ancestor])-query(tin[ancestor]-1);
            if(favs)ans[e.id] = 1;
        }
        // reset
        for(int& i : type[c]){
            update(tin[i], -1);
            update(tout[i], 1);
        }
    }
    for(int i = 0; i < m; i++)
        cout << ans[i];
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("milkvisits.in", "r", stdin);
//    freopen("milkvisits.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
