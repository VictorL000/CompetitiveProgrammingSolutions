#include <bits/stdc++.h>
using namespace std;
int N, M, Q;
long long diff [5001*5001+1];
int main(){
	cin >> N >> M;
	for(int r = 1; r <=N; r++){
		for(int c = 1; c <=M; c++){
			diff[r*c]++;
			diff[(M * N) - (N-r+1) * (M-c+1) + 1 + 1]--;
		//	cout << r*c << ":" << (M*N)-(N-r+1)*(M-c+1)+1 << "   ";
		}
		cout << "\n";
	}
	
	for(int i = 1; i < 5001*5001+1; i++){
		diff[i] += diff[i-1];	
	}

	cin >> Q;
	for(int i = 0; i < Q; i++){
		int q;
		cin >> q;
		cout << diff[q] << "\n";
	}

}