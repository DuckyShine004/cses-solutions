#include <iostream>
#include <vector>

using namespace std;

void solve_odd(int n) {
    vector<int> a;
    vector<int> b;

    int k = n / 2;

    for (int i = 1; i <= k; i++) {
        if (i & 1) {
            a.push_back(i);
            a.push_back(n - i);
        } else {
            b.push_back(i);
            b.push_back(n - i);
        }
    }

    b.push_back(n);

    cout << a.size() << "\n";

    for (int num : a) {
        cout << num << " ";
    }

    cout << "\n" << b.size() << "\n";

    for (int num : b) {
        cout << num << " ";
    }
}

void solve_even(int n) {
    int k = n / 4;
    int res = 0;

    cout << n / 2 << "\n";

    for (int i = 0; i < k; i++) {
        cout << res + 1 << " " << n - res << " ";
        res++;
    }

    cout << "\n" << n / 2 << "\n";

    for (int i = 0; i < k; i++) {
        cout << res + 1 << " " << n - res << " ";
        res++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (((n * (n + 1)) / 2) & 1) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;

    if (n & 1) {
        solve_odd(n);
    } else {
        solve_even(n);
    }
}