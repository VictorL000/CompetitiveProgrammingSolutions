#include <bits/stdc++.h>
using namespace std;
int N, ans, maxFactor;
bool compositeN[200001];
void clear(int i ){
	int n = 1;
	while(n*i <= 200001){
		compositeN[n*i] = true;
		n++;
	}
}
int main(){
	cin >> N;
	compositeN[1] = true;
	for(int i = 2; i <= 200001; i++){
		if(compositeN[i] == false){
		       clear(i);	
		       compositeN[i] = false;
		}
	}
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		for(int j = a; j > 0; j--){
			if(!compositeN[j] && a%j == 0){
				if(j > maxFactor){
					maxFactor = j;
					ans = a;
					break;
				}
			}
		}
	}
	cout << ans << "\n";
}