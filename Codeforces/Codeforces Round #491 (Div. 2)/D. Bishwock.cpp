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
    vector<string> a(3);
    cin >> a[1] >> a[2];
    int n = a[1].size();
    int c = 0;
    for(int i = 0; i+1 < n; i++){
        if(a[1][i] == '0' && a[1][i+1] == '0' && a[2][i] == '0'){
            a[1][i] = 'X', a[1][i+1] = 'X', a[2][i] = 'X';
            c++;
        }else if(a[1][i] == '0' && a[1][i+1] == '0' && a[2][i+1] == '0'){
            a[1][i] = 'X', a[1][i+1] = 'X', a[2][i+1] = 'X';
            c++;
        }else if(a[1][i+1] == '0' && a[2][i] == '0' && a[2][i+1] == '0'){
            a[1][i+1] = 'X', a[2][i] = 'X', a[2][i+1] = 'X';
            c++;
        }else if(a[1][i] == '0' && a[2][i] == '0' && a[2][i+1] == '0'){
            a[1][i] = 'X', a[2][i] = 'X', a[2][i+1] = 'X';
            c++;
        }
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
