#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;
int h, w, m, mx, my;
unordered_map<string, int> mp;
vector<pair<int,int>> vecx, vecy;
int x[300001], y[300001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> h >> w >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b; string str = ""; str += to_string(a); str+= " "; str += to_string(b);
        mp[str] = 1; x[a]++; y[b]++; mx = max(mx, x[a]); my = max(my, y[b]);
    }
    for(int i = 1; i <= h; i++)if(x[i] == mx)vecx.pb({x[i], i});
    for(int i = 1; i <= w; i++)if(y[i] == my)vecy.pb({y[i], i});
    for(int i = 0; i < vecx.size(); i++){
        for(int j = 0; j < vecy.size(); j++){
            string temp =""; temp += to_string(vecx[i].s); temp += " "; temp += to_string(vecy[j].s);
            if(mp.find(temp) == mp.end()){
                cout << mx+my << endl; return 0;
            }
            else continue;
        }
    }
    cout << mx+my-1 << endl;
    return 0;
}
