#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
typedef long long ll;
using namespace std;

const int shift = (int)1e6;
int h, k;
vector<int> a;
bool check(int len){
    for(int i = 0; i < h; i++){
        int pos = a[i]+len, cnt = 1, id = i+1, time = h-1;
        while(time--){
            if(abs(a[id]-pos) > len){
                cnt++;
                pos = a[id]+len;
            }
            id++;
        }
        if(cnt <= k)return 1;
    }
    return 0;
}
void solve(){
    cin >> h;
    a.assign(h+h, 0);
    for(int i = 0; i < h; i++)
        cin >> a[i];
    sort(a.begin(), a.begin()+h);
    for(int i = 0; i < h; i++)
        a[i+h] = a[i]+shift;
    cin >> k;
    int l = 0, r = (int)1e6, m, ans = INT_MAX;
    while(l <= r){
        m = (l+r)/2;
        if(check(m)){
            ans = min(ans, m);
            r = m-1;
        }
        else l = m+1;
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
