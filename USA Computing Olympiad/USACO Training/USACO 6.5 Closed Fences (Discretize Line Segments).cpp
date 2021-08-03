/*
ID: edwinsu1
LANG: C++11
TASK: fence4
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double eps = 1e-9;
struct point{
    double x, y;
    bool operator == (const point& a){
        return fabs(x-a.x) < eps && fabs(y-a.y) < eps;
    }
};
struct event{
    double x, y, x2, y2; int i, i2;
};
bool operator<(const event& a, const event& b){
    if(a.i2 == b.i2)return a.i < b.i;
    return a.i2 < b.i2;
}
double crossProduct(point origin, point a, point b){
    double x1 = a.x - origin.x, x2 = b.x - origin.x, y1 = a.y - origin.y, y2 = b.y - origin.y;
    return x1*y2 - y1*x2;
}
double ma(double a, double b){
    if(a < b)return b;
    return a;
}
double mi(double a, double b){
    if(b < a)return b;
    return a;
}
bool intersect(point a1, point a2, point b1, point b2){
    if(ma(a1.x, a2.x) < mi(b1.x, b2.x) || ma(b1.x, b2.x) < mi(a1.x, a2.x) ||
       ma(a1.y, a2.y) < mi(b1.y, b2.y) || ma(b1.y, b2.y) < mi(a1.y, a2.y)
       || crossProduct(a1, a2, b1) * crossProduct(a1, a2, b2) > eps
       || crossProduct(b1, b2, a1) * crossProduct(b1, b2, a2) > eps)
        return false;
    return true;
}
int n;
point start;
vector<point> fence;
vector<event> ans;
void solve(){
    cin >> n >> start.x >> start.y;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        fence.pb(point{x, y});
    }
    for(int i = 0; i < n; i++){
        point si = fence[i], ei = fence[(i+1)%n];
        for(int j = 0; j < n; j++){
            point sj = fence[j], ej = fence[(j+1)%n];
            if(si == sj || si == ej || ei == sj || ei == ej)continue;
            if(intersect(si, ei, sj, ej)){
                cout << "NOFENCE" << '\n';
                return;
            }
        }
    }
    for(int i = 0; i < n; i++){
        double dx = fence[(i+1)%n].x-fence[i].x, dy = fence[(i+1)%n].y-fence[i].y;
        double incx = dx/500, incy = dy/500;
        double x = fence[i].x, y = fence[i].y;
        for(double iter = 1; iter < 500; iter++){
            x += incx, y += incy;
            bool ok = 1;
            for(int j = 0; j < n; j++){
                if(j == i)continue;
                if(intersect(start, point{x, y}, fence[j], fence[(j+1)%n])){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                if(i == n-1)ans.pb(event{fence[(i+1)%n].x, fence[(i+1)%n].y, fence[i].x, fence[i].y, 0, n-1});
                else ans.pb(event{fence[i].x, fence[i].y, fence[(i+1)%n].x, fence[(i+1)%n].y, i, i+1});
                break;
            }
        }
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for(auto& i : ans)cout << i.x << " " << i.y << " " << i.x2 << " " << i.y2 << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("fence4.in", "r", stdin);
    freopen("fence4.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
