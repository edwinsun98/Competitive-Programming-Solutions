#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
#define ll long long
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
    int ge = 0;
    map<int,int> mp;
    vector<pii> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].f >> a[i].s;
        mp[a[i].f]++;
    }
    for(auto i : mp){
        if(i.s >= 3){
            cout << "Yes" << '\n';
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j==i)continue;
            if(a[i].f == a[j].f)continue;
            double m = (double)(a[i].f-a[j].f)/(a[i].s-a[j].s);
            for(int k = 0; k < n; k++){
                if(k==i || k==j)continue;
                if(a[j].f == a[k].f)continue;
                double mm = (double)(a[k].f-a[j].f)/(a[k].s-a[j].s);
                if(mm == m){
                    cout << "Yes" << '\n'; return 0;
                }
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}
