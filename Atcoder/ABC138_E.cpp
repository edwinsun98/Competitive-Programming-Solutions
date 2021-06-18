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
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> nxt(26, vector<int>(n+1));
    for(int i = 0; i < 26; i++){
        int x = -1;
        for(int j = n-1; j >= 0; j--){
            if(s[j] == char('a'+i)){
                x = j;
            }
            nxt[i][j] = x;
        }
    }
    int f = 0, c = 0;
    for(int i = 0; i < m; i++){
        if(nxt[t[i]-'a'][c] == -1){
            f++;
            c = 0;
            if(nxt[t[i]-'a'][c] == -1){
                cout << -1 << '\n';
                return;
            }else{
                c = nxt[t[i]-'a'][c]+1;
                if(i == m-1){
                    break;
                }
                if(c >= n){
                    c = 0;
                    f++;
                }
            }
        }else{
            c = nxt[t[i]-'a'][c]+1;
            if(i == m-1)break;
            if(c >= n){
                c = 0;
                f++;
            }
        }
    }
    cout << (1LL*f*n+c) << '\n';
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
