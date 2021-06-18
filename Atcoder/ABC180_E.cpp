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
 
 
 
struct ed{
    ll x, y, z;
};
struct state{
    int u, v1;
};
const int sz = (int)1<<18;
ed wt[20];
ll dp[18][sz];
ll ans = LLONG_MAX;
int n;
void go(int cur, int vis1){
    ll dis = dp[cur][vis1];
    if(vis1 == (int)(1<<n)-1){ //time to go back to 1
        ll cost = dis+(ll)abs(wt[0].x-wt[cur].x)+(ll)abs(wt[0].y-wt[cur].y)+(ll)max((ll)0, wt[0].z-wt[cur].z);
        ans = min(ans, cost);
        return;
    }
    else{
        for(int j = 0; j < n; j++){
            int t1 = vis1;
            if(t1&(1<<j))continue;
            t1 |= (1<<j);
            ll cost = dis+(ll)abs(wt[j].x-wt[cur].x)+(ll)abs(wt[j].y-wt[cur].y)+(ll)max((ll)0, wt[j].z-wt[cur].z);
            if(cost >= dp[j][t1])continue;
            dp[j][t1] = cost;
            go(j, t1);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("maxcross.in", "r", stdin);
//    freopen("maxcross.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >>y >>z;
        wt[i] = (ed){x, y, z};
    }
    int tmp = 0;
    tmp |= (1<<0);
    memset(dp, 0x3f3f3f, sizeof(dp));
    dp[0][tmp] = 0;
    go(0, tmp);
    cout << ans << '\n';
    return 0;
}
