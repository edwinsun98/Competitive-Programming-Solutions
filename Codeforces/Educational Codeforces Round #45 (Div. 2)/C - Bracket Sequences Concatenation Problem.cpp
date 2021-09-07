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

int get_net(string s){
    int r = 0;
    for(char& c : s){
        if(c == '(')r++;
        else r--;
    }
    return r;
}
int get_low(string s){
    int r = 1e9, x = 0;
    for(char& c : s){
        if(c == '(')x++;
        else x--;
        r = min(r, x);
    }
    return r;
}
void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    map<int,int> open;
    vector<pair<int,int>> close;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int low = get_low(s), net = get_net(s);
        if(net == 0){
            if(low >= 0){
                ans++;
            }
        }else{
            if(net > 0){
                if(low >= 0){
                    open[net]++;
                }
            }else{
                close.pb(mk(net, low));
            }
        }
    }
    ans *= ans;
    for(int i = 0; i < close.size(); i++){
        int low = close[i].s, net = close[i].f;
        if(low < net)continue;
        ans += open[-net];
    }
    cout << ans << '\n';
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
