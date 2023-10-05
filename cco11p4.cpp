#include <bits/stdc++.h>
using namespace std;
int N, ranks[100005];
map<int, bool> vis;
set<int> visSet;
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> ranks[i];
	}
	for(int i = N-1; i >= 0; i--){
		vis[ranks[i]] = true;
		auto underling = vis.upper_bound(ranks[i]);
		if(underling == vis.end()){ //does not exist
	       		continue;
		}
		if(underling != vis.end()){ //take
			//i can only have one underling is the last element
			visSet.insert( underling->first );
	//		cout << underling -> first << " was chosen by " <<  ranks[i] <<"\n";
			auto underlingtwice = vis.upper_bound(underling -> first);
			if((underlingtwice) != vis.end()) {
				visSet.insert( underlingtwice->first );
	//			cout << underlingtwice -> first << " was chosen by " <<  ranks[i] <<"\n";
				vis.erase( underlingtwice ); //taken element will never be chosen again
			}	
			vis.erase( underling ); //taken element will never be chosen again
		}
	}
	cout << (((int)visSet.size()==N-1)?"YES":"NO");
}