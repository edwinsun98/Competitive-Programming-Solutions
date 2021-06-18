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
 
 
 
int vec[10], vec2[10];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("maxcross.in", "r", stdin);
//    freopen("maxcross.out", "w", stdout);
 
    string s;
    cin >> s;
    sort(all(s));
    if((int)s.length() < 3){
        do{
            int test = stoi(s);
            if(test%8==0){cout << "Yes" << '\n'; return 0;}
        }while(next_permutation(all(s)));
        cout << "No" << '\n'; return 0;
    }
    for(char c:s)vec[c-'0']++;
    vec[0] = 1e9;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            for(int k = 1; k <= 9; k++){
                memcpy(vec2, vec, sizeof(vec2));
                vec2[i]--; vec2[j]--; vec2[k]--;
                bool ok = 1;
                for(int p = 1; p <= 9; p++){
                    if(vec2[p] < 0){ok = 0; break;}
                }
                if(!ok)continue;
                int test = i*100+j*10+k;
                if(test%8==0){
                    cout << "Yes" << '\n'; return 0;
                }
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}
