// O(n log n), inserting to the map is quite slow 
// Faster than 0.57% - 84% [Facepalm]

/*
  A faster way is to do a binary search after finds a smaller digits.
  // Implementation: analyze the situation carefully before coding
  // Many cases were handled incorrecly at first
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int len = nums.size();
        map<int, int> occured_num;
        for (int i=len-1; i>=0; i--) {
            if (occured_num.size() && nums[i] < occured_num.rbegin()->first) {
                auto itr = occured_num.upper_bound(nums[i]);
                swap(nums[i], nums[itr->second]);
                for (int j=i+1, k=len-1; j<k; j++, k--) {
                    swap(nums[j], nums[k]);
                }
                return;
            } else {
                if (!occured_num.count(nums[i])) {
                    occured_num[nums[i]] = i;
                }
            }
        }
        
        for (int i=0; i<len/2; i++) {
            swap(nums[i], nums[len-i-1]);
        }
        return;
    }
};
