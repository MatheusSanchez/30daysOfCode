
/*
    Time: O(n); n == nums.size()
    Space: O(1);
  https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array/
*/
class Solution {
   public:
    int minimumRightShifts(vector<int>& nums) {
        int pivots = 0;
        int rightShifts = 0;

        if (nums.size() == 1) {
            return 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[(i + 1) % nums.size()]) {
                pivots++;
                rightShifts = nums.size() - i - 1;
            }
        }

        if (pivots == 1) {
            return rightShifts;
        }

        return -1;
    }
};