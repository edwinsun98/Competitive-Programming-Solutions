#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
int a[100001];
int n, k;
int main(){
   cin >> n >> k;
   for(int i = 1; i <= n; i++)cin >> a[i];
   int cnt = 0;
   for(int i = 1; i <= n; i++){
    	int j;
    	for(j = i; j <= min(n, i+k-1) ; j++){
    	 	
    	}
    	cnt++;
    	if(j == n+1)break;
    	i = j-2;
   }
   cout << cnt << endl;
   return 0;
}
