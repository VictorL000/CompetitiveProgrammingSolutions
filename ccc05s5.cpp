//counting inversions
//very similar to bubble sort
//can use balenced binary search tree (level 5)
//can use merge sort
//can use bit (coordinate compression)
//similar to bit on frequency array
//get sum of left numbers and subtract from n to get nums less than a[i]


#include <bits/stdc++.h>
using namespace std;
vector <int> cmpr;
vector <int> ranks;
int t;
int bit[100003];
int in[1000003];
int lsb(int x){
	return (x & -x);
}	

int query(int a){
	int sum = 0;
	for(int i = a; i > 0; i -= lsb(i)){
		sum += bit[i];
	}
	return sum;
}

int query(int a, int b){
	return query(b) - query(a-1);
}

void update(int idx, int add){
	for(int i = idx; i < 100001; i+= lsb(i))
		bit[i]+=add;
}

int main(){
	
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int g; 
		scanf("%d", &g);
		cmpr.push_back(g);
	}

	for(int i = 0; i < cmpr.size(); i++){
//		cout << cmpr[i] << "\n";
	}


	vector<int> orig = cmpr;

	sort(cmpr.begin(), cmpr.end());


	for(int i = 0; i < t; i++){
		ranks.push_back(t-i);
	}
	double ans = 0.0;
	for(int i = 0; i < t; i++){
		int idx = lower_bound (cmpr.begin(), cmpr.end(), orig[i]) - cmpr.begin();
		int curRank = ranks[idx];
		update(curRank, 1);
		ans += 1+ query(1, curRank-1);
//		cout << idx << " ";	
	}
	printf("%.2f\n", (ans/t));
	//change priority queue to pair sort with number and index
	//or binary search or indices
	
	

}