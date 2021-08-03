/*
ID: edwinsu1
LANG: C++
TASK: wissqu
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

struct op{
    char c; int i, j;
};
const int N = 4;
vector<vector<bool>> vis(N+1, vector<bool>(N+1));
vector<vector<char>> a(N+1, vector<char>(N+1));
vector<char> co = {'A', 'B', 'C', 'D', 'E'};
vector<int> rem = {3, 3, 3, 4, 3};
vector<pair<int,int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}, {0, 0}};
vector<op> moves;
int ways;
string ans = "z";
vector<op> out;
bool ok(int x, int y, char color){
    for(auto& i : dir){
        int x_ = x+i.f, y_ = y+i.s;
        if(x_ >= 1 && x_ <= N && y_ >= 1 && y_ <= N){
            if(a[x_][y_] == color)return 0;
        }
    }
    return 1;
}
void go(int depth){
    if(depth == 1){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(ok(i, j, co[3])){
                    char pre = a[i][j];
                    a[i][j] = co[3];
                    vis[i][j] = 1;
                    moves.pb(op{co[3], i, j});
                    rem[3]--;
                    go(depth+1);
                    a[i][j] = pre;
                    vis[i][j] = 0;
                    moves.pop_back();
                    rem[3]++;
                }
            }
        }
    }else if(depth > N*N){
        string str = "";
        for(auto& i : moves){
            str += i.c;
            str += to_string(i.i);
            str += to_string(i.j);
        }
        if(str < ans){
            ans = str;
            out = moves;
        }
        ways++;
    }else{
        for(int it = 0; it < 5; it++){
            if(!rem[it])continue;
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    if(vis[i][j])continue;
                    if(ok(i, j, co[it])){
                        char pre = a[i][j];
                        a[i][j] = co[it];
                        vis[i][j] = 1;
                        moves.pb(op{co[it], i, j});
                        rem[it]--;
                        go(depth+1);
                        a[i][j] = pre;
                        vis[i][j] = 0;
                        moves.pop_back();
                        rem[it]++;
                    }
                }
            }
        }
    }
}
void solve(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> a[i][j];
        }
    }
    go(1);
    for(auto& i : out)cout << i.c << " " << i.i << " " << i.j << '\n';
    cout << ways << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("wissqu.in", "r", stdin);
//    freopen("wissqu.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
