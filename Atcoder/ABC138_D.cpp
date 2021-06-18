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
 
 
const int N = 2e5+3;
vector<int> adj[N];
vector<int> in(N), out(N);
int ptr;
void dfs(int c, int p){
    in[c] = ++ptr;
    for(auto& i : adj[c]){
        if(i != p){
            dfs(i, c);
        }
    }
    out[c] = ++ptr;
}
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);
    vector<ll> v(ptr+2);
    for(int i = 1; i <= q; i++){
        int x, p;
        cin >> p >> x;
        v[in[p]] += x, v[out[p]+1] -= x;
    }
    for(int i = 1; i <= ptr; i++){
        v[i] += v[i-1];
    }
    for(int i = 1; i <= n; i++){
        cout << v[in[i]] << " ";
    }
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
