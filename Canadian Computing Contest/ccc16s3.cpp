#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int R = 1e5;
int N,M,T,len,far,a,b,cur,don,dis[R],pre[R];
bool pho[R];
vector<int>adj[R];
queue<int>q;
queue<int>v;
bool vis[R],marked[R];
int edge = 0;
void bfs(int s){
    len = 0; far = 0;
    memset(vis,false,N);
    q.push(s); vis[s] = true; dis[s] = 0;
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(dis[cur] > len && pho[cur]){
            far = cur; len = dis[cur];
        }
        for(int i = 0; i < adj[cur].size(); i++){
            if(!vis[adj[cur][i]]){
                vis[adj[cur][i]] = true;
                pre[adj[cur][i]] = cur;
                dis[adj[cur][i]] = dis[cur]+1;
                q.push(adj[cur][i]);
            }
        }
    }
}
int main()
{
    memset(pre,0,N);
    memset(dis,0,N);
    
    cin >> N >> M;
    memset(pho,false,N);
    for(int i = 0; i < M; i++){
        cin >> T; pho[T] = true; v.push(T);
    }
    for(int i = 0; i < N-1; i++){
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    bfs(0); don=far; bfs(don); memset(marked,false,N);
    while(!v.empty()){
        cur = v.front(); v.pop();
        for(int i = cur; i != don; i = pre[i]){
            if(!marked[i]){marked[i] = true; edge++;}
            else break;
        }
    }
    cout << edge*2-len << endl;
    return 0;
}
