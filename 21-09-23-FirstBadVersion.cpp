/*
// https :  // leetcode.com/problems/first-bad-version/description/

Time: O(log n)  n == strs.size()
Space: O(1)

*/

class Solution {
   public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int firstBadVersion = n;

        while (left <= right) {
            int midPoint = left + (right - left) / 2;

            if (isBadVersion(midPoint)) {
                if (firstBadVersion > midPoint) {
                    firstBadVersion = midPoint;
                }
                right = midPoint - 1;
            } else {
                left = midPoint + 1;
            }
        }

        return firstBadVersion;
    }
};
