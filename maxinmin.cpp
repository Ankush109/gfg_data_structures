 class Solution {
public:
    int findMaxK(vector<int>& nums) {
      
 
    int res = -1;
 
  
    sort(nums.begin(), nums.end());
 

    int l = 0, r = nums.size() - 1;
 

    while (l < r)
    {
         
       
        int sum = nums[l] + nums[r];

        if (sum == 0)
        {
            res = max(res, max(nums[l], nums[r]));
            return res;
        }
 
      
        else if (sum < 0)
        {
            l++;
        }
 
       
        else
        {
            r--;
        }
    }
    return res;
      
    }
 
};
