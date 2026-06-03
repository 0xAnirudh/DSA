class Solution {
public:

    int isPossible(vector<int>& nums, int n, int k, int mid)
    {
        int count = 1;
        int pageSum = 0;

        for (int i = 0; i < n; i++)
        {
            if(pageSum + nums[i] <= mid)
            {
                pageSum += nums[i];
            }

            else
            {
                count++;
                if (count > k || nums[i] > mid)
                {
                    return false;
                }
                pageSum = nums[i];
            }
        }  
        return true;
    }

    int splitArray(vector<int>& nums, int k)
    {
        int n = nums.size();
        int sum = 0;

        for(auto i : nums) sum += i;

        int s = 0;
        int e = sum;
        int ans = -1;
        int mid = s + (e - s)/2;

        for ( ; s <= e; )
        {
            if (isPossible(nums, n, k, mid))
            {
                ans = mid;
                e = mid -1;
            }

            else 
            {
                s = mid + 1;
            }

            mid = s + (e - s)/2;
        }

        return ans;
    }
};