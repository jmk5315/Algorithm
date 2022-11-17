#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int> > v;
	for(int i = 0; i < n;i++){
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(b,a));
	}
	sort(v.begin(),v.end());
	int cnt = 0;
	int tmp = 0;
	for(int i = 0;i < n;i++){
		if(tmp <= v[i].second){
			cnt++;
			tmp = v[i].first;
		}
	}
	cout << cnt;
	return 0;
}