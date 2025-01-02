#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll moves = 0;
    ll size = 0;
    ll curr = 0;
    ll min = 0;

    cin >> size;

    for (int i = 0; i < size; i++) {
        //get the current number
        cin >> curr;

        //current number less than the minimum? 
        //yes: make the number of moves
        //no: no moves needed, so set current number to minimum
        if (curr < min) {
            moves += (min - curr);
        }
        else {
            min = curr;
        }
    }

    cout << moves << endl;
}