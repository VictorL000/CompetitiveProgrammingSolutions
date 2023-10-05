#include <bits/stdc++.h>
using namespace std;
int a, b, dp[1000000], n, factors[1000000];
set<int> fac;
int main(){
	n = 99999999;
	cin >> a >> b;
	int c = a;
	for(int i = 2; i <= (a); i++){
		//cout << i << " " << c << "\n";;
		if(c == 1 || c == 0)break;
		if(c%i == 0){
			factors[i]++;
			fac.insert(i);
	//		cout << c <<"%"<<i<<" == 0\n";
			c = c/i;
			i--;	
		}
	}
	for(auto f : fac){
		int temp = 0;
	//	cout << "f "<<f << "\n";
		memset(dp,0,  1000000);
		for(int i = f; i<= b; i+= f){
			if(f == 0)cout <<"ERR";
			if(i > b) break;
			temp+=1;
			temp+= dp[i/f];
			dp[i] = 1 + dp[i/f];
		//	cout << dp[i] << " ";
		}
	//	cout << temp << "\n";
		n = min(n, temp/ factors[f]);
	}
	cout << n;

}