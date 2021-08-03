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


const int N = 1e5+60;
vector<pair<int,ll>> adj[N];
vector<bool> vis(N);
vector<ll> earliest(N), ret(N), in(N);
int n, c;
ll m;
void solve(){
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++){
        cin >> earliest[i];
    }
    for(int i = 0; i < c; i++){
        int a, b; ll x;
        cin >> a >> b >> x;
        adj[a].pb(make_pair(b, x));
        in[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)if(!in[i])q.push(i);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto& j : adj[cur]){
            earliest[j.f] = max(earliest[j.f], earliest[cur]+j.s);
            in[j.f]--;
            if(!in[j.f])q.push(j.f);
        }
    }
    for(int i = 1; i <= n; i++)cout << earliest[i] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("timeline.in", "r", stdin);
//    freopen("timeline.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
