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
map<int,int> adj[N];
 
/*---------Disjoint Set---------*/
int parent[N], sz[N];
int find_set(int v){
    if (v == parent[v])return v;
    return find_set(parent[v]);
}
 
void union_set(int a, int b){
    int pa = find_set(a);
    int pb = find_set(b);
    if(sz[pa] < sz[pb]){
        sz[pb] += sz[pa];
        parent[pa] = pb;
        for(auto i : adj[pa]){
            adj[pb][i.f] += i.s;
        }
    }
    else{
        sz[pa] += sz[pb];
        parent[pb] = pa;
        for(auto i : adj[pb]){
            adj[pa][i.f] += i.s;
        }
    }
}
/*---------Disjoint Set End---------*/
 
int n, q;
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        parent[i] = i;
        sz[i] = 1;
        adj[i][a[i]] = 1;
    }
    for(int i = 0; i < q; i++){
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if(cmd == 1){
            if(find_set(x) != find_set(y)){
                union_set(x, y);
            }
        }
        else{
            int t = find_set(x);
            cout << adj[t][y] << '\n';
        }
    }
}
