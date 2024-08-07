






Input: nums = [1,1,0,1,1,1]
Output: 3













TIME COMPLEXITY O(n)


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        int maxi =0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 1)
            {
                c++;
                maxi = max(c,maxi);
            }
            else
            {
                c=0;
            }
        }
        return maxi;
    }
};


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int store = 0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                store++;
                maxi = max(maxi,store);
            }
            if(nums[i+1] == 0)
            {
                store = 0;
            }
        }
        return maxi;
    }
};