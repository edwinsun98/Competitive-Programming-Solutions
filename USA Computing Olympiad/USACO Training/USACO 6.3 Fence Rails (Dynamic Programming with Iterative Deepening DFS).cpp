/*
ID: edwinsu1
LANG: C++
TASK: fence8
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


int n, r, ans, boardsum, ls, rs, ms, waste;
vector<int> boards;
vector<int> rails;
vector<int> railsum;
bool go(int cur_r, int cur_b){
    if(cur_r == 0)return 1;
    if(waste > boardsum-railsum[ms])return 0;
    for(int i = cur_b; i <= n; i++){
        if(boards[i] >= rails[cur_r]){
            boards[i] -= rails[cur_r];
            if(boards[i] < rails[1])waste += boards[i];
            bool ret = 0;
            if(rails[cur_r] == rails[cur_r-1])ret = go(cur_r-1, i);
            else ret = go(cur_r-1, 1);
            if(boards[i] < rails[1])waste -= boards[i];
            boards[i] += rails[cur_r];
            if(ret)return 1;
        }
    }
    return 0;
}
void solve(){
    cin >> n;
    boards.assign(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> boards[i];
        boardsum += boards[i];
    }
    sort(boards.begin()+1, boards.end());
    cin >> r;
    rails.assign(r+1, 0);
    for(int i = 1; i <= r; i++)cin >> rails[i];
    sort(rails.begin()+1, rails.end());
    railsum.assign(r+1, 0);
    for(int i = 1; i <= r; i++)railsum[i] = railsum[i-1]+rails[i];
    ls = 0, rs = r;
    while(ls <= rs){
        ms = (ls+rs)/2;
        if(go(ms, 1)){
            ans = ms;
            ls = ms+1;
        }else rs = ms-1;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("fence8.in", "r", stdin);
    freopen("fence8.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
