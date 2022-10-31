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
int visit[10005] ={0,};
vector <int> arr;
void foo(vector <int> v,int cnt){
    if(cnt == m){
        for(auto x : v){
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0;i<n;i++){
        if(!v.empty() && v[v.size()-1] > arr[i]){
            continue;
        }
        if(!visit[arr[i]]){
            visit[arr[i]] = 1;
            v.push_back(arr[i]);
            foo(v,cnt+1);
            visit[arr[i]] = 0;
            v.pop_back();
        }
    }
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    vector <int> arr2;
    foo(arr2,0);
    
}