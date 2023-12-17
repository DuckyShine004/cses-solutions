#include <iostream>
#include <cmath>

using namespace std;

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    long long idx = 1;
    long long res = 1;

    while (idx <= n) {
        res = (res * 2) % MOD;
        idx++;
    }

    cout << res;
}