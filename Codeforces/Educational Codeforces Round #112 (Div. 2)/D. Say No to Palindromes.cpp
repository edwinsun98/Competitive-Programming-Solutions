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
typedef pair<double, int> pdi;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<char> s(n+1);
    for(int i = 1; i <= n; i++)cin >> s[i];
    vector<vector<char>> a(6, vector<char>(max(3+1, n+1)));
    vector<vector<int>> p(6, vector<int>(max(3+1, n+1)));
    vector<string> str = {"abc", "acb", "bca", "bac", "cab", "cba"};
    for(int i = 0; i < 6; i++){
        for(int ptr = 1; ptr <= max(3, n); ptr++){
            if(ptr <= 3)a[i][ptr] = str[i][ptr-1];
            else{
                set<char> st; st.insert(a[i][ptr-1]); st.insert(a[i][ptr-2]);
                if(!st.count('a'))a[i][ptr] = 'a';
                else if(!st.count('b'))a[i][ptr] = 'b';
                else a[i][ptr] = 'c';
            }
        }
        for(int j = 1; j <= n; j++){
            if(a[i][j] != s[j])p[i][j]++;
            p[i][j] += p[i][j-1];
        }
    }
    for(int t = 1; t <= m; t++){
        int l, r;
        cin >> l >> r;
        int ans = 1e9;
        for(int i = 0; i < 6; i++){
            ans = min(ans, p[i][r]-p[i][l-1]);
        }
        cout << ans << '\n';
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
