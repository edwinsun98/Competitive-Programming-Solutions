#include <bits/stdc++.h>
using namespace std;
bool dp[31][31][31][31];
int mo[5][5] = {{2,1,0,2},{1,1,1,1},{0,0,2,1},{0,3,0,0},{1,0,0,1}};
int n, a, b , c, d;
bool fun(int a, int b, int c, int d){
    if (a < 0 || b < 0 || c < 0 || d < 0)return false;
    else{
        if (dp[a][b][c][d])
          return false;
        else return true;
    }
}
int main()
{
    for(int i = 0; i < 31; i++){
        for(int j = 0; j < 31; j++){
            for(int k = 0; k < 31; k++){
                for(int l = 0; l < 31; l++){
                    for(int m = 0; m < 5; m++){
                        if (fun(i-mo[m][0],j-mo[m][1],k-mo[m][2],l-mo[m][3]))dp[i][j][k][l] = true;
                    }
                }
            }
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        if(dp[a][b][c][d])cout << "Patrick" << endl;
        else cout << "Roland" << endl;
    }
    
}
