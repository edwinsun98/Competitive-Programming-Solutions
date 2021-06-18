#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
#define ll long long
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
    ll n;
    cin >> n;
    vector<ll> ans;
    for(ll i = 1; i*i <= n; i++){
        if(n%i)continue;
        ans.pb(i);
        ans.pb((ll)n/i);
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    for(auto& i : ans)cout << i << '\n';
    return 0;
}
