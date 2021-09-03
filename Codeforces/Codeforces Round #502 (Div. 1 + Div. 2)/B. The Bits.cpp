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
    string a, b;
    cin >> n >> a >> b;
    ll zero = 0, one = 0, cnt = 0, tzero = 0, tone = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '1')tone++;
        else tzero++;
    }
    for(int i = 0; i < n; i++){
        if(b[i] == '1')continue;
        if(a[i] == '1'){
            cnt += tzero-zero;
            one++;
        }else{
            cnt += tone-one;
            zero++;
        }
    }
    cout << cnt << '\n';
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
