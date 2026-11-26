class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // early return cases: empty strs or single element
        vector<vector<string>> anagrams;

        if (strs.empty()) {
            anagrams.push_back({""});
            return anagrams;
        }
        if (strs.size() == 1) {
            anagrams.push_back({strs.at(0)});
            return anagrams;
        }

        // still need to push_back() a str alone to a vec if it doesn't have an anagram
        // anagram: all letters in a str have same freqs as those in a different str

        // create map with key = freq map of word, value is vector of itself+anagrams
        unordered_map<string, vector<string>> freqMap;

        for (string s : strs) {
            int alphaFreq[26] = {0}; // char freq map, refreshed for each str
            for (char c : s) {
                alphaFreq[c - 'a']++; // increment count of each char idx
            }
            // now we have int array freq map for string s. insert into map
            string freqKeyStr = "";
            for (int i=0; i<26; i++) {
                freqKeyStr.append(to_string(alphaFreq[i]));
                freqKeyStr.append(","); // separator for each letter
            }
            // now freq array is a string with comma separator for each letter's freq
            
            // we will append s to map value vector if key found, otherwise add new pair
            auto foundItr = freqMap.find(freqKeyStr);
            if (foundItr != freqMap.end()) {
                // we found an existing key, so append s to the pair's value vector
                foundItr->second.push_back(s);
            }
            else {
                // we did not find an existing key, so add pair to map for future checks
                freqMap.insert({freqKeyStr, {s}});
            }
        }
        // finally, push each vector of strings into the return list of vectors
        for (auto itr = freqMap.begin(); itr != freqMap.end(); itr++) {
            anagrams.push_back(itr->second);
        }

        return anagrams;
    }
};
