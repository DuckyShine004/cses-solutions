#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

bool is_valid(string arr[], int x, int y, int n) {
    return x >= 0 && y >= 0 && arr[y][x] != '*';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string arr[n];

    for (string &s : arr) {
        cin >> s;
    }

    long long dp[n][n];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (arr[y][x] == '*') {
                continue;
            }

            dp[y][x] += (is_valid(arr, x, y - 1, n)) ? dp[y - 1][x]: 0;
            dp[y][x] += (is_valid(arr, x - 1, y, n)) ? dp[y][x - 1]: 0;

            dp[y][x] %= MOD;
        }
    }

    cout << (arr[0][0] != '*' ? dp[n - 1][n - 1] : 0);
}