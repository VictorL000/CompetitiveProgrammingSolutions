#include <bits/stdc++.h>
//for full answer, jump by 3/2 n numbers instead of 1, use for loop
using namespace std;

int main(){
	int n, k, cur, next;
	scanf("%d%d", &n, &k);

	int ar[3200][3200];

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	for(cur = 1, next = 2; next <= k; cur = next, next *= 1.5){
		int d = next-cur;
		for(int i = 1; i <= n - cur; i++){
			for(int j = 1; j <= i; j++){
				ar[i][j] = max(max(ar[i][j], ar[i+d][j]), ar[i+d][j+d]);
			}
		}
	}
	long long ans = 0;
	//get answer
	int dist = k - cur;
	
	for(int i = 1; i <= n - k + 1; i++){
		for(int j = 1; j <= i; j++)ans += max(ar[i][j], max(ar[i+dist][j], ar[i+dist][j+dist]));
	}
	cout << ans << "\n";
/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cout << ar[i][j] << " ";
		}
		cout << "\n";

	}
*/
}