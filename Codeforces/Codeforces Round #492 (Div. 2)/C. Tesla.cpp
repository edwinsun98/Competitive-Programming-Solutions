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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(5, vector<int>(n+1));
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if(k == 2*n){
        bool ok = 0;
        for(int j = 1; j <= n; j++){
            if(a[1][j] == a[2][j])ok = 1;
        }
        for(int j = 1; j <= n; j++){
            if(a[4][j] == a[3][j])ok = 1;
        }
        if(!ok){
            cout << -1 << '\n';
            return;
        }
    }
    vector<int> ansi, ansr, ansc;
    int cnt = 0;
    while(1){
        for(int j = 1; j <= n; j++){
            if(a[2][j] == 0)continue;
            if(a[1][j] == a[2][j]){
                ansi.pb(a[2][j]);
                ansr.pb(1);
                ansc.pb(j);
                a[2][j] = 0;
                cnt++;
            }
        }
        for(int j = 1; j <= n; j++){
            if(a[3][j] == 0)continue;
            if(a[4][j] == a[3][j]){
                ansi.pb(a[3][j]);
                ansr.pb(4);
                ansc.pb(j);
                a[3][j] = 0;
                cnt++;
            }
        }
        if(cnt == k)break;
        vector<vector<bool>> vis(5, vector<bool>(n+1));
        for(int j = 1; j <= n; j++){
            if(a[2][j] == 0 || vis[2][j])continue;
            if(j < n){
                if(a[2][j+1] == 0){
                    ansi.pb(a[2][j]);
                    ansr.pb(2);
                    ansc.pb(j+1);
                    swap(a[2][j], a[2][j+1]);
                    vis[2][j+1] = 1;
                }
            }else{
                if(a[3][j] == 0){
                    ansi.pb(a[2][j]);
                    ansr.pb(3);
                    ansc.pb(j);
                    swap(a[2][j], a[3][j]);
                    vis[3][j] = 1;
                }
            }
        }
        for(int j = n; j >= 1; j--){
            if(a[3][j] == 0 || vis[3][j])continue;
            if(j > 1){
                if(a[3][j-1] == 0){
                    ansi.pb(a[3][j]);
                    ansr.pb(3);
                    ansc.pb(j-1);
                    swap(a[3][j], a[3][j-1]);
                    vis[3][j-1] = 1;
                }
            }else{
                if(a[2][j] == 0){
                    ansi.pb(a[3][j]);
                    ansr.pb(2);
                    ansc.pb(j);
                    swap(a[3][j], a[2][j]);
                    vis[2][j] = 1;
                }
            }
        }
    }
    cout << ansi.size() << '\n';
    for(int i = 0; i < ansi.size(); i++){
        cout << ansi[i] << " " << ansr[i] << " " << ansc[i] << '\n';
    }
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
