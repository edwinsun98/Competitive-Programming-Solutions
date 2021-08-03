#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
int n, q, a[5001], cnt[2000004];
ll psa[5001][5001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int k = i+1; k <= n; k++){
            int v = -a[i]-a[k]+1000001;
            if(v >= 0 && v <= 2000002)psa[i][k] += cnt[v];
            cnt[a[k]+1000001]++;
        }
        for(int k = i+1; k <= n; k++)cnt[a[k]+1000001]-=1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            psa[i][j] += psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
        }
    }
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        cout << psa[y][y]-psa[x-1][y]-psa[y][x-1]+psa[x-1][x-1] << endl;
    }
}
