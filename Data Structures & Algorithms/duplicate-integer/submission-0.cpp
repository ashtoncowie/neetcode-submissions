class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // default return false, unless we find dup.
        // recommended O(n) so 1 time through array (no nested loop)
        // we will build an unordered_set as we iterate once through vector
        // if ith value is present (count>0) we return true
        unordered_set<int> present_nums;

        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (present_nums.contains(*it)) return true; // duplicate found
            else present_nums.insert(*it); // add new value to set
        }
        return false; // no duplicate was found
    }
};