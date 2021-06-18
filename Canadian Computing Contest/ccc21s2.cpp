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

template<typename T> struct psa2{
    vector<vector<T>> a;
    int r, c;
    void init(int x, int y){
        r = x, c = y;
        a.assign(x+2, vector<T>(y+2, 0));
    }
    void update(int r1, int c1, int r2, int c2, T v){
        a[r1][c1] += v; a[r1][c2+1] -= v;
        a[r2+1][c1] -= v; a[r2+1][c2+1] += v;
    }
    void build(){ // call build once or twice
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                a[i][j] += a[i][j-1];
        for(int j = 1; j <= c; j++)
            for(int i = 1; i <= r; i++)
                a[i][j] += a[i-1][j];
    }
    T query(int r1, int c1, int r2, int c2){
        return a[r2][c2]-a[r1-1][c2]-a[r2][c1-1]+a[r1-1][c1-1];
    }
};
psa2<int> d;
void solve(){
    int r, c;
    cin >> r >> c;
    d.init(r, c);
    int k;
    cin >> k;
    while(k--){
        char op; int i;
        cin >> op >> i;
        if(op == 'R'){
            d.update(i, 1, i, c, 1);
        }else{
            d.update(1, i, r, i, 1);
        }
    }
    d.build();
    d.build();
    int cnt = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(d.query(i, j, i, j)&1){
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
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
