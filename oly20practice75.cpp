#include <bits/stdc++.h>
using namespace std;
int N, M, lights[100002];
int main(){
	cin >> N >> M;
	for(int i = 0; i< M; i++){
		int L, R;
		cin >> L >> R;
		lights[L]++;
		lights[R+1]--;
	}
	int sum = 0;
	int ans = 0;
	for(int i = 0; i < N; i++){
		sum += lights[i];
		lights[i] = sum;
		if(sum %2 == 1)ans++;
		
	}
	cout << ans;
}