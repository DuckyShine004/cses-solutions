#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, idx;
    cin >> n;

    vector<int> V(n, false);
    
    for (int i = 0; i < n - 1; i++) {
        cin >> idx;
        V[idx - 1] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!V[i]) {
            cout << i + 1;
        }
    }
}