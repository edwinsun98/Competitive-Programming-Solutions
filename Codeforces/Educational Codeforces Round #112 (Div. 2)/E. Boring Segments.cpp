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
typedef pair<double, int> pdi;

template<typename T> struct seg2{
    struct node{
        int l, r;
        T sum, lz;
    };
    vector<node> seg;
    int n;
    void init(int sz){
        n = sz;
        int accurate = (1<<((int)log2(n)+2))-1;
        seg.assign(accurate, (node){0, 0, 0, 0});
    }
    // TODO: operation change
    void pushup(int rt){
        seg[rt].sum = min(seg[2*rt].sum, seg[2*rt+1].sum);
    }
    // TODO: operation change
    void pushdown(int rt){
        int lson = 2*rt, rson = 2*rt+1;
        seg[lson].lz = seg[rt].lz; seg[rson].lz = seg[rt].lz;
        seg[lson].sum = seg[rt].lz;
        seg[rson].sum = seg[rt].lz;
        seg[rt].lz = 0;
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
    void update(int l, int r, T val, int rt){
        if(seg[rt].l==l && seg[rt].r==r){
            seg[rt].lz = val; seg[rt].sum = val;
            return;
        }
        if(seg[rt].lz) pushdown(rt);
        int mid = (seg[rt].l + seg[rt].r)/2;
        if(r <= mid) update(l, r, val, 2*rt);
        else if(l > mid) update(l, r, val, 2*rt+1);
        else {
            update(l, mid, val, 2*rt);
            update(mid+1, r, val, 2*rt+1);
        }
        pushup(rt);
    }
    T query(int l, int r, int rt){
        if(seg[rt].l == l && seg[rt].r == r) return seg[rt].sum;
        if(seg[rt].lz) pushdown(rt);
        int mid = (seg[rt].l + seg[rt].r)/2;
        if(r <= mid) return query(l, r, 2*rt);
        if(l > mid) return query(l, r, 2*rt+1);
        // TODO: operation change
        return min(query(l, mid, 2*rt), query(mid+1, r, 2*rt+1));
    }
};
seg2<ll> ds;
struct e{
    int l, r; ll v;
};
bool cmp(const e& a, const e& b){
    return a.v < b.v;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<e> a(n);
    for(int i = 0; i < n; i++){cin >> a[i].l >> a[i].r >> a[i].v; a[i].l++;}
    sort(all(a), cmp);
    ds.init(m);
    ds.build(1, m, 1);
    for(int i = 1; i <= m; i++)ds.update(i, i, -2e9, 1);
    ll ans = 2e9;
    for(auto& i : a){
        int l = i.l, r = i.r; ll v = i.v;
        ds.update(l, r, v, 1);
        ans = min(ans, v-ds.query(2, m, 1));
    }
    cout << ans << '\n';
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
