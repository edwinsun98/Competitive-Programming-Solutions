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

template<typename T> struct seg{
    struct node{
        int l, r;
        T sum;
    };
    vector<node> seg;
    int n;
    void init(int sz){
        n = sz;
        int accurate = (1<<((int)log2(n)+2))-1;
        seg.assign(accurate, (node){0, 0, 0});
    }
    // TODO: operation change
    void pushup(int rt){
        seg[rt].sum = seg[2*rt].sum + seg[2*rt+1].sum;
    }
    void build(int l, int r, int rt){
        seg[rt].l = l; seg[rt].r = r;
        if(l == r) {
//            cin>>seg[rt].sum;
            return;
        }
        int mid = (l + r)/2;
        build(l, mid, 2*rt); build(mid+1, r, 2*rt+1); pushup(rt);
    }
    void update(int id, T val, int rt){
        if(seg[rt].l == seg[rt].r){
            seg[rt].sum += val;
            return;
        }
        int mid = (seg[rt].l + seg[rt].r)/2;
        if(id <= mid) update(id, val, 2*rt);
        else update(id, val, 2*rt+1);
        pushup(rt);
    }
    T query(int l, int r, int rt){
        if(seg[rt].l == l && seg[rt].r == r) return seg[rt].sum;
        int mid = (seg[rt].l + seg[rt].r)/2;
        if(r <= mid) return query(l, r, 2*rt);
        if(l > mid) return query(l, r, 2*rt+1);
        // TODO: operation change
        return query(l, mid, 2*rt) + query(mid+1, r, 2*rt+1);
    }
};
seg<ll> tree;
const int N = 2e5+3;
vector<int> adj[N];
vector<int> start[N];
int n;
vector<int> a;
ll ans = 0;
void solve(){
    cin >> n;
    tree.init(n);
    tree.build(1, n, 1);
    a.assign(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        adj[a[i]].pb(i);
    }
    for(int i = 1; i <= n; i++){
        if(i == 1){
            int id = lb(all(adj[a[i]]), i)-adj[a[i]].begin();
            if(id+1 < (int)adj[a[i]].size()){
                start[adj[a[i]][id+1]].pb(i);
                tree.update(i, 1, 1);
            }else{
                tree.update(i, 1, 1);
            }
        }else{
            for(auto& j : start[i]){
                tree.update(j, -1, 1);
            }
            int id = lb(all(adj[a[i]]), i)-adj[a[i]].begin();
            if(id-1 >= 0){
                int ls = adj[a[i]][id-1], rs = adj[a[i]][id];
                ans += tree.query(ls+1, rs, 1);
            }else{
                int ls = 1, rs = adj[a[i]][id];
                ans += tree.query(ls, rs, 1);
            }
            if(id+1 < (int)adj[a[i]].size()){
                start[adj[a[i]][id+1]].pb(i);
                tree.update(i, 1, 1);
            }else{
                tree.update(i, 1, 1);
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("tour.in", "r", stdin);
//    freopen("tour.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
