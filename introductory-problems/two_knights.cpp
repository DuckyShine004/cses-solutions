#include <iostream>

using namespace std;

const pair<int, int> directions[8] = {
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {1, -2},
    {1, 2},
    {2, -1},
    {2, 1},
};

bool is_valid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int get_squares(int n) {
    int m = n * n;
    int out = 0;

    int dx, dy;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = 1;

            for (pair<int, int> direction : directions) {
                dx = j + direction.first;
                dy = i + direction.second;

                if (is_valid(j, i, n)) {
                    k++;
                }
            }

            out += m - k;
        }
    }

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int res = 0;

    for (int k = 1; k <= n; k++) {
        res += get_squares(k);
        cout << res << "\n";
    }
}
