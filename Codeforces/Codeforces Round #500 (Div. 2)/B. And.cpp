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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<int,int> mp1, mp2;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp1[a[i]]++;
    }
    for(auto& i : mp1){
        if(i.s >= 2){
            cout << 0 << '\n';
            return;
        }
    }
    for(int i = 0; i < n; i++){
        int t = (a[i]&x);
        mp2[t]++;
        mp1[a[i]]--;
        if(mp1[t] > 0){
            cout << 1 << '\n';
            return;
        }
        mp1[a[i]]++;
    }
    for(auto& i : mp2){
        if(i.s >= 2){
            cout << 2 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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
