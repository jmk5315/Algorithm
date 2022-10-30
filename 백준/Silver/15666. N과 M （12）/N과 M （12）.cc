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

int n,m;
int visit[10005] ={0,};
int count1[10005] = {0,};
vector <int> arr;
vector <int> arr2;
void foo(vector <int> v,int cnt){
    int prev1 = 0;
    if(cnt == m){
        for(auto x : v){
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0;i<n;i++){
        if(prev1 != arr[i]){
            if(v.empty()){
                v.push_back(arr[i]);
                prev1 = arr[i];
                foo(v,cnt+1);
                v.pop_back();
            }
            else{
                if(v.back() <= arr[i]){
                    v.push_back(arr[i]);
                    prev1 = arr[i];
                    foo(v,cnt+1);
                    v.pop_back();
                }
            }
            
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
    foo(arr2,0);   
}