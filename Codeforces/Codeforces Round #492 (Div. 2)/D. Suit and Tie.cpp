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
    int n, cnt = 0;
    cin >> n;
    vector<int> a(2*n+1);
    for(int i = 0; i < 2*n; i++)cin >> a[i];
    for(int i = 0; i < 2*n; i++){
        if(a[i-1] != a[i] && a[i] != a[i+1]){
            int pos = 0;
            for(int j = i+1; j < 2*n; j++){
                if(a[j] == a[i]){
                    pos = j;
                    break;
                }
            }
            while(pos > i+1){
                swap(a[pos], a[pos-1]);
                pos--;
                cnt++;
            }
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
