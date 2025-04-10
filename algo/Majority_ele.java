/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
import java.util.*;
public class Majority_ele {
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the elements of the array: ");
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }
        int res1=majorityElement(arr);
        System.out.println(res1);
        int res2=majorityElement_m2(arr);
        System.out.println(res2);
        int res3=majorityElement_m3(arr);
        System.out.println(res3);
        int res4=majorityElement_m4(arr);
        System.out.println(res4);
    }
    //------------------Brute force approach(O(n^2))------------------------------------
    public static int majorityElement(int[] nums) {
      
        int n=nums.length;
        int max=0,ele=nums[0];
        for(int i=0;i<nums.length;i++)
        {
            int count=0;
            for(int j=i;j<nums.length;j++)
            {
                if(nums[i]==nums[j])
                    count++;
            }
            if(count>max)
            {
                max=count;
                ele=nums[i];
            }
        }
        if(max>=(int)(n/2))
            return ele;
        
        return -1;
    }
//-------------------------------Sorting method: time comp:(nlogn+n)= O(nlogn)  space comp:O(1)------------------------------------------
    public static int majorityElement_m2(int nums[])
    {
            Arrays.sort(nums);
            return nums[nums.length/2];
    }
    //----------------------------HashMap: time comp: O(n)  space comp: O(n)-------------------------------------------------------------
    public static int majorityElement_m3(int[] nums) {
        
        HashMap<Integer,Integer> hm=new HashMap<>();
        
        for(int i=0;i<nums.length;i++)
        {
            if(hm.containsKey(nums[i]))
                hm.put(nums[i] , hm.get(nums[i])+1);
            else
                hm.put(nums[i],1);
        }
        int answer =0;
     for (Map.Entry<Integer, Integer> entry : hm.entrySet())
     {
         if(entry.getValue()>nums.length/2)
         {
             answer = entry.getKey();
         }
     }
    return answer;
    }
    //----------------------------Boyer-Moore Majority Voting Algorithm  time comp: O(n)    space comp: O(1)------------------------------
    public static int majorityElement_m4(int[] nums) {
        int ans=nums[0];
        int count=1;
        for(int i=1;i<nums.length;i++)
        {
                if(nums[i]==ans)
                    count++;
                else
                    count--;
            
        if(count==0)
        {
             ans=nums[i];
            count=1; 
        }
          
        }
        return ans;
        
    }
}