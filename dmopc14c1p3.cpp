#include <bits/stdc++.h>

using namespace std;

int main(){

	double sum = 0;
	double I;
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> I;

	for(int i = 0; i < I; i++){
		int g;
		cin >> g;
		sum += g;
	}
	
	int S;

	cin >> S;

	for(int i = 0; i < S; i ++){
		int g;
		cin >> g;
		sum += g;
		I++;
		printf("%.3f\n", (sum/I));
	}
}