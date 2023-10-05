#include <bits/stdc++.h>
using namespace std;
int N, L, R, layer;
double Y;
map<int, int> ans;
bool cmp(pair<double, int> a, pair<double,int> b){
	if(a.first > b.first)
		return true;
	if(a.first == b.first)
		return (a.second < b.second);
	return false;
}
priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(&cmp)> qu (cmp);
int main(){
	cin >> N >> L >> R >> Y;
	for(int i = 0; i< N; i++){
		double x, v, h;
		cin >> x >> v >> h;
		qu.push(make_pair( (Y*h)/v + x,1));
		qu.push(make_pair( (-Y*h)/v + x,0));
	}
	qu.push(make_pair(R, 0));
	pair<double, int> last = make_pair(L, 1);
	while(!qu.empty()){
		pair<double, int> event = qu.top();
		qu.pop();
	 	//cout << event.first << ":"<<last.first << " " << layer << " " << last.second << "-" << event.second << " \n";	
		if( event.first == L )
			;
		if(event.first >= L){
			if(last.second == 1){ //include last
				if(event.second == 0)
		  			ans[layer] += 1+(floor(event.first) - last.first);   
				else
					ans[layer] += (ceil(event.first) - last.first);
			}
			if(last.second == 0){ //dont include; starting new range
				if(event.second == 0) // dont include event
		  			ans[layer] +=floor(event.first) - last.first;   
				else{
					ans[layer] +=  max(0.0, -1 +ceil(event.first) - last.first);
				} //include event
			}
			if(event.second == 1)last = make_pair(ceil(event.first), 1);
			else last = make_pair(floor(event.first), 0);
			if(event.first == R && event.second == 0){ //end;
				break;
			}
		}
		if(event.second == 0)layer++;
		if(event.second == 1)layer--;
	}
	int sum = 0;
	for(int i = 0; i <= N; i++){
		sum += ans[i];
		cout << sum << "\n";
		
	}
}