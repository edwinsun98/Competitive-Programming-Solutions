#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
ll a[200001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll res = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] < a[i-1]){
            ll need = a[i-1]-a[i];
            a[i] += need; res += need;
        }
    }
    cout << res << endl;
    return 0;
}
