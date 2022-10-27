#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>
#include <cmath>



using namespace std;
typedef long long ll;

int n,m;
int visit[10] ={0,};
void foo(vector <int> v,int cnt){
    if(cnt == m){
        for(auto x : v){
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1;i<n+1;i++){
        if(!visit[i]){
            visit[i] = 1;
            v.push_back(i);
            foo(v,cnt+1);
            visit[i] = 0;
            v.pop_back();
        }
    }
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector <int> arr;
    foo(arr,0);
    
}