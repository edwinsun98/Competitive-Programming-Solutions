#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
double delta(ll x){
	ll c = x, s = 0;
	while( c> 0){
	 	s += c%10; c/= 10;
	}
	return (double)1.0*x/s;
}
int main(){
	int ub = 100, cnt = 0;
	cin >> ub;
	ll a = 0, b=1;
	for(int i = 0; i< ub; i++){
		if((a/b)%10 == 9 && delta(a+b) > delta(a+10*b))b*=10;
		a += b;
		cout <<a  << endl;
  	}
	return 0;
}
