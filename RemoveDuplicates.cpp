/*

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 

The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, return k to finish.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 0;
    int pivot = nums[0];
    int count = 0;
    if (nums.size() == 0)
    {
        return 0;
    } else {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != pivot)
            {
                pivot = nums[i];
                k++;
                count = 0;
                nums[k] = pivot;
            } else {
                count++;
                if (count <= 1)
                {
                    k++;
                    nums[k] = pivot;
                }
            }
        }
    }
    return k + 1;
}

int main() {

    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};    

    vector<int> expectedNums = {0, 0, 1, 1, 2, 3, 3};

    int k = removeDuplicates(nums);

    cout << "k: " << k << endl;

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << endl;
    }

    assert(k == expectedNums.size());

    for (int i = 0; i < k; i++)
    {
        assert(nums[i] == expectedNums[i]);
    }

    cout << "All test cases pass!" << endl;

    return 0;
}