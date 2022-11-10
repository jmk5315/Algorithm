#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;

int arr[51][51] = {0,};
int visit[51][51] = {0,};
int x[4] = {-1,0,1,0};
int y[4] = {0,-1,0,1};
int n,r,l;
int check = 0;

void bfs(int u,int c){
    queue<pair<int,int> > q;
    queue<pair<int,int> > storeq;
    q.push(make_pair(u,c));
    storeq.push(make_pair(u,c));
    visit[u][c] = 1;
    int total = arr[u][c];
    int cnt = 1;
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int dx = xx + x[i];
            int dy = yy + y[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < n){
                if(visit[dx][dy] == 0){
                    int tmp = abs(arr[xx][yy]-arr[dx][dy]);
                    if(tmp >= l && tmp <= r){
                        q.push(make_pair(dx,dy));
                        storeq.push(make_pair(dx,dy));
                        total += arr[dx][dy];
                        cnt += 1;
                        visit[dx][dy] = 1;
                    }
                }
            }
        }
    }
    if(cnt > 1){check = 1;}
    while(!storeq.empty()){
        int nx = storeq.front().first;
        int ny = storeq.front().second;
        storeq.pop();
        arr[nx][ny] = total / cnt;
    }
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> l >> r;
    for(int i= 0;i< n;i++){
        for(int j = 0;j< n;j++){
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    int ans = 0;
    while(1){
        check = 0;
        memset(visit,0,sizeof(visit));
        for(int i = 0;i<n;i++){
            for(int j = 0;j < n;j++){
                if(visit[i][j] == 0){
                    bfs(i,j);
                }
            }
        }
        if(check == 1){
            ans += 1;
        }
        else{
            break;
        }
    }
    
    cout << ans;
    
}