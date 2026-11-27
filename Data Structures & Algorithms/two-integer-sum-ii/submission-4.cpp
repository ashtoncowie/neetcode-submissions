class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // return indices [i, j]
        // condition: num[i]+num[j]==target and i<j (i!=j)
        // we should start with i=0, j=1 for initial loop pos
        // want to find/identify num[i]=target-num[j] or num[j]=target-num[i]
        // at least 2 numbers, and they can be negative (so can target)
        // aim for O(n) time (single pass) and O(1) space (no map or copy)

        // array is already sorted!
        // use two index vars, front (lowest) and back (highest)
        // initialize as i=0 and j=numbers.size()-1
        // e.g. [1 4 6 8 12]: <low,hi> <1,12> sum = 13
        // while condition is (back > front)
        // we increment front when
        // we decrement back when
        
        int i=0;
        int j=numbers.size()-1;

        // move indices closer together until they're equal
        while (j>i) {
            int currSum = numbers[i] + numbers[j];
            if (currSum == target) return {i+1, j+1};
            // since sorted, if > target, i++ would still be > target
            if (currSum > target) j--;
            if (currSum < target) i++;
        }
        return {0,0};
    }
};
