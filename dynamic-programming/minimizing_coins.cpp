#include <iostream>
#include <vector>

using namespace std;

const int N = 1000000;
const int INF = 10000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> vec(n);

    for (int &v : vec) {
        cin >> v;
    }

    int dp[N + 1];

    for (int i = 1; i <= x; i++) {
        int cur = INF;

        for (int v : vec) {
            if (i - v >= 0) {
                cur = min(cur, dp[i - v] + 1);
            }
        }

        dp[i] = cur;
    }

    cout << (dp[x] != INF ? dp[x] : -1);
}