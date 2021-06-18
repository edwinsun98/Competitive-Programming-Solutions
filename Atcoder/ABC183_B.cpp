#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
typedef long long ll;
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double ans = (-1.0*a*d-b*c)/(-1.0*b-d);
    cout << fixed << setprecision(7) << ans << '\n';
}
