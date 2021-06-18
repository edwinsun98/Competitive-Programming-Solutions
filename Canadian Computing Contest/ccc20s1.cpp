#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


void solve(){
    int n;
    cin >> n;
    vector<pair<double, double>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].f >> a[i].s;
    }
    sort(all(a));
    double ans = 0;
    for(int i = 0; i < n-1; i++){
        ans = max(ans, (abs(a[i+1].s-a[i].s))/(a[i+1].f-a[i].f));
    }
    cout << fixed << setprecision(9) << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
