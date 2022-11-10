#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>

using namespace std;
typedef long long ll;
deque <int> deque1,deque2,deque3,deque4;


void forward(deque <int> deq){
    int tmp;
    tmp = deq.back();
    deq.pop_back();
    deq.push_front(tmp);
}

void backward(deque <int> deq){
    int tmp;
    tmp = deq.front();
    deq.pop_front();
    deq.push_back(tmp);
}




int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    for(int i = 0;i < 4;i++){
        string a;
        cin >> a;
        for(int j = 0;j < 8;j++){
            if(i == 0){
                deque1.push_back(a[j]-'0');
            }
            else if(i == 1){
                deque2.push_back(a[j]-'0');
            }
            else if(i == 2){
                deque3.push_back(a[j]-'0');
            }
            else{
                deque4.push_back(a[j]-'0');
            }
        }
    }
    int k;
    cin >> k;
    for(int i = 0;i < k;i++){
        int n,m;
        cin >> n >> m;
        int tmp;
        int arr[6]={0,};
        arr[0] = deque1[2];
        arr[1] = deque2[6];
        arr[2] = deque2[2];
        arr[3] = deque3[6];
        arr[4] = deque3[2];
        arr[5] = deque4[6];
        if(n == 1){
            if(m == 1){
                tmp = deque1.back();
                deque1.pop_back();
                deque1.push_front(tmp);
                if(arr[0] != arr[1]){
                    tmp = deque2.front();
                    deque2.pop_front();
                    deque2.push_back(tmp);
                    if(arr[2] != arr[3]){
                        tmp = deque3.back();
                        deque3.pop_back();
                        deque3.push_front(tmp);
                        if(arr[4] != arr[5]){
                            tmp = deque4.front();
                            deque4.pop_front();
                            deque4.push_back(tmp);
                        }
                    }
                }
            }
            else{
                tmp = deque1.front();
                deque1.pop_front();
                deque1.push_back(tmp);
                if(arr[0] != arr[1]){
                    tmp = deque2.back();
                    deque2.pop_back();
                    deque2.push_front(tmp);
                    if(arr[2] != arr[3]){
                        tmp = deque3.front();
                        deque3.pop_front();
                        deque3.push_back(tmp);
                        if(arr[4] != arr[5]){
                            tmp = deque4.back();
                            deque4.pop_back();
                            deque4.push_front(tmp);
                        }
                    }
                }
            }
        }
        else if(n == 2){
            if(m == 1){
                tmp = deque2.back();
                deque2.pop_back();
                deque2.push_front(tmp);
                if(arr[0] != arr[1]){
                    tmp = deque1.front();
                    deque1.pop_front();
                    deque1.push_back(tmp);
                }
                if(arr[2] != arr[3]){
                    tmp = deque3.front();
                    deque3.pop_front();
                    deque3.push_back(tmp);
                    if(arr[4] != arr[5]){
                        tmp = deque4.back();
                        deque4.pop_back();
                        deque4.push_front(tmp);
                    }
                }
            }
            else{
                tmp = deque2.front();
                deque2.pop_front();
                deque2.push_back(tmp);
                if(arr[0] != arr[1]){
                    tmp = deque1.back();
                    deque1.pop_back();
                    deque1.push_front(tmp);
                }
                if(arr[2] != arr[3]){
                    tmp = deque3.back();
                    deque3.pop_back();
                    deque3.push_front(tmp);
                    if(arr[4] != arr[5]){
                        tmp = deque4.front();
                        deque4.pop_front();
                        deque4.push_back(tmp);
                    }
                }
            }
        }
        else if(n == 3){
            if(m == 1){
                tmp = deque3.back();
                deque3.pop_back();
                deque3.push_front(tmp);
                if(arr[4] != arr[5]){
                    tmp = deque4.front();
                    deque4.pop_front();
                    deque4.push_back(tmp);
                }
                if(arr[2] != arr[3]){
                    tmp = deque2.front();
                    deque2.pop_front();
                    deque2.push_back(tmp);
                    if(arr[0] != arr[1]){
                        tmp = deque1.back();
                        deque1.pop_back();
                        deque1.push_front(tmp);
                    }
                }
            }
            else{
                tmp = deque3.front();
                deque3.pop_front();
                deque3.push_back(tmp);
                if(arr[4] != arr[5]){
                    tmp = deque4.back();
                    deque4.pop_back();
                    deque4.push_front(tmp);
                }
                if(arr[2] != arr[3]){
                    tmp = deque2.back();
                    deque2.pop_back();
                    deque2.push_front(tmp);
                    if(arr[0] != arr[1]){
                        tmp = deque1.front();
                        deque1.pop_front();
                        deque1.push_back(tmp);
                    }
                }
            }
        }
        else{
            if(m == 1){
                tmp = deque4.back();
                deque4.pop_back();
                deque4.push_front(tmp);
                if(arr[4] != arr[5]){
                    tmp = deque3.front();
                    deque3.pop_front();
                    deque3.push_back(tmp);
                    if(arr[2] != arr[3]){
                        tmp = deque2.back();
                        deque2.pop_back();
                        deque2.push_front(tmp);
                        if(arr[0] != arr[1]){
                            tmp = deque1.front();
                            deque1.pop_front();
                            deque1.push_back(tmp);
                        }
                    }
                }
            }
            else{
                tmp = deque4.front();
                deque4.pop_front();
                deque4.push_back(tmp);
                if(arr[4] != arr[5]){
                    tmp = deque3.back();
                    deque3.pop_back();
                    deque3.push_front(tmp);
                    if(arr[2] != arr[3]){
                        tmp = deque2.front();
                        deque2.pop_front();
                        deque2.push_back(tmp);
                        if(arr[0] != arr[1]){
                            tmp = deque1.back();
                            deque1.pop_back();
                            deque1.push_front(tmp);
                        }
                    }
                }
            }
        }
    }
    

    int ans = 0;
    if(deque1[0] == 1){
        ans += 1;
    }
    if(deque2[0] == 1){
        ans += 2;
    }
    if(deque3[0] == 1){
        ans += 4;
    }
    if(deque4[0] == 1){
        ans += 8;
    }
    cout << ans;
    
}