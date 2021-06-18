#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
 
int main(){
   int c = 0;
   string s; cin >> s;
   for(int i = 0; i< s.length();i++){
    	if(s[i] == '+')c++;
    	else c--;
   }
   cout << c << endl;
   return 0;
}
