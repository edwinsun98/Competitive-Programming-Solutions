#include <bits/stdc++.h>
using namespace std;

int n,x,y,a,b;
vector<int>adj[10000];
queue <int> q;
bool vis[10000];
int dis[10000];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0)break;
        memset(vis,false,sizeof(vis));
        memset(dis,0,sizeof(dis));
        q.push(a);
        vis[a] = true;
        dis[a] = -1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i = 0; i < adj[cur].size(); i++){
                int x = adj[cur][i];
                if(!vis[x]){
                    vis[x] = true;
                    dis[x] = dis[cur]+1;
                    q.push(x);
                }
            }
        }
        if(vis[b])cout << "Yes " << dis[b] << endl;
        else cout << "No" << endl;
    }
    return 0;
}
