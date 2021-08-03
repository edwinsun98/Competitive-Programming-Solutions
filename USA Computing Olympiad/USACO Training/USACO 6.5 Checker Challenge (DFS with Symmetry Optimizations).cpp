/*
ID: edwinsu1
LANG: C++11
TASK: checker
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


const int N = 15;
bool col[N], row[N], diag_left[N+N], diag_right[N+N];
int col_at_row[N];
int n, ans, printed;
void dfs(int r){
    if(r > n){
        ans++;
        if(printed < 3){
            printed++;
            cout << col_at_row[1];
            for(int i = 2; i < r; i++)cout << " " << col_at_row[i];
            cout << '\n';
        }
        return;
    }
    for(int j = 1; j <= n; j++){
        if(!col[j] && !diag_left[j-r+n] && !diag_right[r+j]){
            col[j] = 1;
            diag_left[j-r+n] = 1;
            diag_right[r+j] = 1;
            col_at_row[r] = j;
            dfs(r+1);
            col[j] = 0;
            diag_left[j-r+n] = 0;
            diag_right[r+j] = 0;
        }
    }
}
void solve(){
    cin >> n;
    dfs(1);
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
