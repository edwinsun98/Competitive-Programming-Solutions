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
 
 
template<typename T> struct seg{
    struct node{
        int l, r, id;
        T sum;
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
        if(seg[2*rt].sum > seg[2*rt+1].sum){
            seg[rt].id = seg[2*rt].id;
            seg[rt].sum = seg[2*rt].sum;
        }else{
            seg[rt].id = seg[2*rt+1].id;
            seg[rt].sum = seg[2*rt+1].sum;
        }
    }
    void build(int l, int r, int rt){
        seg[rt].l = l; seg[rt].r = r;
        if(l == r) {
            seg[rt].id = l;
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
    pair<int,int> query(int l, int r, int rt){
        if(seg[rt].l == l && seg[rt].r == r) return mk(seg[rt].id, seg[rt].sum);
        int mid = (seg[rt].l + seg[rt].r)/2;
        if(r <= mid) return query(l, r, 2*rt);
        if(l > mid) return query(l, r, 2*rt+1);
        // TODO: operation change
        pair<int,int> ls = query(l, mid, 2*rt), rs = query(mid+1, r, 2*rt+1);
        if(ls.s > rs.s){
            return mk(seg[2*rt].id, seg[2*rt].sum);
        }else return mk(seg[2*rt+1].id, seg[2*rt].sum);
    }
};
 
seg<int> ds;
const int N = 1003;
deque<int> adj[N];
vector<int> ke(N*N+3);
vector<pair<int,int>> ke2(N*N+3);
void solve(){
    int n, ptr = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            ke[i*N+j] = ++ptr;
            ke2[ptr] = mk(i, j);
        }
    }
    ds.init(ptr);
    ds.build(1, ptr, 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-1; j++){
            int x; cin >> x;
            adj[i].pb(x);
            if(j == 1){
                int a  = min(i, x), b = max(i, x);
                ds.update(ke[a*N+b], 1, 1);
            }
        }
    }
    int cnt = 0, turns = 0, pre = 0;
    for(;;){
        if(cnt == (n*(n-1))/2)break;
        turns++;
        if(turns > (n*n-1)/2)break;
        unordered_set<int> st;
        vector<int> toUpdate;
        while(1){
            pair<int,int> ret = ds.query(1, ptr, 1);
            if(ret.s < 2)break;
            int id = ret.f;
            pair<int,int> p = ke2[id];
            if(adj[p.f][0] == p.s && adj[p.s][0] == p.f && !st.count(p.f) && !st.count(p.s)){
                adj[p.f].pop_front();
                adj[p.s].pop_front();
                if(adj[p.f].size())ds.update(ke[(min(p.f, adj[p.f][0])*N+max(p.f, adj[p.f][0]))], 1, 1);
                if(adj[p.s].size())ds.update(ke[(min(p.s, adj[p.s][0])*N+max(p.s, adj[p.s][0]))], 1, 1);
                ds.update(id, -2, 1);
                st.insert(p.f);
                st.insert(p.s);
                cnt++;
            }else{
                ds.update(id, -1, 1);
                toUpdate.pb(id);
            }
        }
        for(auto& i : toUpdate)ds.update(i, 1, 1);
        if(cnt == pre){
            turns = n*n;
            break;
        }else{
            pre = cnt;
        }
    }
    cout << (turns > (n*(n-1)/2) ? -1 : turns) << '\n';
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
