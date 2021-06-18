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
#define pb push_back
#define mod 1000000007
#define ll long long
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}
int n, x, y, dp[10000];
vector<int> adj[10000];
bool vis[10000];
priority_queue<int,vector<int>,greater<int>> q;
int main()
{
    scan(n); dp[1] = 1;
    while(true){
        scan(x,y);
        if(x == 0&&y==0)break;
        adj[x].push_back(y);
    }
    q.push(1); vis[1] = true;
    while(!q.empty()){
        int cur = q.top(); q.pop();
        for(int i : adj[cur]){
            dp[i] += dp[cur];
            if(!vis[i]){q.push(i); vis[i] = true;}
        }
    }
    print(dp[n]);
    return 0;
}
