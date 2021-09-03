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

void solve(){
    int r = 2, c;
    cin >> c;
    vector<vector<int>> a(r+1, vector<int>(c+1)), p(r+1, vector<int>(c+1));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
            p[i][j] = a[i][j];
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            p[i][j] += p[i][j-1];
        }
    }
    int top = 0, bot = 0;
    int ans = 2e9;
    for(int j = 1; j <= c; j++){
        top += a[1][j];
        ans = min(ans, max(bot, p[1][c]-p[1][j]));
        bot += a[2][j];
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
}
