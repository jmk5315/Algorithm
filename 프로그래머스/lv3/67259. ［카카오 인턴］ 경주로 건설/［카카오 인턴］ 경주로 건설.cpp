#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int arr[30][30] = {0,};
int cost[30][30][2] = {0,};
int x[4] = {0,1,0,-1};
int y[4] = {1,0,-1,0};
int k;


void bfs(){
    queue<pair<pair<int,int>,int> > q;
    if(arr[0][1] == 0){
        q.push(make_pair(make_pair(0,1),0));
    }
    if(arr[1][0] == 0){
        q.push(make_pair(make_pair(1,0),1));
    }
    while(!q.empty()){
        int nx = q.front().first.first;
        int ny = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        for(int i = 0; i < 4;i++){
            int dx = nx + x[i];
            int dy = ny + y[i];
            if(dx >= 0 && dx < k && dy >= 0 && dy < k ){
                if(arr[dx][dy] == 0){
                    if(dir == 0){
                        if(x[i] == 0){
                            if(cost[dx][dy][0] >= cost[nx][ny][0] + 1){
                                cost[dx][dy][0] = cost[nx][ny][0] + 1;
                                q.push(make_pair(make_pair(dx,dy),0));
                            }   
                        }
                        else{
                            if(cost[dx][dy][1] >= cost[nx][ny][0] + 6){
                                cost[dx][dy][1] = cost[nx][ny][0] + 6;
                                q.push(make_pair(make_pair(dx,dy),1));
                            } 
                        }
                    }
                    else{
                        if(y[i] == 0){
                            if(cost[dx][dy][1] >= cost[nx][ny][1] + 1){
                                cost[dx][dy][1] = cost[nx][ny][1] + 1;
                                q.push(make_pair(make_pair(dx,dy),1));
                            }   
                        }
                        else{
                            if(cost[dx][dy][0] >= cost[nx][ny][1] + 6){
                                cost[dx][dy][0] = cost[nx][ny][1] + 6;
                                q.push(make_pair(make_pair(dx,dy),0));
                            } 
                        }
                    }
                }
            }
        }
    }
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    int n;
    k = board.size();
    for(int i = 0;i < board.size();i++){
        for(int j = 0;j < board[i].size();j++){
            arr[i][j] = board[i][j];
            cost[i][j][0] = 99999;
            cost[i][j][1] = 99999;
        }
    }
    cost[0][0][0] = 0;
    cost[0][0][1] = 0;
    cost[1][0][1] = 1;
    cost[0][1][0] = 1;
    bfs();
    if(cost[k-1][k-1][0] > cost[k-1][k-1][1]){
        answer = cost[k-1][k-1][1] * 100;
    }
    else{
        answer = cost[k-1][k-1][0] * 100;
    }
    return answer;
}