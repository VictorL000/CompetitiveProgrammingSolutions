#include <bits/stdc++.h>
using namespace std;
int N, M, T;
int matrix[302][302];
int main(){
	cin >> N >> M >> T;
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			matrix[i][j] = 99999999;
		}
		matrix[i][i] = 0;		
	}
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		matrix[a][b] = c;

	}
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(matrix[i][j] > max(matrix[i][k], matrix[k][j]))
					matrix[i][j] = max(matrix[i][k], matrix[k][j]);
			}
		}
	}
	for(int i = 0; i < T; i++){
		int a, b;
		cin >> a >> b;
		if(matrix[a][b] == 99999999)cout << "-1\n";
		else cout << matrix[a][b] << "\n";
	}

}