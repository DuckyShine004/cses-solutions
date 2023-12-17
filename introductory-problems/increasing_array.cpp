#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, val;
    cin >> n;

    long long res = 0;

    vector<int> V(n);
    
    for (int &v : V) {
        cin >> v;
    }

    for (int i = 1; i < n; i++) {
        if (V[i - 1] > V[i]) {
            val = V[i - 1] - V[i];

            V[i] += val;
            res += val;
        }
    }
    
    cout << res;
}