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
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int x = a-c, y = b-c;
    int z = n-x-y-c;
    if(x >= 0 && y >= 0 && z >= 1){
        cout << z << '\n';
    }else cout << -1 << '\n';
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
