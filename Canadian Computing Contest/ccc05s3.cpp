#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vll vector<long long>
#define all(vec) begin(vec), end(vec)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
ll arr[1030][1030], arr2[1030][1030];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int r, c;
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> arr[i][j];
        }
    }
    for(int tt = 0; tt < n-1; tt++){
        int tr, tc;
        cin >> tr >> tc;
        vector<vector<ll>> g(tr+1, vector<ll>(tc+1));
        for(int i = 1; i <= tr; i++)
            for(int j = 1; j <= tc; j++)
                cin >> g[i][j];
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                for(int x = 1; x <= tr; x++){
                    for(int y = 1; y <= tc; y++){
                        arr2[x+(i-1)*tr][y+(j-1)*tc] = arr[i][j]*g[x][y];
                    }
                }
            }
        }
        memcpy(arr, arr2, sizeof(arr2));
        r *= tr; c *= tc;
    }
    ll rowmax = LLONG_MIN, rowmin = LLONG_MAX, colmax = LLONG_MIN, colmin = LLONG_MAX, maxv = LLONG_MIN, minv = LLONG_MAX;
    for(int i = 1; i <= r; i++){
        ll sum = 0;
        for(int j = 1; j <= c; j++){
            sum += arr[i][j];
            maxv = max(maxv, arr[i][j]);
            minv = min(minv, arr[i][j]);
        }
        rowmax = max(rowmax, sum);
        rowmin = min(rowmin, sum);
    }
    for(int j = 1; j <= c; j++){
        ll sum = 0;
        for(int i = 1; i <= r; i++){
            sum += arr[i][j];
        }
        colmax = max(colmax, sum);
        colmin = min(colmin, sum);
    }
    cout << maxv << '\n';
    cout << minv << '\n';
    cout << rowmax << '\n';
    cout << rowmin << '\n';
    cout << colmax << '\n';
    cout << colmin << '\n';
    return 0;
}
