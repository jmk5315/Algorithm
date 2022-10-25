#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>
#include <cmath>

#define MAX 987654321

using namespace std;
typedef long long ll;

int dist[20005] ={0,};
vector< vector <pair <int, int> > > adj(20005);


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int v,e;
    cin >> v >> e;
    int start;
    cin >> start;
    for(int i = 0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
    }
    for(int i = 1;i < v+1;i++){
        if(i == start){
            dist[i] = 0;
        }
        else{
            dist[i] = MAX;
        }
    }
    priority_queue<pair <int,int> > pq;
    pq.push(make_pair(dist[start],start));
    while(!pq.empty()){
        int val = -pq.top().first;
        int pre = pq.top().second;
        pq.pop();
        if(dist[pre] < val){
            continue;
        }
        for(auto next : adj[pre]){
            int v2 = next.second;
            int p2 = next.first;
            if(dist[pre] + v2 < dist[p2]){
                dist[p2] = dist[pre] + v2;
                pq.push(make_pair(-(dist[p2]),p2));
            }
        }
    }
    for(int i = 1;i < v+1;i++){
        if(dist[i] == MAX){
            cout << "INF" << "\n";
        }
        else{
            cout << dist[i] << "\n";
        }
    }

    
}