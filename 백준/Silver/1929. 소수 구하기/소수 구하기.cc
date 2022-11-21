#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000005]={0,};

void isprime(int k){
	for(int i = 2;i <= k;i++){
		for(int j = i*2;j <=k;j+=i){
			arr[j] = 1;
		}
	}
}

int main() {
	int n,m;
	cin >> n >> m;
	arr[1] = 1;
	isprime(m);
	for(int i = n;i <=m;i++){
		if(arr[i] == 0){
			cout << i << '\n';
		}
	}
	return 0;
}