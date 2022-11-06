#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int x[8] = {0,1,0,-1};
int y[8] = {1,0,-1,0};
char arr[5][5];
int check = 1;
int visit[5][5] = {0,};


void bfs(int n, int m, int cnt){
    queue <pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(n,m),cnt));
    while(!q.empty()){
        int nx = q.front().first.first;
        int ny = q.front().first.second;
        int count = q.front().second;
        q.pop();
        if(count < 2){
            for(int i = 0;i < 4;i++){
                int dx = nx + x[i];
                int dy = ny + y[i];
                if(dx >= 0 && dx < 5 && dy >= 0 && dy < 5 && visit[dx][dy] != 1){
                    if(arr[dx][dy] == 'P'){
                        check = 0;
                    }
                    else if(arr[dx][dy] == 'O'){
                        q.push(make_pair(make_pair(dx,dy),count+1));
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0;i < places.size();i++){
        check = 1;
        for(int j = 0;j < places[i].size();j++){
            for(int k = 0;k < places[i][j].size();k++){
                arr[j][k] = places[i][j][k];
                visit[j][k] = 0;
            }
        }
        for(int j = 0;j < 5;j++){
            for(int k = 0;k < 5;k++){
                if(arr[j][k] == 'P'){
                    visit[j][k] = 1;
                    bfs(j,k,0);
                }
            }
        }
        answer.push_back(check);
    }
    return answer;
}