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

int arr[101][101] = {0,};
int visit[101][101] = {0,};
vector<int> store;


void dragon(int dx,int dy,int dir,int gen){
    visit[dx][dy] = 1;
    store.push_back(dir);
    if(dir == 0){
        visit[dx][dy+1] = 1;
        dy = dy + 1;
    }
    else if(dir == 1){
        visit[dx-1][dy] = 1;
        dx = dx - 1;
    }
    else if(dir == 2){
        visit[dx][dy-1] = 1;
        dy = dy - 1;
    }
    else{
        visit[dx+1][dy] = 1;
        dx = dx + 1;
    }
    for(int i = 0;i < gen;i++){
        int size = store.size();
        for(int j = size-1;j>=0;j--){
            if(store[j] == 0){
                visit[dx-1][dy] = 1;
                dx = dx - 1;
                store.push_back(1);
            }
            else if(store[j] == 1){
                visit[dx][dy-1] = 1;
                dy = dy - 1;
                store.push_back(2);
            }
            else if(store[j] == 2){
                visit[dx+1][dy] = 1;
                dx = dx + 1;
                store.push_back(3);
            }
            else{
                visit[dx][dy+1] = 1;
                dy = dy + 1;
                store.push_back(0);
            }
        }

    }
}



int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        dragon(y,x,d,g);
        store.clear();
    }
    int ans = 0;

    for(int i = 0;i < 101;i++){
        for(int j = 0;j < 101;j++){
            if(visit[i][j] == 1){
                if(i < 102 && j < 102){
                    if(visit[i][j+1] == 1 && visit[i+1][j] == 1 && visit[i+1][j+1] == 1){
                        ans += 1;
                    }
                }
            }
        }
    }
    cout << ans;
}