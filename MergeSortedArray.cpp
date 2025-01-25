/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. 

nums2 has a length of n. */


#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int last = m + n - 1;
    int first = m - 1;
    int second = n - 1;
    if (n == 0)
    {
        return;
    }
    else if (m == 0 || nums1[first] < nums2[0])
    {
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
    } else {
        while (second >= 0)
        {
            if (nums1[first] < nums2[second])
            {
                nums1.at(last) = nums2.at(second);
                nums2.pop_back();
                last--;
                second--;
            } else {
                nums1.at(first + 1) = nums1.at(first);
                nums1.at(first) = nums1.at(first - 1);
                last--;
                first--;
            }
        }
    }
}

int main() {

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};

    vector<int> nums2 = {2, 5, 6};

    merge(nums1, 3, nums2, 3);

    cout << "Doing first test case! " << endl;

    for (auto i : nums1)
    {
        cout << i << " ";
    }

    cout << endl;

    nums1 = {1};

    nums2 = {};

    merge(nums1, 1, nums2, 0);

    cout << "Doing second test case! " << endl;

    for (auto i : nums1)
    {
        cout << i << " ";
    }
    cout << endl;

    nums1 = {0};

    nums2 = {1};

    merge(nums1, 0, nums2, 1);

    cout << "Doing third test case! " << endl;

    for (auto i : nums1)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}