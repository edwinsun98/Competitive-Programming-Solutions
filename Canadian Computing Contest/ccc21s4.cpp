#include <bits/stdc++.h>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const int N = 2e5+3;
vector<int> adj[N];
void solve(){
    int n, w, d;
    cin >> n >> w >> d;
    for(int i = 0; i < w; i++){
        int a, b;
        cin >> a >> b;
        adj[b].pb(a);
    }
    queue<int> q;
    vector<ll> dis(n+1, (ll)1e15);
    dis[n] = 0;
    q.push(n);
    while(!q.empty()){
        int c = q.front(); q.pop();
        for(auto& i : adj[c]){
            if(dis[c]+1 < dis[i]){
                dis[i] = dis[c]+1;
                q.push(i);
            }
        }
    }
    vector<int> order(n+1);
    vector<int> ith(n+1);
    multiset<ll> e;
    for(int i = 1; i <= n; i++){
        cin >> order[i];
        ith[i] = order[i];
        e.insert(i-1+dis[order[i]]);
    }
    for(int i = 1; i <= d; i++){
        int x, y;
        cin >> x >> y;
        e.erase(e.lb(dis[order[x]]+x-1));
        e.erase(e.lb(dis[order[y]]+y-1));
        swap(order[x], order[y]);
        e.insert(dis[order[x]]+x-1);
        e.insert(dis[order[y]]+y-1);
        cout << *(e.begin()) << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
