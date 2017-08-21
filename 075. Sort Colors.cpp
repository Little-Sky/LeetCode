// O(n)
// Faster than 17%-17%

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int le=0, ri=nums.size()-1;
        // <= because nums[ri] might be 0, so you have to iterate from 0 to ri
        for (int cur=0; cur <= ri; cur++) {
            // MUST swap with 2 first.
            // Because there might be 0 from end, but no 2 from begin.
            while (nums[cur] == 2 && cur < ri) {
                swap(nums[cur], nums[ri--]);
            }
            while (nums[cur] == 0 && le < cur) {
                swap(nums[cur], nums[le++]);
            }
        }
    }
};
