class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // find i and j such that i!=j and nums[i] + nums[j] == target
        // exactly one pair that satisfies this condition
        // return smaller index first

        // create table with value = index and key = num
        unordered_map<int, int> seen;

        for (int i=0; i<nums.size(); i++) {
            // look through map for value that would satisfy equation
            // if found, return that index (after combining with other idx)
            
            // find a key num in seen that equals (target - nums[i])
            auto found = seen.find(target - nums.at(i)); // returns itr otherwise .end()
            
            // store the index of found num if present then return pair
            if (found != seen.end()) return {found->second, i};

            seen.insert({nums.at(i), i}); // if not found, insert to map for next check
        }

        return {};
    }
};
