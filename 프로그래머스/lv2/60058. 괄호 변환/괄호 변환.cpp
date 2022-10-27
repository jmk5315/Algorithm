#include <string>
#include <vector>
#include <iostream>

using namespace std;


string change(string v){
    if(v == ""){
        return "";
    }
    string tmp = "";
    int left = 0;
    int right = 0;
    for(int i = 0;i<v.size();i++){
        if(v[i] == '('){
            tmp += '(';
            left++;            
        }
        else{
            tmp += ')';
            right++;
        }
        if(left == right){
            v = v.substr(i+1,v.size()-1);
            break;
        }
    }
    left = 0;
    right = 0;
    int check = 0;
    for(int i = 0;i < tmp.size();i++){
        if(tmp[i] == '('){
            left++;
        }
        else{
            right++;
        }
        if(right > left){
            check = 1;
            break;
        }
    }
    cout << tmp << " " << check << endl;
    if(check == 0){
        return tmp + change(v);
    }
    else{
        tmp = tmp.substr(1,tmp.size()-2);
        cout << tmp << endl;
        for(int i = 0;i < tmp.size();i++){
            if(tmp[i] == '('){
                tmp[i] = ')';
            }
            else{
                tmp[i] = '(';
            }
        }
        return '(' + change(v) + ')' + tmp;

    }
}

string solution(string p) {
    int left = 0;
    int right = 0;
    int check = 0;
    for(int i = 0;i < p.size();i++){
        if(p[i] == '('){
            left++;
        }
        else{
            right++;
        }
        if(right > left){
            check = 1;
            break;
        }
    }
    if(check == 0){
        return p;
    }
    else{
        return change(p);
    }
}