#include "bits/stdc++.h"
using namespace std;
long long N, M;
int main(){
	cin >> N >> M;
	cout << 1LL * N*M-( M + N - 1 );
}