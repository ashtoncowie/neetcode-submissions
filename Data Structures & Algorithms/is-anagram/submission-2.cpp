class Solution {
public:
    bool isAnagram(string s, string t) {
        int alpha[26];

        for (char c : s) alpha[c - 'a']++;
        for (char c : t) alpha[c - 'a']--;

        for (int i : alpha) {
            if (i != 0) return false; // at least one letter had multiple
        }

        return true; // array is all zeros, so all letters have equal #
    }
};
