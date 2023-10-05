#include <bits/stdc++.h>
using namespace std;
long long nums[30];
int main(){
	set<int> ans;
	int N;
	int L;
	cin >> N >> L;
	N--;
	for(int i = 0; i < N; i++){
		string a= "";
		for(int j = 0; j < L; j++){
			char temp;
			cin >> temp;
			a+=temp;
		}
		nums[i] = bitset<8>(a).to_ullong();
	//	cout << nums[i] << "\n";
	}
	for(int i = 0; i < N; i++){
		int xsum = 0;
		for(int j = i; j < N; j++)
			xsum ^= nums[j];
		
		ans.insert(xsum);
	//	cout << xsum << " xsum \n";
	}
	string a= "";
	for(int j = 0; j < L; j++){
		char temp;
		cin >> temp;
		a+=temp;
	}
	ans.insert(bitset<8>(a).to_ullong());
	//	cout << nums[i] << "\n";
	cout << ans.size();

}