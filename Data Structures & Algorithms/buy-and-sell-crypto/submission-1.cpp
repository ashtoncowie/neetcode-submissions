class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // can select one integer from the array, aiming for smallest
        // such that an integer later in the array has the biggest diff.
        // you can choose to not make any transactions (if only <0 options)
        // aim for O(n) time and O(1) space (iterate once through prices)

        // store a min value (bestPrice) to be updated as we loop
        // if we find a new higher profit, update it
        // if we find a new min, update it
        // make sure sell > buy (otherwise 0 profit / initial is ideal)

        int maxProfit = 0;
        int bestPrice = prices.at(0);

        for (int i = 1; i < prices.size(); i++) {
            int currPrice = prices.at(i);

            if ((currPrice - bestPrice) > maxProfit) {
                maxProfit = currPrice - bestPrice;
            }
            if (currPrice < bestPrice) bestPrice = currPrice;
        }

        return maxProfit;
    }
};
