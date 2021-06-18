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
    int n; ll k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    for(int i = 0; i < n; i++)cin >> a[i].f >> a[i].s;
    sort(all(a));
    ll c = 0;
    for(int i = 0; i < n; i++){
        ll dist = a[i].f-c;
        if(dist > k){
            cout << c+k << '\n';
            return;
        }
        k -= dist;
        k += a[i].s;
        c = a[i].f;
    }
    cout << c+k << '\n';
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
