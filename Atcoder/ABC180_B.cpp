#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
#define ll long long
#define lld long long double
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
using namespace std;
 
 
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("maxcross.in", "r", stdin);
//    freopen("maxcross.out", "w", stdout);
    int n;
    cin >> n;
    vector<double> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    double x = 0, y = 0, z = 0;
    for(int i = 0; i < n; i++){
        x += (double)abs(a[i]);
        y += (double)abs(a[i])*(double)abs(a[i]);
        z = max(z, (double)abs(a[i]));
    }
    y = (double)sqrt((double)y);
    cout << setprecision(12) << x << '\n';
    cout << setprecision(12) << y << '\n';
    cout << setprecision(12) << z << '\n';
 
    return 0;
}
