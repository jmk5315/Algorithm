#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <deque>

#define ll long long

using namespace std;

bool isprime(ll n){
    if(n < 2){
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int solution(int n, int k) {
    int answer = 0;
    int exp = 0;
    deque <int> arr;
    while(n > 0){
        arr.push_front(n%k);
        n /= k;
    }
    ll tmp = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] == 0){
            if(isprime(tmp)){
                answer++;
                tmp = 0;
                exp = 0;
            }
            else{
                tmp = 0;
                exp = 0;
            }
        }
        else{
            tmp *= 10;
            tmp += arr[i];
            exp++;
        }
    }
    if(isprime(tmp)){
        answer++;
    }
    return answer;
}