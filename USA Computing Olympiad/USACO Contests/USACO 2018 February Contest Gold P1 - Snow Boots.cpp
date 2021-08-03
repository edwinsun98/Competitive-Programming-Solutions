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


struct tile{
    int id, depth;
};
bool operator<(const tile& a, const tile& b){
    return a.depth < b.depth;
}
struct event{
    int id, depth, step;
};
bool operator<(const event& a, const event& b){
    return a.depth < b.depth;
}

void solve(){
    int n, b;
    cin >> n >> b;
    deque<tile> tiles;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(!i && i == n-1)continue;
        tiles.pb(tile{i+1, x});
    }
    sort(all(tiles));
    set<int> st;
    st.insert(1);
    st.insert(n);
    vector<int> ans(b);
    vector<event> events(b);
    for(int i = 0; i < b; i++){
        int d, s;
        cin >> d >> s;
        events[i] = event{i, d, s};
    }
    sort(all(events));
    int maxdis = n-1;
    multiset<int> ranges;
    ranges.insert(n-1);
    for(auto& i : events){
        while(!tiles.empty() && tiles.front().depth <= i.depth){
            int id = tiles.front().id;
            st.insert(id);
            auto ls = st.find(id);
            auto ms = st.find(id);
            auto rs = st.find(id);
            ls--; rs++;
            auto it = ranges.lb((*rs)-(*ls));
            ranges.erase(it);
            ranges.insert((*ms)-(*ls));
            ranges.insert((*rs)-(*ms));
            tiles.pop_front();
        }
        maxdis = *ranges.rbegin();
        if(i.step >= maxdis)ans[i.id] = 1;
        else ans[i.id] = 0;
    }
    for(int i = 0; i < b; i++)cout << ans[i] << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
