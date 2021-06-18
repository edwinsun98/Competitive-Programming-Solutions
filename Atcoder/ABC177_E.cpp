#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
#define endl '\n'
using namespace std;
bool sv[1000002];
int f[1000002];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> vec(n+1);
    int g;
    for(int i = 1; i <= n; i++){
        cin >> vec[i]; f[vec[i]]++;
        if(i == 1){
            g = vec[i]; continue;
        }
        g = __gcd(g, vec[i]);
    }
    if(g == 1){
        //int cnt = 0;
        bool ok = 1;
        for(int i = 2; i <= 1000000; i++){
            if(!sv[i]){
                int cnt = f[i];
                sv[i] = 1;
                for(int j = i+i; j <= 1000000; j += i){
                    sv[j] = 1; cnt += f[j];
                }
                if(cnt <= 1)continue;
                ok = 0; break;
            }
        }
        if(ok){
            cout << "pairwise coprime" << endl;
        }
        else{
            cout << "setwise coprime" << endl;
        }
    }
    else{
        cout << "not coprime" << endl;
    }
    return 0;
}
