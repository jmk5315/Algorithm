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
int arr2[51][51] = {0,};
int x[4] = {-1,0,1,0};
int y[4] = {0,-1,0,1};


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int r,c,t;
    cin >> r >> c >> t;
    int x1,x2;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            int a;
            cin >> a;
            arr[i][j] = a;
            if(a == -1){
                x1 = i-1;
                x2 = i;
            }
        }
    }


    for(int k = 0;k<t;k++){
        for(int i = 0;i < r;i++){
            for(int j = 0;j<c;j++){
                if(arr[i][j] >= 5){
                    int spread = arr[i][j] / 5;
                    int cnt = 0;
                    for(int l = 0;l<4;l++){
                        int dx = i + x[l];
                        int dy = j + y[l];
                        if(dx >= 0 && dx <r && dy >= 0 && dy < c){
                            if(arr[dx][dy] != -1){
                                arr2[dx][dy] += spread;
                                cnt++;
                            }
                        }
                    }
                    int rest = arr[i][j] - (spread*cnt);
                    arr2[i][j] += rest;
                }
                else{
                    arr2[i][j] += arr[i][j];
                }
            }
        }


        int xtmp = arr2[x1][c-1];
        for(int j = c-1;j>1;j--){
            arr2[x1][j] = arr2[x1][j-1];
        }
        arr2[x1][1] = 0;
        int ytmp = arr2[0][c-1];
        for(int i = 0;i<x1-1;i++){
            arr2[i][c-1] = arr2[i+1][c-1];
        }

        arr2[x1-1][c-1] = xtmp;
        xtmp = arr2[0][0];
        for(int j = 0;j < c-2;j++){
            arr2[0][j] = arr2[0][j+1];
        }
        arr2[0][c-2] = ytmp;
        for(int i = x1-1;i > 1;i--){
            arr2[i][0] = arr2[i-1][0];
        }
        arr2[1][0] = xtmp;


        xtmp = arr2[x2][c-1];
        for(int j = c-1;j>1;j--){
            arr2[x2][j] = arr2[x2][j-1];
        }
        arr2[x2][1] = 0;
        ytmp = arr2[r-1][c-1];
        for(int i = r-1;i>x2+1;i--){
            arr2[i][c-1] = arr2[i-1][c-1];
        }
        arr2[x2+1][c-1] = xtmp;
        xtmp = arr2[r-1][0];
        for(int j = 0;j< c-2;j++){
            arr2[r-1][j] = arr2[r-1][j+1];
        }
        arr2[r-1][c-2] = ytmp;
        for(int i = x2+1;i<r-2;i++){
            arr2[i][0] = arr2[i+1][0];
        }
        arr2[r-2][0] = xtmp;



        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                arr[i][j] = arr2[i][j];
                arr2[i][j] = 0;
            }
        }
    }
    int ans = 2;
    for(int i= 0;i<r;i++){
        for(int j = 0;j < c;j++){
            ans += arr[i][j];
        }
    }
    cout << ans;
    
    
}