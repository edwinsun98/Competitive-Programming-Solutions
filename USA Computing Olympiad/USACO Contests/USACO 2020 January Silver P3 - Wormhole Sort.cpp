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


const int N = 1e5+6;
struct ed{
    int a, b, w;
};
vector<int> adj[N];
bool vis[N];
int p[N];
int n, m;
vector<ed> edges;
void dfs(int cur){
    vis[cur] = 1;
    for(auto& i : adj[cur]){
        if(!vis[i]){dfs(i);}
    }
}
bool check(int x){
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        vis[i] = 0;
    }
    for(ed& i : edges){
        if(i.w < x)continue;
        adj[i.a].pb(i.b);
        adj[i.b].pb(i.a);
    }
    for(int i = 1; i <= n; i++){
        if(p[i] != i){
            dfs(i);
            for(int j = 1; j <= n; j++){
                if(p[j] != j){
                    if(!vis[p[j]]){
                        return 0;
                    }
                }
            }
            return 1;
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> p[i];
    bool ok = 1;
    for(int i = 1; i <= n; i++){
        if(p[i] != i)ok = 0;
    }
    if(ok){
        cout << -1 << '\n';
        return;
    }
    edges.assign(m, ed{0,0,0});
    for(int i = 0; i < m; i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    int l = 1, r = 1e9, m, ans = 1;
    while(l <= r){
        m = (l+r)/2;
        if(check(m)){
            l = m+1;
            ans = max(ans, m);
        }
        else r = m-1;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
