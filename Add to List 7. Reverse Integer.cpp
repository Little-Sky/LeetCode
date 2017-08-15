// O(n)
// Faster than: 9% - 81%

class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0;
        if (isNegative){
            x *= -1;
        }
        string xInStr = to_string(x);
        std::reverse(xInStr.begin(), xInStr.end());
        // xInStr.reverse();
        long long xInLongLong = stoll(xInStr) * (isNegative ? -1 : 1);
        if (xInLongLong > INT_MAX || xInLongLong < INT_MIN){
            return 0;
        }
        return (int) xInLongLong;
    }
};
