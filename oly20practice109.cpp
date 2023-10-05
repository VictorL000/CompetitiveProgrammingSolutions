#include "bits/stdc++.h"
using namespace std;
int N;
vector<pair<int, string> > names;

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		string a;
		int b;
		cin >> a >> b;
		names.push_back({ b, a });
	}
	sort(names.begin(), names.end());
	cout << names[N/2].second << "\n";	
}