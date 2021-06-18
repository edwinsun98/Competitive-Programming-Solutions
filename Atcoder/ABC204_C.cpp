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
 
const int N = 2e3+3;
vector<int> adj[N];
void solve(){
    int n, m;
    cin >>n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        vector<bool>vis(n+1);
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int c = q.front(); q.pop();
            for(auto& i : adj[c]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        for(int j = 1; j <= n; j++){
            if(vis[j]){
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
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
