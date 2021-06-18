#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const ll mod = 1e9+7;
const int N = 1e5+6;
vector<ll> power1(N), power2(N);
vector<int> needle(26), haystack(26);
struct hashof{
    string str; int n;
    ll seed = 131;
    vector<ll> h;
    void init(string s){
        str = s;
        int n = (int)s.length(); h.assign(n+1, 0);
        for(int i = 1; i <= n; i++){
            h[i] = (h[i-1]*seed+str[i-1])%mod;
        }
    }
    ll gethash(int l, int r){
        return (h[r]-h[l-1]*power1[r-l+1]%mod+mod)%mod;
    }
};
struct hashof2{
    string str; int n;
    ll seed = 227;
    vector<ll> h;
    void init(string s){
        str = s;
        int n = (int)s.length(); h.assign(n+1, 0);
        for(int i = 1; i <= n; i++){
            h[i] = (h[i-1]*seed+str[i-1])%mod;
        }
    }
    ll gethash(int l, int r){
        return (h[r]-h[l-1]*power2[r-l+1]%mod+mod)%mod;
    }
};
int n, h;
string str1, str2;
hashof one;
hashof2 one2;
set<string> st;
void solve(){
    cin >> str1 >> str2;
    n = str1.size(); h = str2.size();
    power1[0] = power2[0] = 1;
    for(int i = 1; i <= N; i++){
        power1[i] = (power1[i-1]*(ll)131)%mod;
        power2[i] = (power2[i-1]*(ll)227)%mod;
    }
    one.init(str2);
    one2.init(str2);
    for(char& c : str1)needle[c-'a']++;
    for(int i = 1; i <= min(n, h); i++)haystack[str2[i-1]-'a']++;
    if(needle == haystack){
        string ts = to_string(one.gethash(1, n))+" "+to_string(one2.gethash(1, n));
        st.insert(ts);
    }
    for(int i = n+1; i <= h; i++){
        haystack[str2[i-1]-'a']++;
        haystack[str2[i-n-1]-'a']--;
        if(needle == haystack){
            string ts = to_string(one.gethash(i-n+1, i))+" "+to_string(one2.gethash(i-n+1, i));
            st.insert(ts);
        }
    }
    cout << st.size() << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
