#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

map<string ,int> menu;
int visit[26] = {0,};

void findmenu(string s, vector<char> list,int cnt,int limit){
    if(limit == cnt){
        string tmp = "";
        for(auto x : list){
            tmp += x;
        }
        if(menu.find(tmp) != menu.end()){
            menu[tmp] += 1;
        }
        else{
            menu[tmp] = 1;
        }
    }
    for(int i = 0;i < s.size();i++){
        if(list.size() > 0){
            if(!visit[s[i]-'A'] && list[list.size()-1] < s[i]){
               visit[s[i]-'A'] = 1;
               list.push_back(s[i]);
               cnt++;
               findmenu(s,list,cnt,limit);
               list.pop_back();
               cnt--;
               visit[s[i]-'A'] = 0;
            }
        }
        else{
            if(!visit[s[i]-'A']){
               visit[s[i]-'A'] = 1;
               list.push_back(s[i]);
               cnt++;
               findmenu(s,list,cnt,limit);
               list.pop_back();
               cnt--;
               visit[s[i]-'A'] = 0;
            }
        }
       
    }
}

bool comp(pair<string, int>& a, pair<string, int>& b){
	return a.second > b.second;
}



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> arr;
    for(int i = 0;i < orders.size();i++){
        sort(orders[i].begin(),orders[i].end());
    }
    for(int j = 0;j < course.size();j++){
        for(int i = 0;i < orders.size();i++){
            findmenu(orders[i],arr,0,course[j]);
        }
        vector <pair<string ,int> > vmenu(menu.begin(),menu.end());
        vector <string> ans;
        sort(vmenu.begin(),vmenu.end(),comp);
        int max = 2;
        for(auto x: vmenu){
            if(max <= x.second){
                answer.push_back(x.first);
                max = x.second;
            }
            else{
                break;
            }
        }
        menu.clear();
    }
    sort(answer.begin(),answer.end());
    return answer;
}