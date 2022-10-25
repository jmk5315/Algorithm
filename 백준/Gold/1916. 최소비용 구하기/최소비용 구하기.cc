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

int dist[1005] ={0,};
vector< vector <pair <int, int> > > adj(1005);


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
    }
    int start,end;
    cin >> start >> end;
    for(int i = 1;i <= n;i++){
        if(i == start){
            dist[i] = 0;
        }
        else{
            dist[i] = MAX;
        }
    }
    priority_queue <pair <int,int> > pq;
    pq.push(make_pair(dist[start],start));
    while(!pq.empty()){
        int value = -pq.top().first;
        int present = pq.top().second;
        pq.pop();
        if(dist[present] < value){
            continue;
        }
        for(auto next : adj[present]){
            int p2 = next.first;
            int v2 = next.second;
            if((dist[present] + v2) < dist[p2]){
                pq.push(make_pair(-(v2+dist[present]),p2));
                dist[p2] = v2+dist[present];
            } 
        }
    }
    cout << dist[end];
    
}