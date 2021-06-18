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
    ll a, b, k;
    cin >> a >> b >> k;
    ll sz = a+b;
    vector<vector<ll>> c(sz+1, vector<ll>(sz+1));
    for(ll n = 1; n <= sz; n++){
        c[n][0] = c[n][n] = 1;
        for(ll j = 1; j < n; j++){
            c[n][j] = c[n-1][j-1]+c[n-1][j];
        }
    }
    ll as = a, bs = b, rem = k;
    string ans = "";
    for(ll i = 1; i <= sz; i++){
        if(as > 0 && bs > 0){
            if(c[sz-i][bs] >= rem){
                ans += 'a';
                as--;
            }else{
                rem -= c[sz-i][bs];
                ans += 'b';
                bs--;
            }
        }else if(as > 0){
            rem -= c[sz-i][bs];
            ans += 'a';
            as--;
        }else{ // bs > 0
            rem -= c[sz-i][as];
            ans += 'b';
            bs--;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
