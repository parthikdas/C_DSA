// Smallest missing +ve no in unsorted array
/* Approach 1
	Time complexity:O(nlogn)+O(n)[O(nlogn for sorting and O(n)for iteration)].
	Space complexity:O(n) [As we are not using any extra space].
	Intutuion:As we have to calculate the first missing positive integer,and the smallest positive integer is 1.
			  So, take ans=1 and iterate over the array once and check wheather nums[i]==ans (means we are cheacking for value from 1 upto missing number). By iterating if that condition mate where nums[i]==ans then increamnet ans by 1 and again check for the same condition uptill size of the array. After one scan of array we got the missing number stored in ans variable.

	int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ans)
                ans++;
        }
        return ans;
    }
*/

/* Approach 2
	we have created a list full of 0’s with size of the max() value of our given array. Now, whenever we encounter any positive value in our original array, we change the index value of our list to 1. So, after we are done, we simply iterate through our modified list, the first 0 we encounter, its (index value + 1) should be our answer since index in python starts from 0.

	int firstMissingPos(int A[], int n) {
	    bool present[n + 1] = { false }; // To mark the occurrence of elements
	    // Mark the occurrences
	    for (int i = 0; i < n; i++) {
	        // Only mark the required elements. All non-positive elements and the elements greater n + 1 will never be the answer. For example, the array will be {1, 2, 3} in the worst case and the result will be 4 which is n + 1
	        if (A[i] > 0 && A[i] <= n)
	            present[A[i]] = true;
	    }
	    // Find the first element which didn't appear in the original array
	    for (int i = 1; i <= n; i++)
	        if (!present[i])
	            return i;
	    // If the original array was of the type {1, 2, 3} in its sorted form
	    return n + 1;
	}
*/
