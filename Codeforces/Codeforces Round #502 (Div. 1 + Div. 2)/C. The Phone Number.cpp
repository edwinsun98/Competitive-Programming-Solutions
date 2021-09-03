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
    int n;
    cin >> n;
    int len = 0, minv = 1e9;
    for(int x = 1; x <= n; x++){
        if(x+(n+x-1)/x < minv){
            minv = x+(n+x-1)/x;
            len = x;
        }
    }
    vector<vector<int>> adj((n+len-1)/len);
    int cur = 1, cnt = 0;
    for(int i = 0; i < (n+len-1)/len; i++){
        for(int j = cur; j <= cur+len-1; j++){
            if(cnt+1 > n)break;
            cnt++;
            adj[i].pb(j);
        }
        cur = cur+len;
    }
    for(int i = (n+len-1)/len-1; i >= 0; i--){
        for(auto& j : adj[i]){
            cout << j << " ";
        }
    }
    cout << '\n';
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
