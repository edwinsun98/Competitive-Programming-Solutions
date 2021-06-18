#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
struct ed{
    int w, x, y;
};
struct Comp{
    bool operator()(const ed& a, const ed& b){
        return a.w>b.w;
    }
};
int r, c, sx, sy, ex, ey;
char a[1001][1001];
int dis[1001][1001];
vector<pair<int,int>> cords = {{0,1}, {0,-1}, {-1, 0}, {1, 0}};
priority_queue<ed, vector<ed>, Comp> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> sx >> sy >> ex >> ey;
    for(int i = 1; i <= 1000; i++)for(int j = 1; j <= 1000; j++)dis[i][j] = 1e9;
    for(int i = 1; i <= r; i++){
        string line; cin >> line;
        for(int j = 1; j <= c; j++){
            a[i][j] = line[j-1];
        }
    }
    q.push((ed){0, sx, sy}); dis[sx][sy] = 0;
    while(!q.empty()){
        int wt = q.top().w, cx = q.top().x, cy = q.top().y; q.pop();
        if(cx == ex && cy == ey)break;
        for(auto i : cords){
            int tx = cx+i.f, ty = cy+i.s;
            if(tx >= 1 && tx <= r && ty >= 1 && ty <= c && a[tx][ty] == '.' && wt < dis[tx][ty]){
                dis[tx][ty] = wt; q.push((ed){dis[tx][ty], tx, ty});
            }
        }
        int lx = max(1, cx-2), ly = max(1, cy-2), rx = min(r, cx+2), ry = min(c, cy+2);
        for(int i = lx; i <= rx; i++){
            for(int j = ly; j <= ry; j++){
                if(a[i][j] == '.' && wt+1 < dis[i][j]){
                    dis[i][j] = wt+1; q.push((ed){dis[i][j], i, j});
                }
            }
        }
    }
    cout << (dis[ex][ey] == 1e9 ? -1 : dis[ex][ey]) << '\n';
    return 0;
}
