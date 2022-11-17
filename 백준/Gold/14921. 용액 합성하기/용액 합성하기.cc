#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define endl '\n'
typedef long long ll;
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	int s = 0, e = n-1, sum = arr[s]+arr[e], ans = sum;
	while (s < e) {
		if (sum > 0) {
			e--;
			if (s == e) {
				break;
			}
			sum = arr[s] + arr[e];
		}
		else if (sum == 0) {
			cout << sum;
			return 0;
		}
		else {
			s++;
			if (s == e) {
				break;
			}
			sum = arr[s] + arr[e];
		}
		if (abs(ans) > abs(sum)) {
			ans = sum;
		}
	}
	cout << ans;
	return 0;
}