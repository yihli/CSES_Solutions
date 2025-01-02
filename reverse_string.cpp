#include <bits/stdc++.h>
using namespace std;

void reverse(deque<int>& d) {
    int num;

    if (d.size() == 0) {
        return;
    }

    num = d[0];
    d.pop_front();
    reverse(d);
    d.push_back(num);
}

int main() {
    deque<int> d = {1, 2, 3, 4, 5};

    reverse(d);

    for (auto i : d) {
        cout << i;
    }
}