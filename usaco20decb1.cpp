#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int an[9];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int abc = 0;
	for(int i = 0; i < 7; i++){
		int a;
		cin >> a;
		an[i] = a;
		if(a > abc)abc = a;
	}
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 7; j++){
			for(int t = 0; t < 7; t++){
				if(i != j && i != t && j != t){
					if(an[i] + an[j] + an[t] == abc){
						vector<int> pq;
						pq.push_back(an[i]);
						pq.push_back(an[j]);
						pq.push_back(an[t]);
						sort(pq.begin(), pq.end());
						cout << pq[0] << " " << pq[1] << " " << pq[2];
						return 0;
					}
				}
			}
		}	
	}
}