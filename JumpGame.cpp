/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hasZeroes(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            return true;
        }
    }
    return false;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

bool canJump(vector<int>& nums) {
    int maxReach = nums[0];
    int finalIndex = nums.size() - 1;
    if (!hasZeroes(nums))
    {
        return true;
    }
    while (nums[finalIndex - 1] > 0)
    {
        finalIndex--;
    }
    for (int i = 0; i < finalIndex; i++)
    {
        maxReach = nums[i];
        if (i > maxReach)
        {
            return false;
        }
        if (maxReach >= (finalIndex - i))
        {
            return true;
        }
    }
    return false;
}

int main() {

    //vector<int> nums = {1, 1, 2, 5, 2, 1, 0, 0, 1, 3};

    //vector<int> nums = {3, 2, 1, 0, 4};
    
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << boolalpha; 

    cout << canJump(nums) << endl;

    return 0;
}