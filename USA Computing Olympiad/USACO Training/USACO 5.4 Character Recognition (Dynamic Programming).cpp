/*
ID: edwinsu1
LANG: C++
TASK: charrec
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


const int N = 540, K = 20;
vector<vector<int>> fonts(N+1, vector<int>(K+1));
vector<vector<int>> grid;
vector<int> dp;
vector<string> dp2;
int n, tn;
pair<int,string> processa(int id, int len = 19){
    int ret = 1e9; string str = "";
    int ptr = 0;
    for(int st = 1; st <= N; st += K){
        int best = 1e9; ++ptr;
        for(int skip = st; skip < st+K; skip++){
            int diff = 0;
            int it = id;
            for(int i = st; i < st+K; i++){
                if(i == skip)continue;
                for(int j = 1; j <= K; j++){
                    diff += fonts[i][j]^grid[it][j];
                }
                it++;
            }
            best = min(best, diff);
        }
        if(best < ret){
            ret = best;
            if(ptr == 1)str = " ";
            else str = char(ptr-2+'a');
        }
    }
    return mk(ret, str);
}
pair<int,string> processb(int id, int len = 20){
    int ret = 1e9; string str = "";
    int ptr = 0;
    for(int st = 1; st <= N; st += K){
        int diff = 0; ++ptr;
        for(int i = st, ii = id; i < st+K; i++, ii++){
            for(int j = 1; j <= K; j++){
                diff += fonts[i][j]^grid[ii][j];
            }
        }
        if(diff < ret){
            ret = diff;
            if(ptr == 1)str = " ";
            else str = char(ptr-2+'a');
        }
    }
    return mk(ret, str);
}
pair<int,string> processc(int id, int len = 21){
    int ret = 1e9; string str = "";
    int ptr = 0;
    for(int st = 1; st <= N; st += K){
        int best = 1e9; ++ptr;
        for(int dup = id; dup < id+len; dup++){
            int diff = 0;
            int it = st;
            for(int i = id; i < id+len; i++){
                if(i == dup)continue;
                for(int j = 1; j <= K; j++){
                    diff += fonts[it][j]^grid[i][j];
                }
                it++;
            }
            best = min(best, diff);
        }
        if(best < ret){
            ret = best;
            if(ptr == 1)str = " ";
            else str = char(ptr-2+'a');
        }
    }
    return mk(ret, str);
}
int go(int id){
    if(id == n+1)return 0;
    if(dp[id] != -1)return dp[id];
    int ans = 1e9; string str = "";
    if(id+19 <= n+1){
        pair<int,string> ret = processa(id, 19);
        if(ret.f+go(id+19) < ans){
            ans = ret.f+go(id+19);
            str = ret.s+dp2[id+19];
        }
    }
    if(id+20 <= n+1){
        pair<int,string> ret = processb(id, 20);
        if(ret.f+go(id+20) < ans){
            ans = ret.f+go(id+20);
            str = ret.s+dp2[id+20];
        }
    }
    if(id+21 <= n+1){
        pair<int,string> ret = processc(id, 21);
        if(ret.f+go(id+21) < ans){
            ans = ret.f+go(id+21);
            str = ret.s+dp2[id+21];
        }
    }
    dp2[id] = str;
    return dp[id] = ans;
}

void solve(){
    freopen("font.in", "r", stdin);
    cin >> tn;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            char c; cin >> c;
            if(c == '1')fonts[i][j] = 1;
        }
    }
    freopen("charrec.in", "r", stdin);
    cin >> n;
    dp.assign(n+2, -1);
    dp2.assign(n+2, "");
    grid.assign(n+50, vector<int>(K+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= K; j++){
            char c; cin >> c;
            if(c == '1')grid[i][j] = 1;
        }
    }
    go(1);
    cout << dp2[1] << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("tour.in", "r", stdin);
    freopen("charrec.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
