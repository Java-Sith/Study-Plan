/* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 

The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 

The remaining elements of nums are not important as well as the size of nums. Also return k.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0;
    int last = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (last == k)
        {
            break;
        }
        else if (nums[i] == val)
        {
            int temp = nums.at(i);
            while (nums[last] == val)
            {
                last--;
            }
            nums.at(i) = nums.at(last);
            nums.at(last) = temp;
            k++;
        } else {
            k++;
        }
    }
    return k;
}

int main() {

    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};    

    int val = 2;

    vector<int> expectedNums = {0, 1, 4, 0, 3};

    int k = removeElement(nums, val);

    assert(k == expectedNums.size());

    //sort(nums.begin(), nums.begin() + k);

    for (int i = 0; i < k; i++)
    {
        assert(nums[i] == expectedNums[i]);
    }

    cout << "All test cases pass!" << endl;

    return 0;
}