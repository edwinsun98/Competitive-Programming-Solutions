/*
ID: edwinsu1
LANG: C++
TASK: cryptcow
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


const int mod = 1003909; 
struct hashof{
    string str; int n;
    int seed = 131;
    int h = 0;
    int init(string s){
        str = s;
        int n = (int)s.length();
        for(int i = 1; i <= n; i++)h = (h*seed+str[i-1])%mod;
        return h;
    }
}out;

vector<bool> st(mod+3);
string message = "Begin the Escape execution at the Break of Dawn";
int len = message.length();
string in;
bool check(string str){
    int stringHash = out.init(str);
    if(st[stringHash])return 0;
    else st[stringHash] = 1;
    int leftO = 1e9, leftC = 1e9, leftW = 1e9, rightO = 0, rightC = 0, rightW = 0;
    int n = str.length();
    for(int i = 0; i < n; i++){
        if(str[i] == 'C'){
            rightC = max(rightC, i);
            leftC = min(leftC, i);
        }else if(str[i] == 'O'){
            rightO = max(rightO, i);
            leftO = min(leftO, i);
        }else if(str[i] == 'W'){
            rightW = max(rightW, i);
            leftW = min(leftW, i);
        }
    }
    // check end state
    if(leftO == 1e9){
        return str == message;
    }
    // check prefix
    if(str.substr(0, leftC) != message.substr(0, leftC))return 0;
    // check suffix
    if(rightW < n-1){
        int suf = n-rightW-1;
        if(str.substr(rightW+1, suf) != message.substr(len-suf, suf))return 0;
    }
    // check order of 'C', 'O', and 'W'
    if(leftO < leftC || leftW < leftC || rightW < leftO)return 0;
    // check substrings bounded by 'C', 'O', and 'W
    string seg = "";
    for(int i = 0; i < n; i++){
        if(str[i] == 'C' || str[i] == 'O' || str[i] == 'W'){
            if(message.find(seg) == -1)return 0;
            seg = "";
        }else seg += str[i];
    }
    if(message.find(seg) == -1)return 0;
    // transition
    for(int i = 0; i < n; i++){
        if(str[i] == 'C'){
            for(int j = i+1; j < n; j++){
                if(str[j] == 'O'){
                    for(int k = j+1; k < n; k++){
                        if(str[k] == 'W'){
                            string strCO, strOW;
                            if(j-i == 1)strCO = "";
                            else strCO = str.substr(i+1, j-i-1);
                            if(k-j == 1)strOW = "";
                            else strOW = str.substr(j+1, k-j-1);
                            string newstr = str.substr(0, i)+strOW+strCO;
                            if(k < n-1)newstr += str.substr(k+1, n-k-1);
                            if(check(newstr))return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
void solve(){
    getline(cin, in);
    int countC = 0, countO = 0, countW = 0;
    for(char& c: in){
        if(c == 'C')countC++;
        else if(c == 'O')countO++;
        else if(c == 'W')countW++;
    }
    if(countC == countO && countC == countW && check(in))cout << 1 << " " << countC << '\n';
    else cout << "0 0" << '\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cryptcow.in", "r", stdin);
    freopen("cryptcow.out", "w", stdout);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
