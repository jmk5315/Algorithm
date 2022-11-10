#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vector<int> arr;
        for (int j = 0; j < a; j++)
        {
            int k;
            cin >> k;
            arr.push_back(k);
        }
        int sum = 0;
        int max = *max_element(arr.begin(), arr.end());
        while (1)
        {
            if (arr[0] == max)
            {
                arr.erase(arr.begin());
                sum += 1;
                if (b == 0)
                {
                    cout << sum << "\n";
                    break;
                }
                else
                {
                    b -= 1;
                }
                max = *max_element(arr.begin(), arr.end());
            }
            else
            {
                int tmp = arr[0];
                arr.erase(arr.begin());
                if (b > 0)
                {
                    b -= 1;
                }
                else
                {
                    b = arr.size();
                }
                arr.push_back(tmp);
            }
        }
    }
}