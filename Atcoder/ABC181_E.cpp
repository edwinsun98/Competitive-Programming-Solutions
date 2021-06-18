#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
#define ll long long
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
 
 
const int N = 2e5+9;
ll pf[N], sf[N], h[N];
int n, m;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("maxcross.in", "r", stdin);
//    freopen("maxcross.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> h[i];
    vector<ll> form(m);
    sort(h+1, h+1+n);
    for(int i = 0; i < m; i++)cin >> form[i];
    sort(all(form));
    for(int i = 2; i < n; i+=2){
        if(i&1)pf[i] = pf[i-1];
        else pf[i] = pf[i-2]+abs(h[i]-h[i-1]);
    }
    for(int i = n-1; i >= 2; i--){
        if(i&1)sf[i] = sf[i+1];
        else sf[i] = sf[i+2]+abs(h[i]-h[i+1]);
    }
    ll ans = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        if(!(i&1))continue;
        int id = lb(all(form), h[i])-form.begin();
        ll k = (id > 0 ? min(abs(h[i]-form[id]), abs(h[i]-form[id-1])) : abs(h[i]-form[id]));
        ans = min(ans, (ll)pf[i-1]+sf[i+1]+k);
    }
    cout << ans << '\n';
    return 0;
}
