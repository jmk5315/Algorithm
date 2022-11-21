#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1005]={0,};

void isprime(int n){
	for(int i = 2;i <= n;i++){
		for(int j = i*2;j <=n;j+=i){
			arr[j] = 1;
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0;i < n;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	arr[1] = 1;
	sort(v.begin(),v.end());
	isprime(v[n-1]);
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(arr[v[i]] == 0){
			ans++;
		}
	}
	cout << ans;
	return 0;
}