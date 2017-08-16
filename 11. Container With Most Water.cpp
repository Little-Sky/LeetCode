// O(n) one iteration
// Faster than 24% - 44%

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int le=0, ri=height.size()-1;
        while (le < ri){
            int cur_area = (ri - le) * min(height[le], height[ri]);
            area = max (area, cur_area);
            if (height[le] == height[ri]){
                le ++;
            } else if (height[le] < height[ri]){
                int cur_min = height[le];
                while (le < ri && height[le] <= cur_min){
                    le++;
                }
            } else {
                int cur_min = height[ri];
                while (le < ri && height[ri] <= cur_min){
                    ri--;
                }
            }
        }
        return area;
    }
};
