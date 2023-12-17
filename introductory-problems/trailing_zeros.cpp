#include <iostream>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int k = 5;
    int res = 0;

    while (n / k) {
        res += n / k;
        k *= 5;
    }

    cout << res;
}