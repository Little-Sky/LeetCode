// O(logN)
// Faster than 63%

class Solution {
public:
    int mySqrt(int x) {
        long long le = 0, ri = x;
        while (le < ri) {
            long long mid = ri -  (ri-le) / 2;
            long long diff = mid*mid - x;
            if (diff < 0) {
                le = mid;
            } else if (diff > 0) {
                ri = mid-1;
            } else {
                return mid;
            }
        }
        return le;
    }
};
