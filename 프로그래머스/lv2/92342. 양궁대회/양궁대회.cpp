#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int arr[11] = {0,0,0,0,0,0,0,0,0,0,0};
int copy1[11] = {0,0,0,0,0,0,0,0,0,0,0};
int k = 0;
int t = 0;
int max1 = 0;
int tmp[11] = {0,0,0,0,0,0,0,0,0,0,0};

void bfs(int info[],int cnt,int score){
    int num = 0;
    int num2 = t;
    if(cnt == 0){
        for(int i = 0;i < 11;i++){
            if(info[i] != 0){
                num += 10-i;
            }
            if(copy1[i] != 0 && info[i] > copy1[i]){
                num2 -= 10-i;
            }
        }
        
        if(num > num2){
            if((num-num2) > max1){
                max1 = num-num2;
                for(int i = 0;i < 11;i++){
                    tmp[i] = info[i];
                }
            }
            else if((num-num2) == max1){
                for(int i = 10;i >=0;i--){
                    if(tmp[i] < info[i]){
                        for(int j = 0;j < 11;j++){
                            tmp[j] = info[j];
                        }
                        break;
                    }
                    else if(tmp[i] > info[i]){
                        break;
                    }
                }
            }
        }
    }
    for(int i = score;i < 11;i++){
        if(copy1[i]+1 <= cnt){
            info[i] = copy1[i]+1;
            cnt -= info[i];
            bfs(info,cnt,i+1);
            cnt += info[i];
            info[i] = 0;
        }
        else{
            if(i == 10 && cnt != 0){
                info[i] = cnt;
                cnt = 0;
                bfs(info,cnt,i+1);
                cnt += info[i];
                info[i] = 0;
            }
        }

        
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int score = 0;
    k = n;
    for(int i = 0;i < info.size();i++){
        if(info[i] != 0){
            score += 10-i;
        }
        copy1[i] = info[i];
    }
    t = score;
    bfs(arr,n,0);
    for(int i = 0;i < 11;i++){
        answer.push_back(tmp[i]);
    }
    if(max1 == 0){
        answer.clear();
        answer.push_back(-1);
    }
    
    return answer;
}