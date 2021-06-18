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
 
 
struct e{
    int a, b;
 
};
bool operator<(const e& a, const e& b){
    if(a.b == b.b)return a.a < b.a;
    return a.b > b.b;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<e> a(n);
    set<int> st;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].a >> a[i].b;
    }
    sort(all(a));
    for(int i = 1; i <= m; i++)st.insert(i);
    for(int i = 0; i < n; i++){
        auto it = st.lb(a[i].a);
        if(it != st.end()){
            st.erase(it);
            sum += a[i].b;
        }
    }
    cout << sum << '\n';
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
