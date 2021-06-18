#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
#define ll  unsigned long long
#define lld long long double
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
 
 
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("maxcross.in", "r", stdin);
//    freopen("maxcross.out", "w", stdout);
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll cnt = 0;
    while(1){
        if((ll)x*a < x)break;
        if(x*a < x+b && x*a < y){
            cnt++;
            x*=a;
        }else break;
    }
    cnt += (y-x+b-1)/b;
    cnt--;
    cout << cnt << '\n';
    return 0;
}
