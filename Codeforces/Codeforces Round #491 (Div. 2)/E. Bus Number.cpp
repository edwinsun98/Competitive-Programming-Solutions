#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;


void solve(){
    string s;
    cin >> s;
    vector<int> f(10);
    vector<ll> fact(20);
    ll ans = 0;
    fact[0] = 1;
    for(ll i = 1; i <= 19; i++)fact[i] = fact[i-1]*i;
    for(char& c : s)f[c-'0']++;
    for(int zero = 0; zero <= f[0]; zero++){
        for(int one = 0; one <= f[1]; one++){
            for(int two = 0; two <= f[2]; two++){
                for(int three = 0; three <= f[3]; three++){
                    for(int four = 0; four <= f[4]; four++){
                        for(int five = 0; five <= f[5]; five++){
                            for(int six = 0; six <= f[6]; six++){
                                for(int seven = 0; seven <= f[7]; seven++){
                                    for(int eight = 0; eight <= f[8]; eight++){
                                        for(int nine = 0; nine <= f[9]; nine++){
                                            if(zero == 0 && f[0])continue;
                                            if(one == 0 && f[1])continue;
                                            if(two == 0 && f[2])continue;
                                            if(three == 0 && f[3])continue;
                                            if(four == 0 && f[4])continue;
                                            if(five == 0 && f[5])continue;
                                            if(six == 0 && f[6])continue;
                                            if(seven == 0 && f[7])continue;
                                            if(eight == 0 && f[8])continue;
                                            if(nine == 0 && f[9])continue;
                                            if(zero > 0){
                                                int s = zero+one+two+three+four+five+six+seven+eight+nine-1;
                                                if(one > 0){
                                                    one--;
                                                    ll res = fact[s];
                                                    res /= fact[zero];
                                                    res /= fact[one];
                                                    res /= fact[two];
                                                    res /= fact[three];
                                                    res /= fact[four];
                                                    res /= fact[five];
                                                    res /= fact[six];
                                                    res /= fact[seven];
                                                    res /= fact[eight];
                                                    res /= fact[nine];
                                                    ans += res;
                                                    one++;
                                                }
                                                if(two > 0){
                                                    two--;
                                                    ll res = fact[s];
                                                    res /= fact[zero];
                                                    res /= fact[one];
                                                    res /= fact[two];
                                                    res /= fact[three];
                                                    res /= fact[four];
                                                    res /= fact[five];
                                                    res /= fact[six];
                                                    res /= fact[seven];
                                                    res /= fact[eight];
                                                    res /= fact[nine];
                                                    ans += res;
                                                    two++;
                                                }
                                                if(three > 0){
                                                    three--;
                                                    ll res = fact[s];
                                                    res /= fact[zero];
                                                    res /= fact[one];
                                                    res /= fact[two];
                                                    res /= fact[three];
                                                    res /= fact[four];
                                                    res /= fact[five];
                                                    res /= fact[six];
                                                    res /= fact[seven];
                                                    res /= fact[eight];
                                                    res /= fact[nine];
                                                    ans += res;
                                                    three++;
                                                }
                                                if(four > 0){
                                                    four--;
                                                    ll res = fact[s];
                                                    res /= fact[zero];
                                                    res /= fact[one];
                                                    res /= fact[two];
                                                    res /= fact[three];
                                                    res /= fact[four];
                                                    res /= fact[five];
                                                    res /= fact[six];
                                                    res /= fact[seven];
                                                    res /= fact[eight];
                                                    res /= fact[nine];
                                                    ans += res;
                                                    four++;
                                                }
                                                if(five > 0){
                                                    five--;
                                                    ll res = fact[s];
                                                    res /= fact[zero];
                                                    res /= fact[one];
                                                    res /= fact[two];
                                                    res /= fact[three];
                                                    res /= fact[four];
                                                    res /= fact[five];
                                                    res /= fact[six];
                                                    res /= fact[seven];
                                                    res /= fact[eight];
                                                    res /= fact[nine];
                                                    ans += res;
                                                    five++;
                                                }
                                                if(six > 0){
                                                    six--;
                                                    ll res = fact[s];
                                                    res /= fact[zero];
                                                    res /= fact[one];
                                                    res /= fact[two];
                                                    res /= fact[three];
                                                    res /= fact[four];
                                                    res /= fact[five];
                                                    res /= fact[six];
                                                    res /= fact[seven];
                                                    res /= fact[eight];
                                                    res /= fact[nine];
                                                    ans += res;
                                                    six++;
                                                }
                                                if(seven > 0){
                                                    seven--;
                                                    ll res = fact[s];
                                                    res /= fact[zero];
                                                    res /= fact[one];
                                                    res /= fact[two];
                                                    res /= fact[three];
                                                    res /= fact[four];
                                                    res /= fact[five];
                                                    res /= fact[six];
                                                    res /= fact[seven];
                                                    res /= fact[eight];
                                                    res /= fact[nine];
                                                    ans += res;
                                                    seven++;
                                                }
                                                if(eight > 0){
                                                    eight--;
                                                    ll res = fact[s];
                                                    res /= fact[zero];
                                                    res /= fact[one];
                                                    res /= fact[two];
                                                    res /= fact[three];
                                                    res /= fact[four];
                                                    res /= fact[five];
                                                    res /= fact[six];
                                                    res /= fact[seven];
                                                    res /= fact[eight];
                                                    res /= fact[nine];
                                                    ans += res;
                                                    eight++;
                                                }
                                                if(nine > 0){
                                                    nine--;
                                                    ll res = fact[s];
                                                    res /= fact[zero];
                                                    res /= fact[one];
                                                    res /= fact[two];
                                                    res /= fact[three];
                                                    res /= fact[four];
                                                    res /= fact[five];
                                                    res /= fact[six];
                                                    res /= fact[seven];
                                                    res /= fact[eight];
                                                    res /= fact[nine];
                                                    ans += res;
                                                    nine++;
                                                }
                                            }else{
                                                int s = zero+one+two+three+four+five+six+seven+eight+nine;
                                                ll res = fact[s];
                                                res /= fact[zero];
                                                res /= fact[one];
                                                res /= fact[two];
                                                res /= fact[three];
                                                res /= fact[four];
                                                res /= fact[five];
                                                res /= fact[six];
                                                res /= fact[seven];
                                                res /= fact[eight];
                                                res /= fact[nine];
                                                ans += res;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    int tc = 1;
//    cin >> tc;
    while(tc--){
        solve();
    }
}
