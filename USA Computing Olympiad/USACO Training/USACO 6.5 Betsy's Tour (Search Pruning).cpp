/*
ID: edwinsu1
LANG: C++11
TASK: betsy
*/
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

const int N = 10;
int n, sum, ans, goal;
vector<pair<int,int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<bool>> vis(N, vector<bool>(N));
void go(int x, int y){
    if(x == n && y == 1){
        if(sum == goal)ans++;
            return;
    }
    if(vis[x-1][y] && vis[x+1][y] && !vis[x][y-1] && !vis[x][y+1])return;
    if(!vis[x-1][y] && !vis[x+1][y] && vis[x][y-1] && vis[x][y+1])return;
    int mustgo = 0, mustx, musty;
    for(auto& i : dir){
        int x_ = x+i.f, y_ = y+i.s;
        if(!vis[x_][y_] && x_ != n && y_ != 1){
            int free = 0;
            for(auto& j : dir){
                int x__ = x_+j.f, y__ = y_+j.s;
                if(!vis[x__][y__])free++;
            }
            if(free <= 1){
                mustgo++;
                mustx = x_;
                musty = y_;
            }
        }
    }
    if(mustgo > 1)return;
    if(mustgo == 1){
        vis[mustx][musty] = 1;
        sum++;
        go(mustx, musty);
        vis[mustx][musty] = 0;
        sum--;
        return;
    }
    for(auto& i : dir){
        int x_ = x+i.f, y_ = y+i.s;
        if(!vis[x_][y_]){
            vis[x_][y_] = 1;
            sum++;
            go(x_, y_);
            vis[x_][y_] = 0;
            sum--;
        }
    }
}
void solve(){
    cin >> n;
    goal = n*n-1;
    for(int i = 1; i <= n; i++){
        vis[i][0] = 1;
        vis[0][i] = 1;
        vis[i][n+1] = 1;
        vis[n+1][i] = 1;
    }
    vis[1][1] = 1;
    go(1, 1);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("betsy.in", "r", stdin);
//    freopen("betsy.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
