#include <string>
#include <vector>
#include <iostream>

using namespace std;



vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<pair<int,int>,int> > in;
    int car[10005] ={0,};
    for(int i = 0;i < records.size();i++){
        int clock = stoi(records[i].substr(0,2));
        int minute = stoi(records[i].substr(3,2));
        int num = stoi(records[i].substr(6,4));
        char check = records[i][11];
        if(check == 'I'){
            in.push_back(make_pair(make_pair(clock,minute),num));
        }
        else{
            for(int j = 0;j < in.size();j++){
                if(in[j].second == num){
                    int time = ((clock-in[j].first.first)*60) + (minute-in[j].first.second);
                    car[num] += time;
                    in.erase(in.begin()+j);
                }
            }
        }
    }
    for(int i = 0;i < in.size();i++){
        int time = ((23-in[i].first.first)*60) + (59-in[i].first.second);
        car[in[i].second] += time;
    }
    for(int i = 0;i<10000;i++){
        if(car[i] != 0){
            if(car[i] <= fees[0]){
                answer.push_back(fees[1]);
            }
            else{
                int time = car[i] - fees[0];
                if((time % fees[2]) != 0){
                    int fee = ((time/fees[2]) + 1) * fees[3] + fees[1];
                    answer.push_back(fee);
                }
                else{
                    int fee = (time/fees[2]) * fees[3] + fees[1];
                    answer.push_back(fee);
                }
               
            }
        }
    }
    return answer;
}