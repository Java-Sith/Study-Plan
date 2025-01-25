/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

//Get the minimal element in the array
int minElement(int* prices, int pricesSize) { 
    int min = prices[0];
    int k = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            k = i;
        }
    }
    return k;
}

int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;
    int min = minElement(prices, pricesSize);
    for (int i = min; i < pricesSize; i++)
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

int maxProfit2(int* prices, int pricesSize) {
    int maxProfit = 0;
    int min = minElement(prices, pricesSize);
    for (int i = min + 1; i < pricesSize; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    return maxProfit;
}

int main () {

    int nums[] = {7, 1, 5, 3, 6, 4};

    int length = sizeof(nums) / sizeof(nums[0]);

    int profit = maxProfit2(nums, length);

    printf("Maximum profit: %d\n", profit);

    return 0;
}