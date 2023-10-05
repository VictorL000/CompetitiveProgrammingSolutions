#include <bits/stdc++.h>
using namespace std;
int N, M, K,Q;
long long cake[5002][5002];
int main(){
	cin >> N >> M >> K;
	for(int i = 0; i < K; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cake[a][b]++;
		cake[a][d+1]--;
		cake[c+1][b]--;
		cake[c+1][d+1]++;
	}
	for(int i = 0; i< 5002; i++){
		long long sum = cake[i][0];
		for(int j = 0; j < 5002; j++){
			sum += cake[i][j];
			cake[i][j] = sum;	
		}
	}
	for(int i = 0; i< 5002; i++){
		long long sum = cake[0][i];
		for(int j = 0; j < 5002; j++){
			sum += cake[j][i];
			cake[j][i] = sum;	
		
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j <=N; j++){
	//		cout << cake[i][j] << " ";
		}
	//	cout << "\n";
	}
	for(int i = 0; i< 5002; i++){
		long long sum = cake[i][0];
		for(int j = 0; j < 5002; j++){
			sum += cake[i][j];
			cake[i][j] = sum;	
		}
	}
	for(int i = 0; i< 5002; i++){
		long long sum = cake[0][i];
		for(int j = 0; j < 5002; j++){
			sum += cake[j][i];
			cake[j][i] = sum;	
		
		}
	}
	cin >> Q;
	for(int i = 0; i < Q; i++){
		int a, b ,c, d;
		cin >> a >> b >> c >> d;

		cout << cake[c][d] - cake[c][b-1] - cake[a-1][d] + cake[a-1][b-1] << "\n";
		
	}
}