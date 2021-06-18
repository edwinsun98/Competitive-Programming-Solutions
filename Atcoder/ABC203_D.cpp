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
psa2<int> psa;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    int l = 0, r = 1e9, m, ans;
    int t = (k*k)/2+1;
    t = k*k-t+1;
    while(l <= r){
        m = (l+r)/2;
        psa.init(n, n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                psa.a[i][j] = (a[i][j] <= m);
            }
        }
        psa.build();
        bool ok = 0;
        for(int i = 1; i+k-1 <= n; i++){
            for(int j = 1; j+k-1 <= n; j++){
                if(psa.query(i, j, i+k-1, j+k-1) >= t){
                    ok = 1;
                }
            }
        }
        if(ok){
            ans = m;
            r = m-1;
        }else l = m+1;
    }
    cout << ans << '\n';
}
 
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
