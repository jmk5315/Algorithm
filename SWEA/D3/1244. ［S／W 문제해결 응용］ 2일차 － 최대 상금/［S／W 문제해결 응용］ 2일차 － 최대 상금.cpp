/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string smax = "";

void btk(vector<char> tmp, int cnt,int s){
    if(cnt == 0){
    	string ss = "";
        for(int i = 0;i < tmp.size();i++){
        	ss += tmp[i];
        }
        if(ss > smax){
        	smax = ss;
        }
        return;
    }
    int check = 0;
	for(int i = s;i < tmp.size();i++){
    	for(int j = i+1;j < tmp.size();j++){
            if(tmp[i] < tmp[j]){
            	char tmp2;
                tmp2 = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = tmp2;
                btk(tmp,cnt-1,i);
                tmp2 = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = tmp2;
                check = 1;
            }
        }
    }
    if(check == 0){
    	 if(cnt %2 == 0){
            string ss = "";
            for(int i = 0;i < tmp.size();i++){
                ss += tmp[i];
            }
            if(ss > smax){
                smax = ss;
            }
            return;
        }
        else{
        	for(int i = 0;i < tmp.size();i++){
                for(int j = i+1;j < tmp.size();j++){
                    char tmp2;
                    tmp2 = tmp[i];
                    tmp[i] = tmp[j];
                    tmp[j] = tmp2;
                   	string ss = "";
                    for(int i = 0;i < tmp.size();i++){
                        ss += tmp[i];
                    }
                    if(ss > smax){
                        smax = ss;
                    }
                    tmp2 = tmp[i];
                    tmp[i] = tmp[j];
                    tmp[j] = tmp2;                 
                }
            }
        }
    }
}



int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    vector <char> v;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int a,b;
        cin >> a >> b;
        string s = to_string(a);
        for(int i = 0;i < s.size();i++){
        	v.push_back(s[i]);
        }
        btk(v,b,0);
       	cout <<'#' << test_case<< ' ' << smax << endl;
        v.clear();
        smax = "";


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}