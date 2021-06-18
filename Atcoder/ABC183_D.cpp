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
 
 
const int N = (int)2e5+69;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; ll w;
    cin >> n >> w;
    vector<ll> a(N);
    for(int i = 1; i <= n; i++){
        int s, t; ll p;
        cin >> s >> t >> p;
        s++; t++;
        a[s]+= p; a[t]-= p;
    }
    for(int i = 1; i <= N; i++){
        a[i] += a[i-1];
        if(a[i] > w){
            cout << "No" << '\n'; return 0;
        }
    }
    cout << "Yes" << '\n';
}
