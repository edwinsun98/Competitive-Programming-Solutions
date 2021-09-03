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

const int N = 12, M = 500003;
int get(string s){
    int sum = 0, cur = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            sum += (1<<cur);
        }
        cur++;
    }
    return sum;
}
void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n);
    vector<int> cnt(1<<n);
    vector<vector<int>> dp(1<<n, vector<int>(101));
    for(int i = 0; i < n; i++)cin >> w[i];
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        cnt[get(s)]++;
    }
    for(int mask = 0; mask < (1<<n); mask++){
        vector<pii> v;
        for(int i = 0; i < (1<<n); i++){
            int j = (mask^i), sum = 0;
            for(int k = 0; k < n; k++){
                if(j&(1<<k)){
                    continue;
                }else{
                    sum += w[k];
                }
            }
            v.pb(mk(sum, cnt[i]));
        }
        sort(all(v));
        int ptr = 0, res = 0;
        for(int k = 0; k <= 100; k++){
            while(ptr < v.size() && v[ptr].f <= k){
                res += v[ptr++].s;
            }
            dp[mask][k] = res;
        }
    }
    for(int i = 0; i < q; i++){
        string s; int k;
        cin >> s >> k;
        cout << dp[get(s)][k] << '\n';
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
