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
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> blocked(n);
    for(int i = 0; i < m; i++){
        int s;
        cin >> s;
        blocked[s] = 1;
    }
    vector<ll> a(k);
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    vector<int> lst(n);
    for(int i = 0; i < n; i++){
        if(blocked[i]){
            if(i == 0){
                lst[i] = -1;
            }else{
                lst[i] = lst[i-1];
            }
        }else{
            lst[i] = i;
        }
    }
    ll ans = 1e18;
    for(int l = 1; l <= k; l++){
        ll cnt = 0;
        int cur = 0;
        bool ok = 1;
        if(blocked[0]){
            ok = 0;
        }else{
            while(1){
                cnt++;
                int to = cur+l;
                if(to > n-1)break;
                if(lst[to]+l == to){
                    ok = 0;
                    break;
                }
                cur = lst[to];
            }
        }
        if(ok){
            ans = min(ans, cnt*a[l-1]);
        }
    }
    cout << (ans == 1e18 ? -1 : ans) << '\n';
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
