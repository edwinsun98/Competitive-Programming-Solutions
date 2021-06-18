#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, t; cin >> n >> x >> t;
    int res = (n/x)*t;
    if(n%x)res += t;
    cout << res << endl;
 
    return 0;
}
