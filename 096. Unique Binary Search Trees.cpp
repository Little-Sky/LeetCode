// O(n^2) Each i <= n will be calculate once, which takes O(n) time. 
// Faster than 26% (Slower than 0%)

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) {
            return 1;
        } else if (mem.count(n)) {
            return mem[n];
        } else {
            int res = 0;
            for (int i=0; i<n; i++) {
                res += numTrees(i) * numTrees(n-i-1);
            }
            mem[n] = res;
            return res;
        }
    }
private:
    unordered_map<int, int> mem;
};
