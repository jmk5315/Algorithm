#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a,b=0;
	cin >> a >> b;
	int d = a;
	int e = b;
	while(b>0){
		int c = a;
		a = b;
		b = c%b;
	}
	cout << a << endl;
	int f = 0;
	f = (d * e)/a;
	cout << f;
	return 0;
}