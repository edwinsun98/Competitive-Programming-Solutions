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
    int c = 0;
    int s = 4*n+(n+1)/2, x = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x += a[i];
    }
    sort(all(a));
    for(int i = 0; i < n; i++){
        if(x >= s)break;
        c++;
        x += 5-a[i];
    }
    cout << c << '\n';
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
