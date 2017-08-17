// O(n) one iteration
// Faster than 8% - 28%

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        int unique_start=1, start=1;
        for (; start < nums.size(); start++) {
            if (nums[start] != nums[start-1]) {
                nums[unique_start++] = nums[start];
            }
        }
        return unique_start;
    }
};
