/*
ID: edwinsu1
LANG: C++
TASK: prime3
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

struct out{
    string key; vector<vector<int>> a;
};
bool operator<(const out& x, const out& y){return x.key < y.key;}
const int M = 100003, N = 5;
vector<vector<bool>> prefix(6, vector<bool>(M));
vector<vector<int>> a(N+1, vector<int>(N+1));
vector<out> ans;
vector<string> adj[M];
int digitsum, starting, ptr;
bool has_ans;
int on_diagonal(int& x, int& y){
    if(x == 3 && y == 3)return 1;
    if(x == y)return 2;
    if((x == 5 && y == 1) || (x == 4 && y == 2) || (x == 2 && y == 4) || (x == 1 && y == 5))return 3;
    return 4; // not on diagonal
}
void check(){
    for(int i = 1; i <= N; i++){
        int row_num = 0;
        for(int j = 1; j <= N; j++)row_num = row_num*10+a[i][j];
        if(!prefix[N][row_num])return;
    }
    for(int j = 1; j <= N; j++){
        int col_num = 0;
        for(int i = 1; i <= N; i++)col_num = col_num*10+a[i][j];
        if(!prefix[N][col_num])return;
    }
    int diag_num = 0;
    for(int i = 1, j = 1; i <= N && j <= N; i++, j++)diag_num = diag_num*10+a[i][j];
    if(!prefix[N][diag_num])return;
    diag_num = 0;
    for(int i = N, j = 1; i >= 1 && j <= N; i--, j++)diag_num = diag_num*10+a[i][j];
    if(!prefix[N][diag_num])return;
    string key = "";
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            key += to_string(a[i][j]);
    has_ans = 1;
    ptr++;
    ans.pb(out{key , a});
}
void go(int x){
    int row_sum = 0, col_sum = 0, row_num = 0, col_num = 0;
    for(int i = 1; i < x; i++)row_sum += a[x][i], row_num = row_num*10+a[x][i];
    for(int i = 1; i < x; i++)col_sum += a[i][x], col_num = col_num*10+a[i][x];
    if(x == 1){
        for(auto& i : adj[a[x][x]]){
            bool ok = 1;
            for(int k = 1; k <= N; k++){
                if(i[k-1] == '0'){
                    ok = 0;
                    break;
                }
            }
            if(!ok)continue;
            for(auto& j : adj[a[x][x]]){
                bool ok2 = 1;
                for(int k = 1; k <= N; k++){
                    if(j[k-1] == '0'){
                        ok2 = 0;
                        break;
                    }
                }
                if(!ok2)continue;
                for(int k = 1; k <= N; k++){
                    a[k][x] = i[k-1]-'0';
                    a[x][k] = j[k-1]-'0';
                }
                go(x+1);
            }
        }
    }else{
        if(x == 3){
            int center = digitsum-(a[5][1]+a[4][2]+a[2][4]+a[1][5]);
            if(center < 0 || center > 9)return;
            int diag_num = 10000*a[5][1]+1000*a[4][2]+100*center+10*a[2][4]+a[1][5];
            if(!prefix[N][diag_num])return;
        }
        for(auto& i : adj[col_num]){
            for(auto& j : adj[row_num]){
                if(i[x-1] == j[x-1]){
                    for(int k = x; k <= N; k++){
                        a[k][x] = i[k-1]-'0';
                        a[x][k] = j[k-1]-'0';
                    }
                    if(x == N){
                        check();
                        return;
                    }
                    go(x+1);
                }
            }
        }
    }
}
void solve(){
    cin >> digitsum >> starting;
    for(int i = 10000; i <= 99999; i++){
        bool is_prime = 1;
        for(int j = 2; j*j <= i; j++){
            if(i%j == 0){
                is_prime = 0;
                break;
            }
        }
        if(is_prime){
            string str = to_string(i);
            int sum = 0;
            for(char&c : str)sum += c-'0';
            if(sum != digitsum)continue;
            for(int j = 1; j <= N; j++){
                string new_str = str.substr(0, j);
                adj[stoi(new_str)].pb(str);
                prefix[j][stoi(new_str)] = 1;
            }
        }
    }
    a[1][1] = starting;
    go(1);
    if(!has_ans)cout << "NONE" << '\n';
    else{
        sort(all(ans));
        for(int i = 0; i < ptr; i++){
            for(int x = 1; x <= N; x++){
                for(int y = 1; y <= N; y++){
                    cout << ans[i].a[x][y];
                }
                cout << '\n';
            }
            if(i != ptr-1)cout << '\n';
        }
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("prime3.in", "r", stdin);
//    freopen("prime3.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
