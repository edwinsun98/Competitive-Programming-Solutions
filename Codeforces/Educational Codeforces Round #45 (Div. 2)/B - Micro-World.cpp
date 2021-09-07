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
    int n, k;
    cin >> n >> k;
    multiset<int> st;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    sort(all(a));
    for(int i = 0; i < n; i++){
        auto it = st.lb(a[i]);
        if(it == st.end() || *it != a[i])continue;
        while(1){
            it = st.lb(a[i]-k);
            if(it == st.end())break;
            if(*it >= a[i])break;
            st.erase(it);
        }
    }
    cout << st.size() << '\n';
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
