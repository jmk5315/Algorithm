#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define MAX 987654321

using namespace std;

int visit[50005] ={0,};
vector <vector <pair<int,int> > > adj(50005);
vector <pair <int,int > > ans;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    for(int i = 0;i < paths.size();i++){
        int a = paths[i][0];
        int b = paths[i][1];
        int c = paths[i][2];
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    priority_queue <pair <int,int> >pq;
    for(int i = 0;i<gates.size();i++){
        pq.push(make_pair(0,gates[i]));   
        visit[gates[i]] = 1;
    }
    for(int i = 1;i < n+1;i++){
        if(visit[i] == 1){
            visit[i] = 0;
        }
        else{
            visit[i] = MAX;
        }
    }
    while(!pq.empty()){
        int now = pq.top().second;
        int inten = -pq.top().first;
        pq.pop();
        for(auto vertex : adj[now]){
            int check = 0;
            int next = vertex.first;
            int len = vertex.second;
            if(visit[next] <= max(len,inten)){
                continue;
            }
            for(int i = 0;i < summits.size();i++){
                if(next == summits[i]){
                    ans.push_back(make_pair(next,max(inten,len)));
                    visit[next] = max(inten,len);
                    check = 1;
                    break;
                }
            }
            if(check == 0){
                pq.push(make_pair(-max(len,inten),next));
                visit[next] = max(len,inten);
            }
        }
    }
    int min = ans[0].second;
    int summit = ans[0].first;
    for(int i = 1;i < ans.size();i++){
        if(min > ans[i].second){
            min = ans[i].second;
            summit = ans[i].first;
        }
        else if(min == ans[i].second){
            if(summit > ans[i].first){
                summit = ans[i].first;
            }
            
        }
    }
    
    answer.push_back(summit);
    answer.push_back(min);

    

    
    return answer;
}