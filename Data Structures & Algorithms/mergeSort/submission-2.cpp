// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };



class Solution {
private:
    void sortRange(vector<Pair>& pairs, int l, int r, vector<Pair>& tempBuf) {
        if (r - l <= 1) return; // sorted once we have size 1

        int m = l + (r - l) / 2; // midpt, or start idx of right sub-list

        // one call of sortRange for each half
        // [l m) is left sub-list, [m r) is right
        sortRange(pairs, l, m, tempBuf);
        sortRange(pairs, m, r, tempBuf);

        // both halves are now sorted, now we need to merge them
        mergeRanges(pairs, l, m, r, tempBuf);
    }

    void mergeRanges(vector<Pair>& pairs, int l, int m, int r, vector<Pair>& tempBuf) {
        // read left half [l m), read right half [m, r)
        // write into tempBuf starting at l
        // compare keys at the two read indices
        int leftRead = l;
        int rightRead = m;
        int writeIdx = l;

        while (leftRead < m && rightRead < r) {
            if (pairs.at(rightRead).key < pairs.at(leftRead).key) {
                tempBuf.at(writeIdx) = pairs.at(rightRead);
                rightRead++;
            }
            else {
                tempBuf.at(writeIdx) = pairs.at(leftRead);
                leftRead++;
            }
            writeIdx++;
        }

        while (leftRead < m) {
            tempBuf.at(writeIdx) = pairs.at(leftRead);
            leftRead++;
            writeIdx++;
        }
        while (rightRead < r) {
            tempBuf.at(writeIdx) = pairs.at(rightRead);
            rightRead++;
            writeIdx++;
        }

        // now we have filled out tempbuf between l and r, so update pairs in that range
        for (int i=l; i<r; i++) {
            pairs.at(i) = tempBuf.at(i);
        }

    }

public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        // first function: separate into two sub-lists until each is size 1 (sorted).
        // middle index m = L+(R-L)/2, which rounds down for odd n.
        // need recursive helpers, sortRange() and mergeRanges()

        vector<Pair> tempBuf = pairs;
        int l = 0;
        int r = pairs.size(); // exclusive end; size = r - l

        sortRange(pairs, l, r, tempBuf);

        return pairs;
    }
};
