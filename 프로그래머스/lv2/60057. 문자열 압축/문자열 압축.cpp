#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string btk(string s,int cnt){
    string ans = "";
    int count = 1;
    int len = 0;
    string tmp = "";
    string tmp2 = "";
    for(int i = 0;i < s.size();i++){
        if(len < cnt){
            tmp += s[i];
            len++;
        }
        else{
            if(tmp != tmp2){
                if(count == 1){
                    ans += tmp2;
                    tmp2 = tmp;
                    tmp = s[i];
                    len = 1;
                }
                else{
                    ans += to_string(count);
                    ans += tmp2;
                    tmp2 = tmp;
                    tmp = s[i];
                    count = 1;
                    len = 1;
                }
            }
            else{
                count++;
                tmp = s[i];
                len = 1;
            }
        }
    }
    if(tmp != tmp2){
        if(count == 1){
            ans += tmp2;
            ans += tmp;
        }
        else{
            ans += to_string(count);
            ans += tmp2;
            ans += tmp;
        }
    }
    else{
        ans += to_string(count+1);
        ans += tmp;
    }
    return ans;
    
}

int solution(string s) {
    int answer = 987654321;
    vector <string> tmp;
    for(int i = 1;i < s.size()+1;i++){
        tmp.push_back(btk(s,i));
    }
    for(int i = 0;i < tmp.size();i++){
        if(tmp[i].size() < answer){
            answer  = tmp[i].size();
        }
    }
    
    return answer;
}