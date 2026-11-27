class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // return indices [i, j]
        // condition: num[i]+num[j]==target and i<j (i!=j)
        // we should start with i=0, j=1 for initial loop pos
        // want to find/identify num[i]=target-num[j] or num[j]=target-num[i]
        // at least 2 numbers, and they can be negative (so can target)
        // aim for O(n) time (single pass) and O(1) space (no vector copy)

        // use unordered map so we can keep track of prev values and index
        // finding a prev value in this should be ~O(1) on avg
        // <key, value> should be set up as <num, index>
        unordered_map<int,int> idxMap;
        vector<int> foundIdxs;

        // as we loop once, keep track of unique values and their idx
        for (int i=0; i<numbers.size(); i++) {
            // first see if target value is in map, return valid idxs if so
            int currDiff = target-numbers[i];
            auto foundItr = idxMap.find(currDiff);
            if (foundItr != idxMap.end()) {
                // we found a matching num, return the idx values
                foundIdxs = {foundItr->second+1, i+1};
                break; // should go right to return after loop
            }
            idxMap.insert({numbers.at(i), i}); // add new num/idx pair to map
        }

        return foundIdxs;
    }
};
