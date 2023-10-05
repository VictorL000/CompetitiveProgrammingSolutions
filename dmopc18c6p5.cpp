#include <bits/stdc++.h>
using namespace std;
struct event{
	int type; //0 for start 1 for goose 2 for end
	int r, c, r1, c1, id;
	int left, right, up, down;

};
bool lrCompare(event e1, event e2){
	if(e1.r != e2.r)return (e1.r > e2.r);
	return (e1.type > e2.type);
}
bool tbCompare(event e1, event e2){
	if(e1.c != e2.c)return (e1.c > e2.c);
	return (e1.type > e2.type);
}
int N, M, K, Q, T, segtree[3000006], lz[3000006], bestGeese[100005];
long long ans;
vector<pair<int, int>> gooseO;
vector<pair<int, int>> quadO, quadOE;
priority_queue<int, vector<int>, greater<int>> pq;
unordered_map<int, int> lookup;
priority_queue<event, vector<event>, function<bool(event, event)>> tb(lrCompare), lr(tbCompare);

void update(int idx, int l, int r, int ul, int ur, int x){
	if(l < 0)cout << " l is less than 0 ????";

	if(lz[idx] != 0){
		segtree[idx] += lz[idx];
		//need to push to children
		if(l != r){
			lz[idx*2] += lz[idx];
			lz[idx*2+1] += lz[idx];
		}
		//if(l != (l+r)/2)lz[idx*2] = lz[idx];
		//if(r != 1+(l+r)/2)lz[idx*2+1] = lz[idx];
		
		//segtree[2*idx+1] += lz[idx];
		//segtree[2*idx] += lz[idx]; 

		lz[idx] = 0;
	}

	if(l > ur || r < ul)return;

	//if(l == r){ // at leaf node
	//	segtree[idx] += x;	       
	//	return;
	//}

	if(l >= ul && r <= ur){ //range is completely within query range and not leaf
		//update lz
		segtree[idx] += x;
		if(l != r){
			lz[idx*2] += x;
			lz[idx*2+1] += x;
		}
		//lz[idx] += x;	
		return;
	}		
	
	int mid = (l + r)/2;
	update(2*idx, l, mid, ul, ur, x);
	update(2*idx+1, mid+1, r, ul, ur, x);
	segtree[idx] = max(segtree[2*idx], segtree[2*idx+1]);
 
}
int query(int idx, int l, int r, int ul, int ur){
	if(l < 0)cout << " l is less than 0 ????";

	if(lz[idx] != 0){
		segtree[idx] += lz[idx];
		//need to push to children
		if(l != r){
			lz[idx*2] += lz[idx];
			lz[idx*2+1] += lz[idx];
		}
		//if(l != (l+r)/2)lz[idx*2] = lz[idx];
		//if(r != 1+(l+r)/2)lz[idx*2+1] = lz[idx];
		
		//segtree[2*idx+1] += lz[idx];
		//segtree[2*idx] += lz[idx]; 

		lz[idx] = 0;
	}
	if(l > ur || r < ul)return 0;
	if(l >= ul && r <= ur){
		return segtree[idx];
	}
	if(l == r){
		cout << "ERROR LEAF NODE GOT PAST CHECKS";
		return 0;
	}
	int mid = (l+r)/2;
	return max(query(2*idx, l, mid, ul, ur), query(2*idx+1, mid+1, r, ul, ur));
}
int main(){
//	update(1, 1, 6, 2, 6, 1);
//	update(1, 1, 6, 3, 5, 1);
//	cout << query(1, 1, 6, 2, 4);
	/*
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b, c, d;;
		cin >> a >> b >> c >> d;;
		
		if(a == 0){
			update(1, 1, 12 ,b, c, d);
			for(int i = 0; i < 25; i++){
				cout << segtree[i] << " ";
			}	
			cout << "\n";
			for(int i = 0; i < 25; i++){
				cout << lz[i] << " ";
			}	
			cout << "\n";
		}
		else cout << query(1, 1, 12, b ,c) << "\n";
	}
	return 0;
	*/
	cin >> N >> M >> K >> Q >> T;
	for(int i = 0; i < K; i++){
		int a, b;
		cin >> a >> b;
		gooseO.push_back(make_pair(a, b));
		pq.push(a+T);
		pq.push(a-T);
		pq.push(b+T);
		pq.push(b-T);
		pq.push(a);
		pq.push(b);
		
	}
	for(int i = 0; i < Q; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		quadO.push_back(make_pair(a, b));
		quadOE.push_back(make_pair(c, d));
		pq.push(a);
		pq.push(b);
		pq.push(c);
		pq.push(d);
	}
	pq.push(2010000000);
	int inc = 1;
	while(!pq.empty()){
		int a = pq.top();
		pq.pop();
		if(lookup[a] != 0){
			continue;
		}
		lookup[a] = inc;
		//cout << a << ": " << inc << "\n";
		inc++;
	}

	for(int i = 0; i < K; i++){
		event goose;
		goose.type = 1;
		goose.id = i;
		goose.r = lookup[gooseO[i].first];
		goose.c = lookup[gooseO[i].second];
		goose.left = lookup[gooseO[i].second-T];
		goose.right = lookup[gooseO[i].second+T];
		goose.up = lookup[gooseO[i].first-T];
		goose.down = lookup[gooseO[i].first+T];
		lr.push(goose);
		tb.push(goose);
	}
	for(int i = 0; i < Q; i++){
		event quad;
		quad.type = 0;
		quad.r = lookup[quadO[i].first];
		quad.c = lookup[quadO[i].second];
		quad.r1 = lookup[quadOE[i].first];
		quad.c1 = quad.c;
		lr.push(quad);
		quad.r1 = quad.r;
		quad.c1 = lookup[quadOE[i].second];
		tb.push(quad);

		event quadend;
		quadend.type = 2;
		quadend.r1 = lookup[quadOE[i].first];
		quadend.c1 = lookup[quadOE[i].second];
		quadend.r = lookup[quadO[i].first];
		quadend.c = quadend.c1;
		lr.push(quadend);
		quadend.r = quadend.r1;
		quadend.c = lookup[quadO[i].second];
		tb.push(quadend);
	}
	while(!lr.empty()){
		event e = lr.top();
		lr.pop();
		if(e.type == 0){
			update(1, 1,lookup[2010000000], e.r, e.r1, 1);
		}
		if(e.type == 1){
			bestGeese[e.id] = query(1, 1, lookup[2010000000], e.up, e.down);
		//	cout << bestGeese[e.id] << " \n";
		}
		if(e.type == 2){
			update(1,1, lookup[2010000000], e.r, e.r1, -1);
		}
		
		if(e.type == 0){
		//	cout << "Begin quad at " << e.r << ":" << e.c << " to " << e.r1 << ":"<<e.c1 << "\n";
		}
		if(e.type == 1){
		//	cout << "Goose at " << e.r << ":"<<e.c<<" that can fly from " << e.up << " to " << e.down << "\n"; 
		}
		if(e.type == 2){
		//	cout << "End quad at " << e.r << ":" << e.c << " to " << e.r1 << ":"<<e.c1 << "\n";
		}
	}
	memset(segtree, 0, sizeof(segtree));
	memset(lz, 0, sizeof(lz));

	while(!tb.empty()){
		event e = tb.top();
		tb.pop();
		if(e.type == 0){
			update(1, 1,lookup[2010000000], e.c, e.c1, 1);
		}
		if(e.type == 1){
			int a = query(1, 1, lookup[2010000000], e.left, e.right);
			ans += max(bestGeese[e.id], a); 
		//	cout << a<< " \n";
		}
		if(e.type == 2){
			update(1,1, lookup[2010000000], e.c, e.c1, -1);
		}
		
		if(e.type == 0){
		//	cout << "Begin quad at " << e.r << ":" << e.c << " to " << e.r1 << ":"<<e.c1 << "\n";
		}
		if(e.type == 1){
		//	cout << "Goose at " << e.r << ":"<<e.c<<" that can fly from " << e.left << " to " << e.right << ", originally " << gooseO[e.id].second - T<< " to " << gooseO[e.id].second + T<< "\n";
		}
		if(e.type == 2){
		//	cout << "End quad at " << e.r << ":" << e.c << " to " << e.r1 << ":"<<e.c1 << "\n";
		}
	}
	cout << ans;
}