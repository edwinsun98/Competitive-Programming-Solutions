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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


int m, n;
bool vis[1002][1002], vis2[1000002];
queue<pair<int,pair<int,int>>> q;
int a[1002][1002];

bool in_range(int x, int y){
    return x >= 1 && x <= m && y >= 1 && y <= n;
}

void solve(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    vis[1][1] = 1;
    vis2[a[1][1]] = 1;
    q.push({a[1][1], {1, 1}});
    while(!q.empty()){
        int num = q.front().f, x = q.front().s.f, y = q.front().s.s; q.pop();
        for(int i = 1; i*i <= num; i++){
            if(num%i)continue;
            int x_ = i, y_ = num/i;
            if(x_ == m && y_ == n){
                cout << "yes" << '\n';
                return;
            }
            if(in_range(x_, y_) && !vis[x_][y_] && !vis2[a[x_][y_]]){
                vis[x_][y_] = 1;
                vis2[a[x_][y_]] = 1;
                q.push({a[x_][y_], {x_, y_}});
            }
            swap(x_, y_);
            if(x_ == m && y_ == n){
                cout << "yes" << '\n';
                return;
            }
            if(in_range(x_, y_) && !vis[x_][y_] && !vis2[a[x_][y_]]){
                vis[x_][y_] = 1;
                vis2[a[x_][y_]] = 1;
                q.push({a[x_][y_], {x_, y_}});
            }
        }
    }
    cout << "no" << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
