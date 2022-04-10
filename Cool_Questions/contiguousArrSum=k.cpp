/*Given an unsorted array A of size N of non-negative integers, find a continuous
subarray which adds to a given number S.

Constraints
1 <= N <= 10^5
0 <= Ai <= 10^10

Example
Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements from 2nd position to 4th position is 12.*/

/* 1st Approach:
->Time Complexity: O(n^2) in worst case. 
->Nested loop is used to traverse the array so the time complexity is O(n^2)
->Space Complexity: O(1). 
->As constant extra space is required.

    int subArraySum(int arr[], int n, int sum) {
        for (int i = 0; i < n; i++) {
            int cur_sum = arr[i];
            for (j = i + 1; j <= n; j++) { // try all subarrays starting with 'i'
                if (curr_sum == sum) {
                    cout << "Sum found between indexes "
                         << i << " and " << j - 1;
                    return 1;
                }
                if (curr_sum > sum || j == n)
                    break;
                curr_sum = curr_sum + arr[j];
            }
        }

        cout << "No subarray found";
        return 0;
    }
*/

/* 2nd Approach
->Time Complexity : O(n). 
->Only one traversal of the array is required. So the time complexity is O(n).
->Space Complexity: O(1). 
->As constant extra space is required.

    #include <iostream>
    using namespace std;
    int subArraySum(int arr[], int n, int sum) {
        // Initialize curr_sum as value of first element and starting point as 0 
        int curr_sum = arr[0], start = 0, i;
        // Add elements one by one to curr_sum and if the curr_sum exceeds the sum, then remove starting element 
        for (i = 1; i <= n; i++) {
            // If curr_sum exceeds the sum, then remove the starting elements
            while (curr_sum > sum && start < i - 1) {
                curr_sum = curr_sum - arr[start];
                start++;
            }
            // If curr_sum becomes equal to sum, then return true
            if (curr_sum == sum) {
                cout << "Sum found between indexes " << start << " and " << i - 1;
                return 1;
            }
            // Add this element to curr_sum
            if (i < n) curr_sum = curr_sum + arr[i];
        }
        // If we reach here, then no subarray
        cout << "No subarray found";
        return 0;
    }
    int main()
    {
        int arr[] = { 1,2,3,7,5 };
        int n = sizeof(arr) / sizeof(arr[0]);
        int sum = 12;
        subArraySum(arr, n, sum);
        return 0;
    }
*/

/* 3rd Approach
->Time complexity: O(N). 
->If hashing is performed with the help of an array, then this is the time complexity. In case the elements cannot be hashed in an array a hash map can also be used as shown in the above code.
->Auxiliary space: O(n). 
->As a HashMap is needed, this takes linear space.

    #include<bits/stdc++.h>
    using namespace std;
    // Function to print subarray with sum as given sum
    void subArraySum(int arr[], int n, int sum){
        // create an empty map
        unordered_map<int, int> map;

        // Maintains sum of elements so far
        int curr_sum = 0;

        for (int i = 0; i < n; i++)
        {
            // add current element to curr_sum
            curr_sum = curr_sum + arr[i];

            // if curr_sum is equal to target sum
            // we found a subarray starting from index 0
            // and ending at index i
            if (curr_sum == sum)
            {
                cout << "Sum found between indexes "
                     << 0 << " to " << i << endl;
                return;
            }

            // If curr_sum - sum already exists in map
            // we have found a subarray with target sum
            if (map.find(curr_sum - sum) != map.end())
            {
                cout << "Sum found between indexes "
                     << map[curr_sum - sum] + 1
                     << " to " << i << endl;
                return;
            }

            map[curr_sum] = i;
        }

        // If we reach here, then no subarray exists
        cout << "No subarray with given sum exists";
    }
    int main()
    {
        int arr[] = {10, 2, -2, -20, 10};
        int n = sizeof(arr)/sizeof(arr[0]);
        int sum = -10;

        subArraySum(arr, n, sum);

        return 0;
    }
*/