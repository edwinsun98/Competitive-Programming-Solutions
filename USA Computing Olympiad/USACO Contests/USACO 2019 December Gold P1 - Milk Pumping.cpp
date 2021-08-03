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


struct seg{
    int a, b, c, f;
};
const int N = 1e3+3;
vector<pii> adj[N];
vector<seg> edges;
vector<int> pre(N), dist(N);
vector<vector<int>> matrix(N, vector<int>(N));
int n, m;
int fun(int minflow){
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        pre[i] = 0;
        dist[i] = 1e9;
    }
    for(seg& e : edges){
        if(e.f >= minflow){
            int a = e.a, b = e.b;
            adj[a].pb({b, e.c});
            adj[b].pb({a, e.c});
            matrix[a][b] = e.f;
            matrix[b][a] = e.f;
        }
    }
    queue<int> q;
    q.push(1); dist[1] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto& i : adj[cur]){
            if(dist[cur]+i.s < dist[i.f]){
                dist[i.f] = dist[cur]+i.s;
                pre[i.f] = cur;
                q.push(i.f);
            }
        }
    }
    if(dist[n] == 1e9)return 0;
    int mv = 1e9, dis = 0;
    for(int i = n; i != 1; i = pre[i]){
        mv = min(mv, matrix[i][pre[i]]);
    }
    return 1e6*mv/dist[n];
}
void solve(){
    cin >> n >> m;
    vector<int> flows;
    for(int i = 0; i < m; i++){
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        edges.pb(seg{a, b, c, f});
        flows.pb(f);
    }
    sort(all(flows));
    flows.erase(unique(all(flows)), flows.end());
    int ret = 0;
    for(auto& i : flows){
        ret = max(ret, fun(i));
    }
    cout << ret << '\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("pump.in", "r", stdin);
//    freopen("pump.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
