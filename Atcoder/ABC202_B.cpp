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
    string s;
    cin >> s;
    reverse(all(s));
    for(char& c : s){
        if(c == '6')c = '9';
        else if(c == '9')c = '6';
    }
    cout << s << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
