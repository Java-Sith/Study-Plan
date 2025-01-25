/*

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

A good hint is to reverse the array or parts of it.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void reverse(vector<int>& nums, int start, int end) {
    while (start < end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(vector<int>& nums, int k) {
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}

int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    int k = 3;

    vector<int> expectedNums = {5, 6, 7, 1, 2, 3, 4};

    rotate(nums, k);

    for (int i = 0; i < expectedNums.size(); i++)
    {
        assert(nums[i] == expectedNums[i]);
    }
    
    cout << "All tests passed!" << endl;

    return 0;
}