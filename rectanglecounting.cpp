#include <bits/stdc++.h>
using namespace std;
//priority_queue<int, vector<int>, greater<int> > leftCorner, rightCorner;
//map<pair<int, int>, queue<pair<int, int> > > corrospondingl, corrospondingr;
struct rect{
	int x, ylo, yhi;
	bool closing;
};
bool rectSort(rect a, rect b){
	bool ret = a.x < b.x;
	if(a.x == b.x){
		ret = a.closing;
	}
	return ret;
}
vector<rect> rectangles;

long long bitB[1000009], bitT[1000009], nums[1000000], ans;
int N;
int maxn = 1e6;
void updateT(int idx, int a){
	while(idx <= maxn){
		bitT[idx] += a;
		idx += idx & (-idx);
	}
}

void updateB(int idx, int a){
	while(idx <= maxn){
		bitB[idx] += a;
		idx += idx & (-idx);
	}
}
int queryT(int a){
	int sum = 0;
	while(a > 0){
		sum += bitT[a];
		a -= a & (-a);
	}
	return sum;
}
int queryB(int a){
	int sum = 0;
	while(a > 0){
		sum += bitB[a];
		a -= a & (-a);
	}
	return sum;
}

int queryT(int a, int b){
	if(a > b)
		return 0;
	int sum = queryT(b) - queryT(a-1);
	return sum;
}
int queryB(int a, int b){
	if(a > b)
		return 0;
	int sum = queryB(b) - queryB(a-1);
	return sum;
}

pair<int, int> getCornerL(pair<int, int> a, pair<int, int> b){
	pair<int, int> corner = make_pair(a.first, b.second);
	return corner;
}
pair<int, int> getCornerR(pair<int, int> a, pair<int, int> b){
	pair<int, int> corner = make_pair(b.first, a.second);
	return corner;
}

int main(){
	
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		rect temp = {a, b, d, false};
		rect temp2 = {c, b, d, true};
		rectangles.push_back(temp);
		rectangles.push_back(temp2);
	}
	sort(rectangles.begin(), rectangles.end(), rectSort);
	for(int i = 0; i < 2*N; i++){
		rect r = rectangles[i];
		//cout << left << " vs " << right << "\n";
		if(rectangles[i].closing){
			ans += queryB(r.yhi-1) - queryT(r.ylo) - 1;
			updateB(r.ylo, -1);
			updateT(r.yhi, -1);
			nums[r.ylo] -= 1;
			nums[r.yhi] -= 1;
		}
		else{
			updateB(r.ylo, 1);
			updateT(r.yhi, 1);
			nums[r.ylo] += 1;
			nums[r.yhi] += 1;
		}
		/*
		if(leftCorner.empty() || left >= right){//ending rect
			cout << "end " << rightCorner.top().first << ":"<<rightCorner.top().second << " and " << corrospondingr[rightCorner.top()].front().first << ":" << corrospondingr[rightCorner.top()].front().second << "\n";
			ans += query(1 + min(rightCorner.top().second, corrospondingr[rightCorner.top()].front().second),
				     max(rightCorner.top().second, corrospondingr[rightCorner.top()].front().second) - 1);
			update(rightCorner.top().second, -1);
			update(corrospondingr[rightCorner.top()].front().second, -1);
			nums[rightCorner.top().second] -= 1;
			nums[corrospondingr[rightCorner.top()].front().second] -= 1;
			corrospondingr[rightCorner.top()].pop();
			rightCorner.pop();
		}

		
		else{ //starting new rect
			cout << "start " << leftCorner.top().first << ":"<<leftCorner.top().second << " and " << corrospondingl[leftCorner.top()].front().first << ":" <<  corrospondingl[leftCorner.top()].front().second << "\n";
			ans += query(1 + min(leftCorner.top().second, corrospondingl[leftCorner.top()].front().second),
				     max(leftCorner.top().second, corrospondingl[leftCorner.top()].front().second) - 1);
			update(leftCorner.top().second, 1);
			update(corrospondingl[leftCorner.top()].front().second, 1);
			nums[leftCorner.top().second] += 1;
			nums[corrospondingl[leftCorner.top()].front().second] += 1;
			corrospondingl[leftCorner.top()].pop();
			leftCorner.pop();
		}*/
	//	cout << ans<< "\n";
	}
	cout << ans;

//	while(true){
//	int a, b;
//		cin >> a >> b;
//		cout << corrospondingl[make_pair(a, b)].front().first << ":" << corrospondingl[make_pair(a, b)].front().second << "\n";
//		cout << corrospondingr[make_pair(a, b)].front().first << ":" << corrospondingr[make_pair(a, b)].front().second << "\n";
//	}
	
}