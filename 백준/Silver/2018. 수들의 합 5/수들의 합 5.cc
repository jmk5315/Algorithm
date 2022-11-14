#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	int s = 1, e = 1, sum = 0;
	while (s <= e && e <= n+1) {
		if (sum > n) {
			sum -= s;
			s++;
		}
		else if (sum < n) {
			sum += e;
			e++;
		}
		else {
			ans++;
			sum += e;
			e++;
		}
	}
	cout << ans;
	return 0;
}