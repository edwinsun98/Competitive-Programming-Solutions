#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

vector<ll> dp;
vector<ll> wt;
vector<ll> tl;
int n; ll w;

bool ok(ll rate){
    fill(all(dp), -1e18);
    dp[0] = 0;
    for(ll i = 0; i < n; i++){
        ll v = (ll)1000*tl[i]-rate*wt[i], sz = wt[i];
        for(ll j = w; j >= 0; j--){
            dp[min(w, j+sz)] = max(dp[min(w, j+sz)], dp[j]+v);
        }
    }
    return dp[w] >= 0;
}
void solve(){
    cin >> n >> w;
    dp.assign(w+1, -1e18);
    wt.assign(n, 0);
    tl.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> tl[i];
    }
    ll ls = 0, rs = (ll)2e6*250, mid, ret;
    while(ls <= rs){
        mid = (ls+rs)/2;
        if(ok(mid)){
            ret = mid;
            ls = mid+1;
        }
        else rs = mid-1;
    }
    cout << ret << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
