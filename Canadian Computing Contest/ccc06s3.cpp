#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;



struct point{
    int x, y;
};
bool ccw(point& a, point& b, point& c){
    return (c.y-a.y)*(b.x-a.x) > (b.y-a.y)*(c.x-a.x);
}
int cross(point& a, point& b){
    return a.x*b.y-a.y*b.x;
}
int dot(point& a, point& b){
    return a.x*b.x+a.y*b.y;
}
bool collinear(point& a, point& b, point &c){
    return (b.y-a.y)*(c.x-a.x) == (c.y-a.y)*(b.x-a.x);
}
bool onseg(point& a, point& b, point& c){
    if(a.x == b.x && b.x == c.x){
        int ly = min(a.y, b.y), ry = max(a.y, b.y);
        return c.y >= ly && c.y <= ry;
    }
    // if point c is on seg ab
    int lx = min(a.x, b.x), rx = max(a.x, b.x);
    return collinear(a, b, c) && c.x >= lx && c.x <= rx;
}
bool intersect(point& a, point& b, point& c, point& d){
    // line segments ab and cd
    int as = ccw(a, c, d), bs = ccw(b, c, d), cs = ccw(a, b, c), ds = ccw(a, b, d);
    if(collinear(a, b, c) && collinear(a, b, d)){
        int minab = min(a.x, b.x), maxab = max(a.x, b.x);
        int mincd = min(c.x, d.x), maxcd = max(c.x, d.x);
        if(maxab < mincd || minab > maxcd)return 0;
        else return 1;
    }
    if(onseg(a, b, c) || onseg(a, b, d) || onseg(c, d, a) || onseg(c, d, b))return 1;
    return as != bs && cs != ds;
}

void solve(){
    int xr, yr, xj, yj;
    cin >> xr >> yr >> xj >> yj;
    point rom = point{xr, yr}, jul = point{xj, yj};
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        vector<point> vec(m);
        for(int j = 0; j < m; j++){
            cin >> vec[j].x >> vec[j].y;
        }
        bool blocked = 0;
        for(int j = 1; j < m; j++){
            if(intersect(rom, jul, vec[j-1], vec[j])){
                blocked = 1;
                break;
            }
        }
        if(intersect(rom, jul, vec[m-1], vec[0]))blocked = 1;
        if(blocked)cnt++;
    }
    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
      
