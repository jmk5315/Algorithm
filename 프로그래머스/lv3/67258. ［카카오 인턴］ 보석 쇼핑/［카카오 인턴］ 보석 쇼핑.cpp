#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map <string,int> m;


vector<int> solution(vector<string> gems) {
    vector<int> answer;
    for(int i = 0;i < gems.size();i++){
        m[gems[i]] = 0;
    }
    int size = m.size();
    int size2 = 0;
    int start = 0;
    int end = 0;
    int len = 987654321;
    int ans_start = 1;
    int ans_end = gems.size();
    while(start <= end && end < gems.size()){
        if(m[gems[end]] == 0){
            m[gems[end]]++;
            size2++;
            end++;
        }
        else{
            if(size == size2){
                while(1){
                    if(m[gems[start]] > 1){
                        m[gems[start]]--;
                        start++;
                    }
                    else{
                        break;
                    }
                }
                if(len > end-start){
                    len = end-start;
                    ans_start = start+1;
                    ans_end = end;
                }
                m[gems[end]]++;
                end++;
            }
            else{
                m[gems[end]]++;
                end++;
            }
        }
    }
    while(1){
        if(m[gems[start]] > 1){
            m[gems[start]]--;
            start++;
        }
        else{
            break;
        }
    }
    if(len > end-start){
        len = end-start;
        ans_start = start+1;
        ans_end = end;
    }
    answer.push_back(ans_start);
    answer.push_back(ans_end);
    return answer;
}