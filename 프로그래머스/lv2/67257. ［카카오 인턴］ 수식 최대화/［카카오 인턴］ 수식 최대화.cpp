#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

char express1[3]={'*','+','-'};
char express2[3]={'*','-','+'};
char express3[3]={'+','*','-'};
char express4[3]={'+','-','*'};
char express5[3]={'-','+','*'};
char express6[3]={'-','*','+'};

vector <ll> ans;

ll cal(char a,ll n, ll m){
    if(a == '*'){
        return n*m;
    }
    else if(a == '+'){
        return n+m;
    }
    else if(a == '-'){
        return n-m;
    }
}

void findstar(vector<ll> numtmp,vector <char> arr,char exp[3]){
    for(int k = 0;k<3;k++){
        for(int i = 0;i < arr.size();i++){
            if(arr[i] == exp[k]){
                numtmp[i] = cal(arr[i],numtmp[i],numtmp[i+1]);
                arr.erase(arr.begin()+i);
                numtmp.erase(numtmp.begin()+i+1);
                i -= 1;
            }
         }
    }
    ans.push_back(abs(numtmp[0]));
}

long long solution(string expression) {
    long long answer = 0;
    string tmp="";
    vector <ll> num;
    vector <char> exp;
    for(int i = 0;i < expression.size();i++){
        if(expression[i] == '-' || expression[i] == '+' || expression[i] == '*'){
            exp.push_back(expression[i]);
            num.push_back(stoi(tmp));
            tmp ="";
        }
        else{
            tmp += expression[i];
        }
    }
    num.push_back(stoi(tmp));
    findstar(num,exp,express1);
    findstar(num,exp,express2);
    findstar(num,exp,express3);
    findstar(num,exp,express4);
    findstar(num,exp,express5);
    findstar(num,exp,express6);
    
    ll maxans = 0;
    for(int i = 0;i < ans.size();i++){
        if(ans[i] > maxans){
            maxans = ans[i];
        }
    }
    answer = maxans;
    return answer;
}