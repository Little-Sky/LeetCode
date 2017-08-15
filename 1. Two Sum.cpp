class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> valueToIndex;
        for (int index=0; index < nums.size(); index++){
            if (valueToIndex.count(target - nums[index])) {
                res.push_back(valueToIndex[target - nums[index]]);
                res.push_back(index);
                return res;
            } else {
                valueToIndex[nums[index]] = index;
            }
        }
        return res;
        
        // vector<int> res;
        // unordered_set<int> s(nums.begin(), nums.end());
        // for (int i=0; i<nums.size(); i++){
        //     if (s.count(target - nums[i])){
        //         for (int j=0; j<nums.size(); j++){
        //             if (nums[j] + nums[i] == target && i != j){
        //                 res.push_back(i);
        //                 res.push_back(j);
        //                 break;
        //             }
        //         }
        //         if (res.size())
        //             break;
        //     }
        // }
        
        // for (int i=0; i<nums.size(); i++){
        //     for (int j=i+1; j<nums.size(); j++){
        //         if (nums[i] + nums[j] == target){
        //             res.push_back(i);
        //             res.push_back(j);
        //             break;
        //         }
        //     }
        //     if (res.size())
        //     break;
        // }
        return res;
    }
};
