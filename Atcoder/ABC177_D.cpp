#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
#define endl '\n'
using namespace std;
set<int> adj[200001];
bool vis[200001];
int cnt = 0;
void dfs(int x){
    cnt++;
    for(auto i : adj[x]){
        if(!vis[i]){
            vis[i] = 1; dfs(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].insert(b); adj[b].insert(a);
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1; cnt = 0; dfs(i); res = max(res, cnt);
        }
    }
    cout << res << endl;
    return 0;
}
