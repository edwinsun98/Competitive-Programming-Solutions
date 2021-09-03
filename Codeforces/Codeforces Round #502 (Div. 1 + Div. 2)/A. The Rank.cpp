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

bool cmp(const pii& a, const pii& b){
    if(a.f == b.f)return a.s < b.s;
    else return a.f > b.f;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s = a+b+c+d;
        v.pb(mk(s, i));
    }
    sort(all(v), cmp);
    for(int i = 0; i < n; i++){
        if(v[i].s == 0){
            cout << i+1 << '\n';
            return;
        }
    }
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
