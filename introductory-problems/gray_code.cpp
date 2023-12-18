#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n;

    deque<char> q;
    string s;

    k = (int) pow(2, n);

    for (int i = 0; i < n; i++) {
        q.push_front('0');
    }

    
}

