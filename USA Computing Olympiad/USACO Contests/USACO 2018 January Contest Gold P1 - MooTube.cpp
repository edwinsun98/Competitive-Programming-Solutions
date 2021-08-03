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
vector<int> parent(N), sz(N);
int find_set(int v){
    if (v == parent[v])return v;
    return find_set(parent[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a == b)return;
    if(sz[a] < sz[b]){
        sz[b] += sz[a];
        parent[a] = b;
    }
    else{
        sz[a] += sz[b];
        parent[b] = a;
    }
}
int n, q;
struct ed{
    int a, b, w;
};
bool operator<(const ed& a, const ed& b){
    return a.w < b.w;
}
struct event{
    int k, v, i;
};
bool operator<(const event& a, const event& b){
    return a.k < b.k;
}
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    deque<ed> edges(n);
    for(int i = 0; i < n-1; i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    vector<int> ans(q);
    vector<event> events(q);
    for(int i = 0; i < q; i++){
        int k, v;
        cin >> k >> v;
        events[i] = event{k, v, i};
    }
    sort(all(events));
    reverse(all(events));
    sort(all(edges));
    reverse(all(edges));
    for(auto& e : events){
        while(!edges.empty() && edges.front().w >= e.k){
            ed seg = edges.front();
            union_set(seg.a, seg.b);
            edges.pop_front();
        }
        int p = find_set(e.v);
        ans[e.i] = sz[p];
    }
    for(int i = 0; i < q; i++)cout << ans[i]-1 << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("mootube.in", "r", stdin);
//    freopen("mootube.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
