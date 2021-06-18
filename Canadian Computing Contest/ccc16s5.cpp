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


const int N = (int)1e5+69;
int a[N], tmp[N], n;
ll t;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == '1')
            a[i] = 1;
    }
    for(int i = 50; i >= 0; i--){
        if(t&((ll)1<<i)){
            int k = ((ll)1<<i)%n;
            for(int i = 0; i < n; i++){
                int x = ((i-k)%n+n)%n, y = (i+k)%n;
                tmp[i] = a[x]^a[y];
            }
            for(int i = 0; i < n; i++)a[i] = tmp[i];
        }
    }
    for(int i = 0; i < n; i++)cout << a[i];
    cout << '\n';
    return 0;
}
