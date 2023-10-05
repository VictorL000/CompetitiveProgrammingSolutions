#include <bits/stdc++.h>
using namespace std;
deque<long long> minN, minI;
int nums[200004];
long long psa[200004];
long long ans;
int N;
unsigned int K;

int main(){
	scanf("%d%d", &N, &K);
	long long sum = 0;
	for(int i = 1; i <= N; i++){
		int a;
		scanf("%d", &a);
		nums[i] = a;
		nums[i+N] = a;
	}
	for(int i = 1; i <= 2*N; i++){
		sum += nums[i];
		psa[i] = sum;
	}
	//for(int i = 1; i <= 2*N; i++)
	//	cout << psa[i] << " ";
	//cout << "\n";
	minN.push_front(0);
	minI.push_front(0);
	for(int r = 1; r <= 2*N; r++){
		long long pushed = psa[r];
		
		long long minNum = minN.back();
	//	cout << pushed << "-" << minNum << " = " <<pushed-minNum << "\n";
		if(!minI.empty()){	
			//cout << " ---> " << minI.back() << " - " << r <<"\n";
		}
		ans = max(ans, pushed-minNum);
	
		while(!minN.empty() && minN.front() >= pushed){
			//cout << minN.back() << " POPPED!\n";
			minN.pop_front();
			minI.pop_front();

		}
		
		minN.push_front(pushed);
		minI.push_front(r);
		//cout << pushed << " PUSHED!\n";

		if(!minI.empty() && r-minI.back() + 1> K){
			minI.pop_back();
			minN.pop_back();
		}

	}	
	cout << ans;
}