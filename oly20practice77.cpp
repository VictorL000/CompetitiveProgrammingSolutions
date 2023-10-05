#include <bits/stdc++.h>
using namespace std;
int N;
int lr[300001], psa[300001], ans;
string s;
int main(){
	cin >> N;
	ans = 300004;
	cin >> s;
	for(unsigned long i = 0; i < s.length(); i++){
		if(s[i] == 'L'){
			lr[i] = 0;
		}
		else{
			lr[i] = 1;
		}
	}
	psa[0] = lr[0];
	for(int i = 1; i< N; i++)
		psa[i] = psa[i-1] + lr[i];
	for(int i = 0; i < N; i++){
		if(i == 0)
			ans = min(ans, psa[N-1]-psa[0]);
		if(i == N-1)
			ans = min(ans, N - 1 - psa[N-2]);
		else
			
			ans = min(ans, (i -psa[i-1]) + (psa[N-1] - psa[i]));
		if(ans == 0)cout << i << "\n";
	}
	cout << ans;
}