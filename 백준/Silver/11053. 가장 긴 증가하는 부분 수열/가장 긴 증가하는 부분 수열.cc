#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int dp[1005] = {0,};
	for(int i = 0;i < n;i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	for(int i = 0;i < n;i++){
		dp[i] = 1;
		for(int j = 0;j < i;j++){
			if(v[i] > v[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(dp[i] > ans){
			ans = dp[i];
		}
	}
	cout << ans;
	return 0;
}