#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, K, clubs[33], dist[6000];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	for(int i = 0; i < K; i++){
		int a;
		cin >> a;
		clubs[i] = a;
	}
	dist[0] = 1;
	for(int i = 0; i < N; i++){
		if(dist[i] != 0){
			for(int j = 0; j < K; j++){
				if(dist[i + clubs[j]] == 0)
					dist[i + clubs[j]] = dist[i] +1;
				else dist[i + clubs[j]] = min( dist[i + clubs[j]], dist[i] + 1 );
			}
		}
	}
	if(dist[N] == 0)cout << "Roberta acknowledges defeat.\n";
	else cout << "Roberta wins in " << dist[N]-1 << " strokes.\n";
}