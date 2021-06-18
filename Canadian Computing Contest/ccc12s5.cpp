#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int r, c, g[27][27], k, x, y;
int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < k; i++){
        cin >> x >> y; g[x][y] = -1;
    }
    g[1][1] = 1;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(g[i][j] == -1)continue;
            if(i-1 >= 1){
                if(g[i-1][j] != -1){
                    g[i][j] += g[i-1][j];
                }
            }
            if(j-1 >= 1){
                if(g[i][j-1] != -1){
                    g[i][j] += g[i][j-1];
                }
            }
        }
    }
    cout << g[r][c];
    return 0;
}
