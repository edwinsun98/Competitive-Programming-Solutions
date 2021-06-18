#include <bits/stdc++.h>
using namespace std;
#ifdef WIN64
#define gc getchar()
#define pc(x) putchar(x)
#endif
#ifndef WIN64
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#endif
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}
typedef long long ll;
int t, n, k, w, s[30001];
ll dp[501][30001];
void solve(){
    memset(dp,0,sizeof(dp));memset(s,0,sizeof(s));
    cin >> n >> k >> w;
    for(int i = 1, tp; i <= n; i++){
        cin >> tp;
        if(i == 1)s[i] = tp;
        else s[i] = s[i-1]+tp;
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j-1];
            if(j-w >= 0)dp[i][j] = max(dp[i][j],dp[i-1][j-w]+s[j]-s[j-w]);
        }
    }
    cout << dp[k][n] << endl;
}
int main(){
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
