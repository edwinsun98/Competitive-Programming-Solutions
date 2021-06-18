#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    ll foo = 0;
    for(int i = 0; i < s.length(); i++){
        foo += (ll)s[i]-'0';
    }
    if(foo%9 == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
