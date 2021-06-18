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
 
 
const int N = 2503;
vector<pair<int,int>> adj[N];
vector<int> radj[N];
void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mk(b, p-c));
        radj[b].pb(a);
    }
    vector<bool> in(n+1), vis(n+1);
    vector<int> dis(n+1, 1e9);
    vector<int> relaxed(n+1, 0);
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    while(!q.empty()){
        int c = q.front(); q.pop();
        for(auto& i : radj[c]){
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }
 
 
    q.push(1);
    in[1] = 1;
    dis[1] = 0;
    while(!q.empty()){
        int c = q.front(); q.pop();
        in[c] = 0;
        for(auto& i : adj[c]){
            if(dis[c]+i.s < dis[i.f]){
                dis[i.f] = dis[c]+i.s;
                if(!in[i.f]){
                    relaxed[i.f]++;
                    if(relaxed[i.f] > n){
                        if(vis[i.f]){
                            cout << -1 << '\n';
                            return;
                        }
                    }else{
                        q.push(i.f);
                        in[i.f] = 1;
                    }
                }
            }
        }
    }
    cout << max(0, -dis[n]) << '\n';
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
