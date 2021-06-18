#include <bits/stdc++.h>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

vector<int> a;
int ptr;
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
        seg[rt].sum = __gcd(seg[2*rt].sum , seg[2*rt+1].sum);
    }
    void build(int l, int r, int rt){
        seg[rt].l = l; seg[rt].r = r;
        if(l == r) {
            seg[rt].sum = a[++ptr];
            return;
        }
        int mid = (l + r)/2;
        build(l, mid, 2*rt); build(mid+1, r, 2*rt+1); pushup(rt);
    }
    void update(int id, T val, int rt){
        if(seg[rt].l == seg[rt].r){
            seg[rt].sum = val;
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
        return __gcd(query(l, mid, 2*rt) , query(mid+1, r, 2*rt+1));
    }
};

int n, m;
seg<int> tree;
void solve(){
    cin >> n >> m;
    vector<vector<int>> p(17, vector<int>(n+2));
    vector<int> x(m+1), y(m+1), z(m+1); a.assign(n+1, 0);
    fill(all(a), 1);
    tree.init(n);
    for(int i = 1; i <= m; i++){
        cin >> x[i] >> y[i] >> z[i];
        p[z[i]][x[i]]++;
        p[z[i]][y[i]+1]--;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 16; j++){
            p[j][i] += p[j][i-1];
            if(p[j][i] > 0){
                a[i] = (a[i]*j)/__gcd(a[i], j);
            }
        }
    }
    tree.build(1, n, 1);
    for(int i = 1; i <= m; i++){
        if(tree.query(x[i], y[i], 1) != z[i]){
            cout << "Impossible" << '\n';
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << '\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
