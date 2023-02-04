#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>
#include <cmath>
#include <map>



using namespace std;
typedef long long ll;



int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    queue <int> q;
    vector <int> v;
    for(int i = 0;i < n;i++){
        q.push(i+1);
    }
    int cnt = 0;
    while(!q.empty()){
        cnt++;
        if(cnt == m){
            v.push_back(q.front());
            q.pop();
            cnt = 0;
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    cout << '<';
    for(int i = 0;i < n;i++){
        if(i == n-1){
            cout << v[i] << '>';
        }
        else{
            cout << v[i] << ", ";
        }
        
    }
}