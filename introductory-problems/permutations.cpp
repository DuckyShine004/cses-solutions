#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    int x = 0;
    int y = -1;
    int k = n / 2;

    for (int i = 0; i < n; i++) {
        cout << (i < k ? x += 2 : y += 2) << " ";
    }
}