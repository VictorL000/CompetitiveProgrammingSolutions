#include <bits/stdc++.h> 
using namespace std;
int n;
vector<long long> arSum;
vector<int> ar;

queue<int> freq;
vector<long long> freqSum;

long lsBit(long i){
	return ( i & (-i));
}

long long getSum(int i, long long sum, vector<long long>& sums){
	if( i <= 0)return sum;
	long g = getSum(i - lsBit(i), sum+ sums[i], sums);
	return g;
}

long long query(int a, int b, vector<long long>& sums){
	if( a > b)return 0;
	long long g = getSum(b, 0, sums) - getSum(a-1,0, sums);
	return g;
}

void update(int i, int add, vector<long long>& sums){
	
	if(i > 100000) return;
	sums[i] += add;
	update(i + lsBit(i), add, sums);
}
void updater(int i, int add){
	int diff = add-ar[i];
	update(ar[i], -1, freqSum);
	update(add, 1, freqSum);
	
//	freq[ar[i]]--;
//	freq[add]++;

	ar[i] = add;
	update(i, diff, arSum);
	
}
int main(){
	int ops;
	scanf("%d%d", &n, &ops);
//	scainf("%d", &ops);

	arSum.reserve(100005);
	ar.reserve(100005);
	
	freqSum.reserve(100005);


	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
		freq.push(ar[i]);
	}
//	printf("f");
	for(int i = 1; i <= n; i++){
		update(i, ar[i], arSum);
		update(freq.front(), 1, freqSum);	
		freq.pop();
	}
	
//	for(int i = 1; i <= n; i++)cout << freqSum[i] <<" ";

	for(int i = 0; i < ops; i++){
		char in[3];
//		for(int i = 1; i <= 25; i++)cout << freqSum[i] <<" ";
//		cout<<"\n";
//		for(int i = 1; i <= n; i++)cout << ar[i] <<" ";
		
//		cout<<"\n\n";
		scanf("%s", in);	

		int a;
		scanf("%d", &a);
		if(strcmp(in, "Q") == 0)cout << query(0, a, freqSum) << "\n";
		
		else{
			int b;
			scanf("%d", &b);

			if(strcmp(in, "S") == 0)cout << query(a, b, arSum) << "\n";
			if(strcmp(in, "C") == 0)updater(a, b);

		}
	}

}