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
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            int x = i*100+j;
            sum += x;
        }
    }
    cout << sum << '\n';
}
 
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
