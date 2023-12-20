#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, num;
    cin >> n;

    int k = 0;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> num;

        k += num;
        coins.push_back(num);
    }

    vector<bool> dp(k + 1);
    vector<int> res;

    dp[0] = true;

    for (int coin : coins) {
        for (int i = k - coin; i >= 0; i--) {
            if (dp[i] && !dp[i + coin]) {
                res.push_back(i + coin);
                dp[i + coin] = true;
            }
        }
    }

    cout << res.size() << "\n";

    sort(res.begin(), res.end());

    for (int num : res) {
        cout << num << " ";
    }
}
