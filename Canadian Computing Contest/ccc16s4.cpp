#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void scan(){}template<class T,class...A>void scan(T&t,A&...a){cin>>t,scan(a...);}
void print(){}template<class T,class...A>void print(T t,A...a){cout<<t,print(a...);}
int n, res = 0, a[401];
bool dp[401][401];
int dis(int l, int r){return a[r]-a[l-1];}
bool ds(int l, int r){
    for(int mid = l; mid < r; mid++){
        if(dp[l][mid] && dp[mid+1][r] && dis(l,mid)==dis(mid+1,r)){
            return true;
        }
    }
    return false;
}
bool ts(int l, int r){
    for(int ms = l+1; ms < r; ms++){
        if(!dp[l][ms-1])continue;
        for(int me = ms; me < r; me++){
            if(dp[ms][me] && dp[me+1][r] && dis(me+1,r) == dis(l,ms-1))return true;
        }
    }
    return false;
}
int main()
{
    scan(n);
    for(int i = 1, s; i <= n; i++){
        scan(s);
        if(i == 1){
            a[1] = s;
        }
        else a[i] = a[i-1]+s;
    }

    for(int k= 0; k < n; k++){
        for(int i = 1; i <= n-k; i++){
            int j = k+i;
            if(i==j)dp[i][j] = true;
            else if(j-i <= 2 && dis(i,i) == dis(j,j) && dp[i][i] && dp[j][j])dp[i][j] = true;
            else if(ts(i,j))dp[i][j] = true;
            else if(ds(i,j))dp[i][j] = true;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(dp[i][j]){res = max(res, dis(i,j));}
        }
    }
    print(res);

    return 0;
}
