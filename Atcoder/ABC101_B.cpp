#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
 
int main(){
   int n; cin >> n;
   string s; s = to_string(n);
   int temp = 0;
   for(int i  = 0; i < s.length(); i++){
    	temp += (int)s[i]-'0';
   }
   if(n%temp)cout << "No" << endl;
   else cout << "Yes" << endl;
   return 0;
}
