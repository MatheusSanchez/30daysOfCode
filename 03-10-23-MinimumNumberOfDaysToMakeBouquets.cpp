/*
    Time: O(n log m)  n = bloomDay.size() m = bigger day
    Space: O(1)
    https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/
*/

class Solution {
   public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minDays = INT_MAX;
        int maxDays = INT_MIN;

        for (int i = 0; i < bloomDay.size(); i++) {  // O(n)
            if (bloomDay[i] < minDays) {
                minDays = bloomDay[i];
            }

            if (bloomDay[i] > maxDays) {
                maxDays = bloomDay[i];
            }
        }

        int ans = -1;

        while (minDays <= maxDays) {  // O(log n) ------------------ //

            int mediumDays = (minDays + maxDays) / 2;
            int howMany = howManyBouquets(bloomDay, mediumDays, k);  // O(n)

            if (howMany >= m) {
                maxDays = mediumDays - 1;
                ans = mediumDays;
            } else {
                minDays = mediumDays + 1;
            }
        }

        return ans;
    }

    int howManyBouquets(vector<int>& bloomDay, int days, int k) {
        int flowersAdj = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days) {
                flowersAdj++;
            } else {
                flowersAdj = 0;
            }

            if (flowersAdj == k) {
                bouquets++;
                flowersAdj = 0;
            }
        }

        return bouquets;
    }
};