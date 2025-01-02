#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x{};
    int n{};
    cin >> x >> n;


    // idea 1: use a set to remember te positions of lights. use a multiset to  
    // remember the distances of no lights. When a new light is built, find the 
    // lights directly before and after it, and replace the old distance with 
    // the two new distances formed by adding the new light. Then find the max
    // distance. 
    set<int> lights({0,x});
    multiset<int> distances({x});

    while (n--) {
        int p{};
        cin >> p;

        // upper bound returns the next largest
        // pre-decrement gives the largest that's less than p
        int next_light = *(lights.upper_bound(p));
        int last_light = *(--lights.upper_bound(p));

        // remove the distance (that is being split) from the multimap
        auto iter_to_element = distances.lower_bound(next_light - last_light);
        distances.erase(iter_to_element);

        // put the new distances into the multimap
        distances.insert(next_light - p);
        distances.insert(p - last_light);
        cout << *(--distances.end()) << '\n';

        // put the position of the new light into the set.
        lights.insert(p);
    } 

    // for (auto x : distances) {
    //     cout << x << '\n';
    // }
}