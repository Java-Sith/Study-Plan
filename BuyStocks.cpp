/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Get the minimal element in the array
int minElement(vector<int>& prices) {
    int min = prices[0];
    int k = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            k = i;
        }
    }
    return k;
}

//Get the maximal element in a comparison
int max(int a, int b) { 
    return (a > b) ? a : b;
}

int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int min = minElement(prices);
    for (int i = min; i < prices.size(); i++)
    {
        maxProfit = max(maxProfit, prices[i] - prices[min]);
    }
    return maxProfit;
}

/*
Part Two: On each day, you may decide to buy and/or sell the stock. 

You can only hold at most one share of the stock at any time. 

However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 */

int maxProfit2(vector<int>& prices) {
    int maxProfit = 0;
    int min = minElement(prices);
    for (int i = min + 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    return maxProfit;
}

int main() { 

    vector<int> prices = {1, 4, 7, 8, 6, 4};

    int profit = maxProfit2(prices);

    cout << "Maximum profit: " << profit << endl;

    return 0;
}