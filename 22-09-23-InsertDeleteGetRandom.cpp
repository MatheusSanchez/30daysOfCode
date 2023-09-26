/*
    Time: O(1)
    Space: O(1)
    https://leetcode.com/problems/insert-delete-getrandom-o1/description/
*/

class RandomizedSet {
   public:
    unordered_set<int> randomSet;

    RandomizedSet() { return; }

    bool insert(int val) {
        if (randomSet.find(val) == randomSet.end()) {
            randomSet.insert(val);
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (randomSet.find(val) != randomSet.end()) {
            randomSet.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {  // O (1)  ????????????????????????????
        int sizeSet = randomSet.size();
        int ramdomElement = random() % sizeSet;

        for (auto u : randomSet) {
            if (ramdomElement == 0) {
                return u;
            }

            ramdomElement--;
        }
        return 0;
    }
};
