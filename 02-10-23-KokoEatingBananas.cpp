/*
Time:  O( n log m )  m = maxBananas,  n = piles.size()
Space: O(1)
https://leetcode.com/problems/koko-eating-bananas/

*/

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minBananas = 1;
        int maxBananas = -1;

        for (int i = 0; i < piles.size(); i++) {
            if (maxBananas < piles[i]) {  //
                maxBananas = piles[i];
            }
        }

        while (minBananas <= maxBananas) {
            int mid = minBananas + (maxBananas - minBananas) / 2;
            long long hours = calcHours(piles, mid);

            if (hours > h) {
                minBananas = mid + 1;
            } else {
                maxBananas = mid - 1;
            }
        }

        return minBananas;
    }

    long long calcHours(vector<int>& piles, int bananasPerHour) {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / bananasPerHour;
            if (piles[i] % bananasPerHour != 0) {
                hours++;
            }
        }

        return hours;
    }
};