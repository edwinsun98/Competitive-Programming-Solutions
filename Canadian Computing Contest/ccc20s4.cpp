#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define p push
#define ll long long
#define lld long long double
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
using namespace std;


struct seg{
    int a, b, c;
};
int fun(seg A, seg B, seg C){
    int cost = 0;
    int delta = min(A.b, B.a);
    A.b -= delta; B.a -= delta; cost += delta;
    if(B.a > 0){
        cost += B.a;
        A.c -= B.a;
        B.c += B.a;
    }
    delta = min(A.c, C.a);
    A.c -= delta; C.a -= delta; cost += delta;
    if(C.a > 0){
        cost += C.a;
        A.b -= C.a;
        C.b += C.a;
    }
    delta = max(B.c, C.b);
    cost += delta;
    return cost;
}
int fun2(seg A, seg C, seg B){
    int cost = 0;
    int delta = min(A.c, C.a);
    A.c -= delta; C.a -= delta; cost += delta;
    if(C.a > 0){
        cost += C.a;
        A.b -= C.a;
        C.b += C.a;
    }
    delta = min(A.b, B.a);
    A.b -= delta; B.a -= delta; cost += delta;
    if(B.a > 0){
        cost += B.a;
        A.c -= B.a;
        B.c += B.a;
    }
    delta = max(B.c, C.b);
    cost += delta;
    return cost;
}
int fun3(seg B, seg C, seg A){
    int cost = 0;
    int delta = min(B.c, C.b);
    B.c -= delta; C.b -= delta; cost += delta;
    if(C.b > 0){
        cost += C.b;
        B.a -= C.b;
        C.a += C.b;
    }
    delta = min(B.a, A.b);
    B.a -= delta; A.b -= delta; cost += delta;
    if(A.b > 0){
        cost += A.b;
        B.c -= A.b;
        A.c += A.b;
    }
    delta = max(A.c, C.a);
    cost += delta;
    return cost;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for(char f : s){
        if(f == 'A')a++;
        else if(f == 'B')b++;
        else if(f == 'C')c++;
    }

    int n = (int)s.length();
    s += s;
    vector<char> vec(n+n+1);
    vector<int> ac(n+n+1), bc(n+n+1), cc(n+n+1);
    for(int i = 0; i < (int)s.length(); i++)vec[i+1] = s[i];
    for(int i = 1; i <= n+n; i++){
        if(vec[i] == 'A')ac[i]++;
        else if(vec[i] == 'B')bc[i]++;
        else cc[i]++;
    }
    for(int i = 1; i <= n+n; i++){
        ac[i] += ac[i-1];
        bc[i] += bc[i-1];
        cc[i] += cc[i-1];
    }
    int ans = INT_MAX;
    for(int i = 1; i+a+b+c-1 <= n+n; i++){ 
        seg A = seg{ac[i+a-1]-ac[i-1],bc[i+a-1]-bc[i-1],cc[i+a-1]-cc[i-1]};
        seg B = seg{ac[i+a+b-1]-ac[i+a-1],bc[i+a+b-1]-bc[i+a-1],cc[i+a+b-1]-bc[i+a-1]};
        seg C = seg{ac[i+a+b+c-1]-ac[i+a+b-1],bc[i+a+b+c-1]-bc[i+a+b-1],cc[i+a+b+c-1]-cc[i+a+b-1]};
        ans = min(ans, fun(A,B,C));
        A = seg{ac[i+a-1]-ac[i-1],bc[i+a-1]-bc[i-1],cc[i+a-1]-cc[i-1]};
        C = seg{ac[i+a+c-1]-ac[i+a-1],bc[i+a+c-1]-bc[i+a-1],cc[i+a+c-1]-bc[i+a-1]};
        B = seg{ac[i+a+b+c-1]-ac[i+a+c-1],bc[i+a+b+c-1]-bc[i+a+c-1],cc[i+a+b+c-1]-cc[i+a+c-1]};
        ans = min(ans, fun2(A,C,B));
        B = seg{ac[i+b-1]-ac[i-1],bc[i+b-1]-bc[i-1],cc[i+b-1]-cc[i-1]};
        C = seg{ac[i+b+c-1]-ac[i+b-1],bc[i+b+c-1]-bc[i+b-1],cc[i+b+c-1]-bc[i+b-1]};
        A = seg{ac[i+a+b+c-1]-ac[i+b+c-1],bc[i+a+b+c-1]-bc[i+b+c-1],cc[i+a+b+c-1]-cc[i+b+c-1]};
        ans = min(ans, fun3(B,C,A));
    }
    cout << ans << '\n';
    return 0;
}
