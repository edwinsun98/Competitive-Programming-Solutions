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
    int n, a, b;
    cin >> n >> a >> b;
    if(n == 2 && a == 1 && b == 1){
        cout << "NO" << '\n';
        return;
    }
    if(n == 3 && a == 1 && b == 1){
        cout << "NO" << '\n';
        return;
    }
    if(a != 1 && b != 1){
        cout << "NO" << '\n';
        return;
    }
    vector<vector<int>> adj(n+1, vector<int>(n+1));
    bool swapped = 0;
    if(a == 1){
        swap(a, b);
        swapped = 1;
    }
    for(int i = a; i < n; i++){
        adj[i][i+1] = adj[i+1][i] = 1;
    }
    if(swapped){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)continue;
                adj[i][j] ^= 1;
            }
        }
    }
    cout << "YES" << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << adj[i][j];
        }
        cout << '\n';
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
