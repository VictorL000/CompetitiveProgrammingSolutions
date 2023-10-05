#include <bits/stdc++.h>
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int M, N, S;
int firstRow[2004];
int firstCol[2004];
double ans;
string s;
int main(){
	scanf("%d%d%d", &M, &N, &S);
	for(int i = 0; i <= N-S; i++){
		for(int j = 0; j < S; j++){
			firstRow[i+j]++;
		}
	}
	for(int i = 0; i <= M-S; i++){
		for(int j = 0; j < S; j++){
			firstCol[i+j]++;
		}
	}
	cout << '\n';
	for(int i = 0; i< M; i++){
		cin >> s;
		for(int j = 0; j < N; j++){
			if(s[j] == 'X'){
				ans += firstCol[i] * firstRow[j];
			}
		}
	}
	printf("%.9f", ans/( (M+1-S)*(N+1-S) ));
}