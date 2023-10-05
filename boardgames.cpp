#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
const ll MM = 40000005;
int a, b, cur, dis[MM];
bool vis[MM];
queue<int> q;
 
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    q.push(a); 
    vis[a] = true; 
    dis[a] = 0;         //dis[i] is 0 by default if you declare outside of main
    while (!q.empty()){
        cur = q.front(); 
        q.pop();
        if (3*cur <= 10000000 && vis[cur * 3] == false){
            vis[cur * 3] = true; 
            dis[cur * 3] = dis[cur] + 1; 
            q.push(cur * 3);
            if (cur * 3 == b) break;
        }
        if (cur > 1 && vis[cur - 1] == false){
            vis[cur - 1] = true; 
            dis[cur - 1] = dis[cur] + 1; 
            q.push(cur - 1);
            if (cur - 1 == b) break;
        }
        if (cur > 3 && vis[cur - 3] == false){
            vis[cur - 3] = true; 
            dis[cur - 3] = dis[cur] + 1; 
            q.push(cur - 3);
            if (cur - 3 == b) break;
        }
        if (cur % 2 == 0 and vis[cur / 2] == 0){
            vis[cur / 2] = true; 
            dis[cur / 2] = dis[cur] + 1; 
            q.push(cur / 2);
            if (cur / 2 == b) break;
        }
    }
    cout << dis[b] << "\n";
}