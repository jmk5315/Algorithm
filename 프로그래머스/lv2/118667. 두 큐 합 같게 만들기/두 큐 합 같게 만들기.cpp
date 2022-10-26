#include <string>
#include <vector>
#include <iostream>
#include <queue>

#define ll long long 

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    ll sum1 = 0;
    ll sum2 = 0;
    for(int i = 0;i < queue1.size();i++){
        q1.push(queue1[i]);
        sum1 += queue1[i];
    }
    for(int i = 0;i < queue2.size();i++){
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    if((sum1 + sum2) % 2 != 0){
        return -1;
    }
    while(sum1 != sum2){
        ll tmp = 0;
        if(q1.empty() || q2.empty()){
            return -1;
        }
        if(sum1 > sum2){
            tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            sum1 -= tmp;
            sum2 += tmp;
            answer++;
        }
        else if(sum1 < sum2){
            tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            sum1 += tmp;
            sum2 -= tmp;
            answer++;
        }
        if(answer > queue1.size() * queue2.size()){
            return -1;
        }
    }
    return answer;
}