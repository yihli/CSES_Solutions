#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// recursive problem solving:
// 1. show f(1) works: move from 1 to 3.
// 2. assume that f(n-1) works: if n can be moved from 1 to 3, then n - 1 can be moved from 1 to 3.
// 3. show how f(n) is related to f(n-1).
void hanoi(int n, int start, int end) {
    if (n == 1) {
        cout << start << " " << end << endl;
    }
    else {
        hanoi(n - 1, start, 6 - (start + end));
        cout << start << " " << end << endl;
        hanoi(n - 1, 6 - (start + end), end);
    }
}

int main() {
    int n;
    cin >> n;

    //the number of moves is equal to 2^n - 1
    cout << pow(2, n) - 1 << endl;
    hanoi(n, 1, 3);
}