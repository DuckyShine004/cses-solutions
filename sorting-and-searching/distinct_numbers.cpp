#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n;

    set<int> iset;

    for (int i = 0; i < n; i++) {
        cin >> k;
        iset.insert(k);
    }

    cout << iset.size();
}
