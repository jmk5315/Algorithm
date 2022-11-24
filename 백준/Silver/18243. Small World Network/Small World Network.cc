#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int inf = 100000000;


int n = 0;
int m = 0;
int arr[101][101] = {0,};
int visit[101] = {0,};


void addedge(int u,int v){
	arr[u][v] = 1;
	arr[v][u] = 1;
}
void dfs(int c){
	if(visit[c] == true){
		return;
	}
	visit[c] = true;
	for(int i = 1;i<=n;i++){
		if(arr[c][i] == 1){
			dfs(i);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin >> a >> b;
		addedge(a,b);
	}
	int sum = 0;
	for(int i = 1;i<=n;i++){
		if(visit[i] == 0){
			sum++;
		}
		dfs(i);
	}
	if(sum > 1){
		cout << "Big World!";
		return 0;
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i==j){
					continue;
				}
				else{
					if(arr[i][k] != 0 && arr[k][j] != 0){
						if(arr[i][j] == 0){
							arr[i][j] = arr[i][k] + arr[k][j];
						}
						else{
							arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
						}
					}
					
				}
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(arr[i][j] > 6){
				cout << "Big World!";
				return 0;
			}
		}
	}
	cout << "Small World!";
	
	
	
	return 0;
}