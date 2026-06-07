class Solution {
public:
    // long long ans = LLONG_MIN;
    // void solve (vector<int> &nums, int m, int l, int r, int idx, int count, long long sum){
    //     int n = nums.size();
    //     if (count >= 1) ans = max(ans, sum);
    //     if (count == m || idx >= n) return;

    //     for (int i = idx; i < n; i++){
    //         long long sub = 0;

    //         for (int len = 1; len <= r && i + len <= n; len++) {
    //             sub += nums[i + len - 1];
    //             if (len >= l)
    //                 solve (nums, m, l, r, i + len, count + 1, sum + sub);
    //         }
    //     }
    // }
    // long long maximumSum(vector<int>& nums, int m, int l, int r) {
    //     solve (nums, m, l, r, 0, 0, 0);
    //     return ans;
    // }
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        long long ans = LLONG_MIN;

        vector <long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        vector<vector<long long>> dp(n + 1, vector<long long> (m + 1, LLONG_MIN / 2));
        
        for (int idx = 0; idx <= n; idx++) dp[idx][0] = 0;
        
        for (int count = 1; count <= m; count++){
            deque<int>dq;
            for(int idx = 1; idx <= n; idx++){
                    // dp[idx][count] = max(dp[idx - 1][count], dp[idx][count - 1]);
                    dp[idx][count] = dp[idx - 1][count];
    
                    int add = idx - l;
                if(add >=0 && dp[add][count -1] != LLONG_MIN/2){
                    while ( !dq.empty() && dp[dq.back()][count - 1] - pre[dq.back()] <= dp[add][count-1] - pre[add])
                        dq.pop_back();
                    dq.push_back(add);
                }
                
                while (!dq.empty() && dq.front() < idx - r)
                    dq.pop_front();

                if(!dq.empty()){
                        long long sum = dp [dq.front()][count-1] - pre[dq.front()] + pre[idx];
                        dp[idx][count] = max (dp[idx][count], sum);
                }
            }
        }
        for (int idx = 1; idx <= n; idx++)
            for (int count = 1; count <= m; count++)
                if(dp[idx][count] != LLONG_MIN/2)
                    ans = max (ans, dp[idx][count]);
                    
        return ans;
    }
};