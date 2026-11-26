class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // early return case
        if (nums.size() == 1) return {nums.at(0)};
        
        int maxFreq = 0; // keep track of max freq for later use

        // make a map with key=num, value=freq
        unordered_map<int, int> freqMap;
        for (auto itr = nums.begin(); itr != nums.end(); itr++) {
            // if key (*itr) is present, increment corresponding freq value
            // else, insert key into map with freq value = 1
            auto foundItr = freqMap.find(*itr);
            if (foundItr != freqMap.end()) {
                // key already present, increment freq
                foundItr->second++;
                if (foundItr->second > maxFreq) maxFreq = foundItr->second;
            }
            else {
                // insert new key value pair to map
                freqMap.insert({*itr, 1});
                if (*itr > maxFreq) maxFreq = *itr;
            }
        }
        // now we have a completed unordered freq map.
        // last step is to find the k highest freqs and return their keys as a vector
        // highest possible freq is n for size n vector
        vector<pair<int, int>> pairVec; // freq, num
        vector<int> mostFreqValues;

        for (auto itr = freqMap.begin(); itr != freqMap.end(); itr++) {
            pairVec.push_back({itr->second, itr->first});
        }

        sort(pairVec.begin(), pairVec.end()); // now sorted by freq instead of num. we can start from back now

        for (int i=0; i<k; i++) {
            pair currPair = pairVec.at(pairVec.size()-1-i);
            mostFreqValues.push_back(currPair.second);
        }

        return mostFreqValues;
    }
};
