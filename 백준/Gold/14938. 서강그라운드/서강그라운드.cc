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

int dist[105] ={0,};
int item[105] = {0,};
vector< vector <pair <int, int> > > adj(105);
int ans[105] = {0,};


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,r;
    cin >> n >> m >> r;
    for(int i = 1;i < n+1;i++){
        int t;
        cin >> t;
        item[i] = t;
    }
    for(int i = 1;i < r+1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < n+1;j++){
            if(i == j){
                dist[j] = 0;
            }
            else{
                dist[j] = MAX;
            }
        }
        priority_queue<pair <int,int> > pq;
        pq.push(make_pair(0,i));
        while(!pq.empty()){
            int v = -pq.top().first;
            int p = pq.top().second;
            pq.pop();
            if(dist[p] < v){
                continue;
            }
            for(auto next : adj[p]){
                int v2 = next.second;
                int p2 = next.first;
                if(v2 + dist[p] < dist[p2]){
                    dist[p2] = v2 + dist[p];
                    pq.push(make_pair(-dist[p2],p2));
                }
            }
        }
        for(int k = 1;k < n+1;k++){
            if(m >= dist[k]){
                ans[i] += item[k];
            }
        }  

    }
    int mx = ans[1];
    for(int i = 2;i < n+1;i++){
        if(ans[i] > mx){
            mx = ans[i];
        }
    }
    cout << mx;

    
}