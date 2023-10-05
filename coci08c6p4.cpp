#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

queue<int> bag0, bag1, bag2;
deque<int> dq;
int N;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		if(a%3 == 0)bag0.push(a);
		if(a%3 == 1)bag1.push(a);
		if(a%3 == 2)bag2.push(a);
	}
	if(!bag0.empty()){
		dq.push_front(bag0.front());
		bag0.pop();
	}
	else{
		if(bag2.empty()){
			while(!bag1.empty()){
				cout << bag1.front() << " ";
				bag1.pop();
			}
		}
		else if(bag1.empty()){
			while(!bag2.empty()){
				cout << bag2.front() << " ";
				bag2.pop();
			}
		}
		else{
			cout << "impossible";
		}
		cout << '\n';
		return 0;
	}
	if(bag0.size() > 1 + bag1.size() + bag2.size() ){
		cout << "impossible\n";
		return 0;
	}
	for(int i = 1; i < N; i++){
		if(dq.front()%3 == 1 && !bag0.empty()){
//			cout << "a";
			dq.push_front(bag0.front());
			bag0.pop();
		}
		else if(dq.front()%3 != 2 && !bag1.empty()){
//			cout << "b";
			dq.push_front(bag1.front());
			bag1.pop();
		}
		else if(dq.back()%3 == 2 && !bag0.empty()){
//			cout << "c";
			dq.push_back(bag0.front());
			bag0.pop();
		}
		else if(dq.back()%3 != 1 && !bag2.empty()){
//			cout << "d";
			dq.push_back(bag2.front());
			bag2.pop();
		}
		else{
			cout << "impossible\n";
			return 0;
		}
	}
	if((int)dq.size() == N){
		while(!dq.empty()){
			cout << dq.front() << " ";
			dq.pop_front();
		}
		cout << '\n';
	}
	else cout << "impossible\n";
}