#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;


int x[4] ={0,-1,0,1};
int y[4] ={-1,0,1,0};





int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int arr[51][51]={0,};
    int n,m;
    cin >> n >> m;
    int r,c;
    int dir;
    cin >> r >> c >> dir;
    for(int i = 0;i < n;i++){
        for(int j = 0; j <m;j++){
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    arr[r][c] = 2;
    int cnt = 1;
    while(1){
        if(arr[r + x[0]][c + y[0]] != 0 && arr[r + x[1]][c + y[1]] != 0 && arr[r + x[2]][c + y[2]] != 0 && arr[r + x[3]][c + y[3]] != 0){
            if(dir == 0){
                if(arr[r+1][c] == 1){
                    break;
                }
                else{
                    r+= 1;
                    continue;
                }
            }
            else if(dir == 1){
                if(arr[r][c-1] == 1){
                    break;
                }
                else{
                    c -=1;
                    continue;
                }
            }
            else if(dir == 2){
                if(arr[r-1][c] == 1){
                    break;
                }
                else{
                    r -=1;
                    continue;
                }
            }
            else{
                if(arr[r][c+1] == 1){
                    break;
                }
                else{
                    c += 1;
                    continue;
                }
            }
        }
        if(arr[r + x[dir]][c + y[dir]] == 0){
            r += x[dir];
            c += y[dir];
            arr[r][c] = 2;
            cnt ++;
            if(dir == 0){
                dir = 3;
            }
            else if(dir == 1){
                dir = 0;
            }
            else if(dir == 2){
                dir = 1;
            }
            else{
                dir = 2;
            }
        }
        else{
            if(dir == 0){
                dir = 3;
            }
            else if(dir == 1){
                dir = 0;
            }
            else if(dir == 2){
                dir = 1;
            }
            else{
                dir = 2;
            }
        }
    }

    
    cout << cnt;

    
}