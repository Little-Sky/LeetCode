// O(n^2) a faster one, where n are number of distinct elements
// Faster than 13%


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> counter;
        vector<vector<int>> res;
        set<int> numSet(nums.begin(), nums.end());
        for (auto num : nums) {
            counter[num]++;
        }
        // Find three distant number triples (a, b, c)
        for (auto itr1 = numSet.begin(); itr1 != numSet.end(); itr1++) {
            for (auto itr2 = next(itr1, 1); itr2 != numSet.end(); itr2++) {
                int thirdNum = - (*itr1) - (*itr2);
                if (thirdNum > *itr2 && counter.count(thirdNum)) {
                    vector<int> cur = {*itr1, *itr2, thirdNum};
                    res.push_back(cur);
                }
            } 
        }
        // Find two distant number triples (a, a, b) or (a, b, b)
        for (auto itr = counter.begin(); itr != counter.end(); itr++) {
            if (itr->first && itr->second >= 2 && counter.count(-2 * itr->first)){
                vector<int> cur = {itr->first, itr->first, -2 * itr->first};
                res.push_back(cur);
            }
        }
        if (counter[0] >= 3){
            res.push_back(vector<int>(3,0));
        }
        return res;

// O(n^2) a slow one
// Faster than 7%

        // unordered_map <int, int> allNum;
        // unordered_set <string> added; 
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> res;
        // for (int i=0; i<nums.size(); i++){
        //     // for dulplicates, only count the largest index
        //     allNum[nums[i]] = i;
        // }
        // for (int i=0; i<nums.size(); i++){
        //     for (int j=i+1; j<nums.size(); j++){
        //         if (i && nums[i-1] == nums[i])
        //             continue;
        //         if (allNum.count(-nums[i]-nums[j])) {
        //             int k = allNum[-nums[i]-nums[j]];
        //             string hash_code = to_string(nums[i]) + " " + to_string(nums[j]);
        //             if (k > j && !added.count(hash_code)) {
        //                 vector<int> cur = {nums[i], nums[j], nums[k]};
        //                 res.push_back(cur);
        //                 added.insert(hash_code);
        //             }
        //         }
        //     }
        // }
        // return res;
    }
};
