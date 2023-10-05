#include <bits/stdc++.h>
int N, cutoff;
using namespace std;

int main(){
	cin >> N >> cutoff;
	for(int i = 0; i < N; i++){
		string name;
		int score;
		cin >> name >> score;
		if(score > cutoff)
			cout << name << " will advance\n";
		else cout << name << " will not advance\n";
	}
}