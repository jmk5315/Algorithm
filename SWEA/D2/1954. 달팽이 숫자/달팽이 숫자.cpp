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
#include<queue>

using namespace std;

int arr[11][11] = {0,};

void bfs(int n){
	queue <pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(0,0),0));
    int cnt = 1;
    while(!q.empty() && cnt <= n*n){
    	int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;
        arr[x][y] = cnt;
        cnt++;
        q.pop();
        if(dir == 0){
        	if(y+1 < n){
                if(arr[x][y+1] == 0){
                	q.push(make_pair(make_pair(x,y+1),0));
                }
				else{
                	q.push(make_pair(make_pair(x+1,y),1));
                }
            }
            else{
            	q.push(make_pair(make_pair(x+1,y),1));
            }
        }
        else if(dir == 1){
        	if(x+1 < n){
                if(arr[x+1][y] == 0){
                	q.push(make_pair(make_pair(x+1,y),1));
                }
				else{
                	q.push(make_pair(make_pair(x,y-1),2));
                }
            }
            else{
            	q.push(make_pair(make_pair(x,y-1),2));
            }
        }
        else if(dir == 2){
        	if(y > 0){
                if(arr[x][y-1] == 0){
                	q.push(make_pair(make_pair(x,y-1),2));
                }
				else{
                	q.push(make_pair(make_pair(x-1,y),3));
                }
            }
            else{
            	q.push(make_pair(make_pair(x-1,y),3));
            }
        }
        else{
            if(arr[x-1][y] == 0){
                q.push(make_pair(make_pair(x-1,y),3));
            }
            else{
                q.push(make_pair(make_pair(x,y+1),0));
            }
        }
    }
    
    
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{	
        int k;
        cin >> k;
        bfs(k);
        cout << '#' << test_case << '\n';
        for(int i = 0;i < k;i++){
        	for(int j = 0;j < k;j++){
            	cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        for(int i = 0;i < k;i++){
        	for(int j = 0;j < k;j++){
            	arr[i][j] = 0;
            }
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}