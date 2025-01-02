#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // sort the end times of the movie and store the lengths of movies
    // the first movie is definitely watched 
    // if the start time (end time  - length) is before the previously watched movie, don't watch that one
    int n, a, b;
    int prev_end = 0;
    int movies_watched = 0;
    multimap<int, int> m;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        // multimap sorts by end time automatically
        m.insert(make_pair(b, b-a));
        
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {

        // if the end time minus the length is after the last end time.
        if (iter->first - iter->second >= prev_end) {
            movies_watched++;
            prev_end = iter->first;
        }
    }

    cout << movies_watched << '\n';

    
    
}