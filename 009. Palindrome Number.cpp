// O(n)
// Faster than: 55% - 85%

/*
  A faster method seems to be calculate the reverse number, then check wether they are equal.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // if (x < 0){
        //     x *= -1;
        // }
        if (x < 0){
            return false;
        }
        int digit = (int)log10(x);
        while (digit >= 1){
            if (x % 10 != x / (int)pow(10, digit)){
                // cout << (x % 10) << "\n";
                // cout << (x / (int)pow(10, digit)) << endl;
                return false;
            }
            x = (x % (int)pow(10, digit)) / 10;
            digit -= 2;
        }
        return true;
    }
};
