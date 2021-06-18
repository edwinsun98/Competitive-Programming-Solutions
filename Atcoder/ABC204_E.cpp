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
 
 
const int N = 1e5+3;
struct ed{
    int i; ll c, d, x;
};
vector<ed> adj[N];
int n, m;
ll check(ll t){
    vector<ll> dis(n+1, 1e18);
    dis[1] = t;
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push(mk(dis[1], 1));
    while(!q.empty()){
        int v = q.top().s;
        if(dis[v] != q.top().f){q.pop(); continue;}
        q.pop();
        for(auto& e : adj[v]){
            ll x = e.x;
            if(dis[v] >= x)x = 0;
            else x = x-dis[v];
            if(dis[v]+e.c+e.d/(dis[v]+x+1)+x < dis[e.i]){
                dis[e.i] = dis[v]+e.c+e.d/(dis[v]+x+1)+x;
                q.push(mk(dis[e.i], e.i));
            }
        }
    }
    return dis[n];
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; ll c, d;
        cin >> a >> b >> c >> d;
        ll l = 0, r = d, mid;
        while(l < r){
            mid = (l+r)/2;
            double x = (double)d/(mid+1)+mid;
            double y = (double)d/(mid+2)+mid+1;
            if(x < y){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        adj[a].pb(ed{b, c, d, l});
        adj[b].pb(ed{a, c, d, l});
    }
    ll ans = check(0);
    cout << (ans == 1e18 ? -1 : ans) << '\n';
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
