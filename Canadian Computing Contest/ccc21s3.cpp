#include <bits/stdc++.h>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

int n;
vector<ll> p, w, d;

ll getTime(ll pos){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(pos >= p[i]-d[i] && pos <= p[i]+d[i])continue;
        else if(pos < p[i]-d[i]){
            sum += w[i]*(p[i]-d[i]-pos);
        }
        else{
            sum += w[i]*(pos-p[i]-d[i]);
        }
    }
    return sum;
}
void solve(){
    cin >> n;
    p.assign(n, 0);
    w.assign(n, 0);
    d.assign(n, 0);
    for(int i = 0; i < n; i++){
        cin >> p[i] >> w[i] >> d[i];
    }
    ll ls = 0, rs = 1e12, ms, ans;
    while(ls <= rs){
        ms = (ls+rs)/2;
        if(getTime(ms) < getTime(ms+1)){
            ans = getTime(ms);
            rs = ms-1;
        }
        else{
            ls = ms+1;
        }
    }
    cout << ans << '\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
