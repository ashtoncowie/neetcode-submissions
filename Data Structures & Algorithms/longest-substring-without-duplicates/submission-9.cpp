class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // return an int that is length of longest substr (continous chunk)
        // *without duplicate chars* so freq>1 of a char in a substr dq's it
        // O(n) time: one loop through s; O(m) space: max size is our substr
        int maxLen = 1;

        // early return cases: < 2 chars
        if (s.empty()) return 0;
        if (s.size() == 1) return 1; // double check if substr can be s

        unordered_map<char,int> seenMap; // <key, value> is <s.at(i), i>
        int left = 0; // index that represents beginning of substr

        // single pass through s (check if we start at i=1)
        for (int i=0; i<s.size(); i++) {
            // keep track of the longest substr we've found so far.
            // if we see a letter is already present in the substr we're
            // constructing, then update left idx *after* the position
            // of the offending (duplicate) letter, if we have space.
            // ex. [a b w b k o] we get up to [a b w] (left=0, i=2) then
            // need to update to just [w] (left=2, i=2) before next iter

            auto found = seenMap.find(s.at(i));
            if (found != seenMap.end() && found->second >= left) {
                // we found a duplicate. reset substr to start after dup idx
                int dupIdx = found->second;
                left = dupIdx+1;
            }
            seenMap[s.at(i)] = i; // update latest index for curr char
            int currLen = i-left+1;
            if (currLen > maxLen) maxLen = currLen;
        }

        return maxLen;
    }
};
