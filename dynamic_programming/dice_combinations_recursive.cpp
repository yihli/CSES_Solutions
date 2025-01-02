//
// recursive solution
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int ll;

int recurse(int n) {
    int out = 0;
    if (n < 0) return 0;
    if (n == 0) return 1;

    for (int i = 1; i <= 6; i++) {
        out += recurse(n - i) % 1000000007;
    }

    return out;
}


int main() {
    int n;
    int sum = 0;
    cin >> n;
    
    sum = recurse(n);
    cout << sum << endl;
    
}