#include <cmath>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> squareDifference(int n) {
        int root = sqrt(n);
        int lower = root * root;
        int upper = (root + 1) * (root + 1);

        int nearest;
        if (abs(n - lower) <= abs(upper - n)) {
            nearest = lower;
        } else {
            nearest = upper;
        }

        return {nearest, abs(n - nearest)};
    }
};
