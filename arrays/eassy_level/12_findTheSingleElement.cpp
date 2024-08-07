





Problem statement:-

**FIND THE NUMBER THAT APPEARS ONCE, AND THE OTHER NUMBERS TWICE**

You are given a sorted array 'arr' of positive integers of size 'n'.
It contains each number exactly twice except for one number, which occurs exactly once.
Find the number that occurs exactly once

Input: nums = [2,2,1]
Output: 1







brute aproach:-
time complexity is O(n^2)

#include<vector>
int getSingleElement(vector<int> &arr){
	// Write your code here.
	int n = arr.size();	
	int flag =0;
	int temp;
	for(int i=0;i<n;i++)
	{
		temp = arr[i];
		int c=0;  					//we have to reset the value of c
		for(int j=0;j<n;j++)
		{
			if(temp == arr[j])
			{
				c++;
			}
		}
		if(c==1)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1) return temp;
}


method 2:-
better approach:-  array hashing

but while submitting it gives us time limiting exceed but still
time complexity of this code of O(n)
and the extra space complexity is O(maxElement in given array)

#include<vector>
int getSingleElement(vector<int> &arr){
	int n = arr.size();
	// int maxi = *max_element(arr.begin(), arr.end()); // Use max_element properly to find the maximum element // by this it give direct maximum element
	int maxi = arr[0];
	for(int i=0;i<n;i++)
	{
		maxi = max(maxi,arr[i]);
	}
	int hash[maxi + 1] = {0};
	for(int i=0;i<n;i++)
	{
		hash[arr[i]]++;
	}

	for(int i=0;i<=maxi;i++)
	{
		if(hash[i] == 1) return i;
	}
}

in the above code there is some limitation that 
1. we can not afford negative value in the given array
2. the no of values in the given arrays is in the boundary of hash array

to avoid this type of problem we are using map data structure:-

Therefore, the overall time complexity of the getSingleElement function is O(n log n),
where n is the size of the input vector arr.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;				//it is taking O(log n) time complexity
        }
        for(auto it : mpp)
        {
            if(it.second == 1) return it.first;
        }
        return -1;
    }
};

	WE CAN ALSO USE unordered_map TO DECREASE TIME COMPLEXITY


method 3:-
optimal solution
time complexity O(n)
extra space complexity is O(1)

#include <bits/stdc++.h>>
#include<vector>

int getSingleElement(vector<int> &arr){
	int Xor1 = 0;
	for(int i=0;i<arr.size();i++)
	{
		Xor1 = Xor1 ^ arr[i];
	}
	return Xor1;
}

another optimal solution for this particular problem
time complexity is O(n)
and extra space complexity of O(1)

#include<vector>
int getSingleElement(vector<int> &arr){
	// Write your code here.	
	int n=arr.size();
	for(int i=0;i<n;)
	{
		if(arr[i] == arr[n-1])
		{
			return arr[i];
		}
		else if(arr[i] == arr[i+1])
		{
			i=i+2;
		}
		else
		{
			return arr[i];
		}
	}
}

modified version of above 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int i;
        sort(nums.begin(),nums.end());
        for(i=1 ; i<n ;){
            if(nums[i] != nums[i-1]){
               return nums[i-1];
            }
            i+=2;
        }
       return nums[n-1];
    }
}