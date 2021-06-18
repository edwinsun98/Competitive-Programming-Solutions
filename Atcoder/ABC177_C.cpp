#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
#define endl '\n'
using namespace std;
ll mod = 1000000007;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> vec(n+1);
    vector<ll> p(n+1);
    for(int i = 1; i <= n; i++)cin >> vec[i];
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1]+vec[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n-1; i++){
        ans += (vec[i]%mod) * ((p[n]-p[i])%mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
