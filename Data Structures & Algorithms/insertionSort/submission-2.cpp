// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        // we are given a ref to a vector (list) of pairs, need to sort by key.
        // if two(or more?) pairs have the same key, keep the same order
        // should be pairs.length() # of states total (we could use outer for loop?)
        // -----
        // return list of lists, each sub-list is state of the array after an insertion
        // so we append/push_end the current list at each sort step

        vector<vector<Pair>> stateList;

        if (pairs.empty()) return stateList;

        // first output row (i=0) is initial list of pairs
        stateList.push_back(pairs);

        // first pair is now sorted. move onto next pairs
        for (int i = 1; i < pairs.size(); i++) {
            int j = i;
            while (j > 0 && pairs.at(j).key < pairs.at(j-1).key) {
                swap(pairs.at(j), pairs.at(j-1));
                j--;
            }
            stateList.push_back(pairs);
        }

        return stateList;
    }
};
