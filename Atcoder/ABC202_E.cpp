#include <bits/stdc++.h>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
 
const int N = 2e5+3;
vector<int> adj[N], e[N];
vector<int> in(N), out(N);
int ptr, n;
void dfs(int c, int p, int d){
    ptr++;
    e[d].pb(ptr);
    in[c] = ptr;
    for(auto& i : adj[c]){
        if(i^p){
            dfs(i, c, d+1);
        }
    }
    ptr++;
    out[c] = ptr;
}
void solve(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].pb(i);
        adj[i].pb(p);
    }
    dfs(1, 0, 0);
    for(int i = 0; i <= n; i++)sort(all(e[i]));
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        int u, d;
        cin >> u >> d;
        int l = lb(all(e[d]), in[u])-e[d].begin();
        int r = lb(all(e[d]), out[u])-e[d].begin()-1;
//        cout << l << " " << r << '\n';
        cout << max(0, r-l+1) << '\n';
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
