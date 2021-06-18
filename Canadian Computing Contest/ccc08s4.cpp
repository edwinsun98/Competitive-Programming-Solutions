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


int ret(int cur, int delta, int op){
    if(op == 1)cur +=delta;
    else if(op == 2)cur -= delta;
    else if(op == 3)cur *= delta;
    else{
        if(delta == 0 || cur%delta){
            return -1;
        }
        else cur /= delta;
    }
    return cur;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        vector<int> a(4);
        for(int i = 0; i < 4; i++)cin >> a[i];
        sort(all(a));
        int ans = INT_MIN;
        vector<int> x, y, z, v;
        for(int i = 1; i <= 4; i++){x.pb(i); y.pb(i); z.pb(i); v.pb(i);}
        do{
            for(auto i : x){
                for(auto j : y){
                    for(auto k : z){
                        for(auto u : v){
                            vector<int> t;
                            t.pb(i); t.pb(j); t.pb(k); t.pb(u);
                            sort(all(t));
                            do{
                                bool ok = 1;
                                int sum = a[0];
                                for(int p = 1; p < 4; p++){
                                    sum = ret(sum, a[p], t[p]);
                                    if(sum == -1){
                                        ok = 0; break;
                                    }
                                }
                                if(ok){
                                    if(sum <= 24)
                                        ans = max(ans, sum);
                                }
                                int ge1 = ret(a[0], a[1], t[1]), ge2 = ret(a[2], a[3], t[3]);
                                if(ge1 != -1 && ge2 != -1){
                                    sum = ret(ge1, ge2, t[2]);
                                    if(sum <= 24 && sum != -1)ans = max(ans, sum);
                                }
                            }while(next_permutation(all(t)));
                        }
                    }
                }
            }
        }while(next_permutation(all(a)));
        cout << ans << '\n';
    }
}
