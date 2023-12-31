#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    while (n > 1) {
        cout << n << " ";
        n = (n & 1) ? (3 * n) + 1 : n / 2;
    }

    cout << 1;
}