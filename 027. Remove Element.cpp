// O(n) one iteration
// Faster than 69% - 69%

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int removed_start=0, start=0;
        for (; start<nums.size(); start++) {
            if (nums[start] != val){
                nums[removed_start++] = nums[start];
            }
        }
        return removed_start;
    }
};
