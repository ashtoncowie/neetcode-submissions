class Solution {
public:
    bool isPalindrome(string s) {
        // definition of palindrome: forwards = backwards
        // s[0] = s[(n-1)-0], s[1] = s[(n-1)-1], etc
        // where n = s.size()
        // could use a front and back index, moving them closer until they're equal

        // first build a string that's only alphanumeric and lowercase
        string s2;
        for (char c : s) {
            if (isalnum(c)) s2.push_back(tolower(c));
        }

        int frontIdx = 0;
        int backIdx = s2.size()-1;

        // ex. racecar (n=7): s2[0]==s2[n-1], s2[1]==s2[n-2], ... s2[3]==s2[n-4]
        // while loop should be frontIdx <= backIdx so we handle odd length (common middle char)
        // but it shouldn't matter actually- middle char doesn't determine whether it's a palindrome, we would already know at that point. so < is fine

        if (s2.size() <= 1) return true; // "a" and "" both palindromes (?)

        while (frontIdx < backIdx) {
            if (s2.at(frontIdx) != s2.at(backIdx)) return false;
            frontIdx++;
            backIdx--;
        }
        return true; // each front letter had a matching back letter
    }

};
