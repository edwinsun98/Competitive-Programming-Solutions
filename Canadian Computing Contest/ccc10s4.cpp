#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
vector<pair<int,int>> adj[102];
vector<pair<string,int>> adj2[102];
vector<int> edge;
vector<int> cost;
unordered_map<string,int> mp;
unordered_map<string, int> weights;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
unordered_set<int> nodes;
bool flag;
int n, x, ep;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        edge.clear(); cost.clear();
        for(int j = 1; j <= x; j++){
            cin >> ep; edge.push_back(ep);
        }
        for(int j = 1; j <= x; j++){
            cin >> ep; cost.push_back(ep);
        }
        for(int j = 0; j < edge.size()-1; j++){
            int a = edge[j], b = edge[j+1];
            if(a > b)swap(a,b);
            string temp = to_string(a)+" "+to_string(b);
            adj2[i].push_back(make_pair(temp,cost[j]));
        }
        if(edge.size() > 2){
            int a = edge[edge.size()-1], b = edge[0];
            if(a > b)swap(a,b);
            string temp = to_string(a)+" "+to_string(b);
            adj2[i].push_back(make_pair(temp,cost[cost.size()-1]));
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < adj2[i].size(); j++){
            flag = false;
            for(int y = 1; y <= n; y++){
                if(y == i)continue;
                pair<int,int> one = {i,adj2[i][j].second};
                pair<int,int> two = {y,adj2[i][j].second};
                if(find(adj2[y].begin(),adj2[y].end(),adj2[i][j]) != adj2[y].end() &&
                   find(adj[y].begin(),adj[y].end(),one) == adj[y].end() &&
                   find(adj[i].begin(),adj[i].end(),two) == adj[i].end()){
                    adj[y].push_back(make_pair(i,adj2[i][j].second));
                    adj[i].push_back(make_pair(y,adj2[i][j].second));
                    if(y > i){
                        weights[to_string(i)+" "+to_string(y)] = adj2[i][j].second;
                    }
                    else{
                        weights[to_string(y)+" "+to_string(i)] = adj2[i][j].second;
                    }
                    flag = true;
                    mp[adj2[i][j].first] = 1;
                }
            }
            if(mp.find(adj2[i][j].first) != mp.end())flag = true;
            if(!flag){
                adj[0].push_back(make_pair(i,adj2[i][j].second));
                adj[i].push_back(make_pair(0,adj2[i][j].second));
                weights[to_string(0)+" "+to_string(i)] = adj2[i][j].second;
            }
        }
    }
    int ans1 = 9999999, ans2 = 9999999;
    int total = 0;
    vector<int> vis; vis.pb(1);
    while(vis.size() < n){
        int minw = 9999999, mint = 0;
        for(int i = 0; i < vis.size(); i++){
            int cur = vis[i];
            for(auto j : adj[cur]){
                if(find(vis.begin(),vis.end(),j.first) == vis.end() && j.second < minw && j.first != 0){
                    minw = j.second; mint = j.first;
                }
            }
        }
        vis.pb(mint);
        total += minw;
    }
    ans1 = total;

    total = 0; vis.clear(); vis.pb(0);
    while(vis.size() < n+1){
        int minw = 9999999, mint = 0;
        for(int i = 0; i < vis.size(); i++){
            int cur = vis[i];
            for(auto j : adj[cur]){
                if(find(vis.begin(),vis.end(),j.first) == vis.end() && j.second < minw){
                    minw = j.second; mint = j.first;
                }
            }
        }
        vis.pb(mint);
        total += minw;
    }
    ans2 = total;
    cout << min(ans1, ans2) << endl;

}
