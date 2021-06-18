#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
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
 
 
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; ll k;
    cin >> n>> k;
    vector<vector<ll>> d(n+1, vector<ll>(n+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> d[i][j];
    int cnt = 0;
    vector<int> p(n-1);
    for(int i = 1; i < n; i++)p.pb(i+1);
    do{
        ll t = 0;
        int cur = 1;
        for(int i = 0; i < n-1; i++){
            t += d[cur][p[i]];
            cur = p[i];
        }
        t += d[cur][1];
        if(t == k)
            cnt++;
    }while(next_permutation(all(p)));
    cout << cnt << '\n';
}
