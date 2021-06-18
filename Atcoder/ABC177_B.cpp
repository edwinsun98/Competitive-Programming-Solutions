#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
#define endl '\n'
using namespace std;
int f(string a, string b){
    int c = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i])c++;
    }
    return c;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int ans = 1e9;
    for(int i = 0; i < s.length(); i++){
        int x = i+t.length();
        if(x > s.length())break;
        ans = min(ans, f(t, s.substr(i,t.length())));
    }
    cout << ans << endl;
    return 0;
}
