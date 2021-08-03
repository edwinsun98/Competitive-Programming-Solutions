/*
ID: edwinsu1
LANG: C++11
TASK: clocks
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define all(vec) begin(vec), end(vec)
#define pf push_front
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;


const int N = 9;
vector<int> a(N+1), v(N+1);
vector<int> moves[N+1];
string ans;
void turn(int i){
    for(auto& j : moves[i]){
        v[j] += 3;
        if(v[j] > 12)v[j] -= 12;
    }
}
bool check(){
    for(int i = 1; i <= N; i++)if(v[i]^12)return 0;
    return 1;
}

void solve(){
    for(int i = 1; i <= N; i++)cin >> a[i];
    moves[1] = {1, 2, 4, 5};
    moves[2] = {1, 2, 3};
    moves[3] = {2, 3, 5, 6};
    moves[4] = {1, 4, 7};
    moves[5] = {2, 4, 5, 6, 8};
    moves[6] = {3, 6, 9};
    moves[7] = {4, 5, 7, 8};
    moves[8] = {7, 8, 9};
    moves[9] = {5, 6, 8, 9};
    for(int ones = 0; ones < 4; ones++){
        for(int twos = 0; twos < 4; twos++){
            for(int threes = 0; threes < 4; threes++){
                for(int fours = 0; fours < 4; fours++){
                    for(int fives = 0; fives < 4; fives++){
                        for(int sixes = 0; sixes < 4; sixes++){
                            for(int sevens = 0; sevens < 4; sevens++){
                                for(int eights = 0; eights < 4; eights++){
                                    for(int nines = 0; nines < 4; nines++){
                                        string str = "";
                                        v = a;
                                        for(int i = 1; i <= ones; i++)turn(1), str += "1";
                                        for(int i = 1; i <= twos; i++)turn(2), str += "2";
                                        for(int i = 1; i <= threes; i++)turn(3), str += "3";
                                        for(int i = 1; i <= fours; i++)turn(4), str += "4";
                                        for(int i = 1; i <= fives; i++)turn(5), str += "5";
                                        for(int i = 1; i <= sixes; i++)turn(6), str += "6";
                                        for(int i = 1; i <= sevens; i++)turn(7), str += "7";
                                        for(int i = 1; i <= eights; i++)turn(8), str += "8";
                                        for(int i = 1; i <= nines; i++)turn(9), str += "9";
                                        if(check()){
                                            if(str.length() < ans.length() || ans == ""){
                                                ans = str;
                                            }else if(str.length() == ans.length() && str < ans){
                                                ans = str;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < ans.length(); i++){
        if(i == 0)cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
