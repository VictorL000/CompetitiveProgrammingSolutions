#include <bits/stdc++.h>
using namespace std;
int W, H, N, ans;
int cake[302][302];
int query(int a, int b, int c, int d){
	return (cake[c][d] - cake[c][b-1] - cake[a-1][d] + cake[a-1][b-1]);
}
int main(){
	cin >> W >> H >> N;
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			int a;
			cin >> a;
			cake[i][j] = a;
		}
	}
	for(int i = 0; i<= 300; i++){
		int sum = 0;
		for(int j = 0; j <= 300; j++){
			sum += cake[i][j];
			cake[i][j] = sum;	
		}
	}
	for(int i = 0; i<= 300; i++){
		int sum = 0;
		for(int j = 0; j <= 300; j++){
			sum += cake[j][i];
			cake[j][i] = sum;

		}
	}
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			for(int k = i; k <= min(H, i+N); k++){
				int qu = query( i, j, k, min(W, j + N/(k-i+1) - 1 ) );
				ans = max(ans, qu);
			}
		}
 	}
	cout << ans;
}