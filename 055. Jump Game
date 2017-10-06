// O(n) One iteration
// Faster than 33%

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int i=0; i<nums.size() && i <= mx; i++) {
            mx = max(mx, i + nums[i]);
        }
        return mx+1 >= nums.size();
    }
};
