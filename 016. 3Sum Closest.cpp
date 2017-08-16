// O(n^2) swapping window
// Faster than: 18% - 45%

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3){
            return 0;
        }
        int res = nums[0] + nums[1] + nums[2];
        for (int i=0; i<nums.size(); i++){
            int goal = target - nums[i];
            int j=i+1, k=nums.size()-1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - res)){
                    res = sum;
                }
                if (sum > target){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return res;
    }
};
