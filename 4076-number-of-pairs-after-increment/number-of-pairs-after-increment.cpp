class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums2.size(), m = nums1.size();

        vector<long long> a(nums2.begin(), nums2.end());
        vector<long long> d(n + 1, 0);

        vector<int> f(100001, 0);

        for (auto v : a)
            f[v]++;

        bool dirty = false;
        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                d[q[1]] += q[3];
                d[q[2] + 1] -= q[3];
                dirty = true;
            } else {
                if (dirty) {
                    fill(f.begin(), f.end(), 0);

                    long long ps = 0;
                    for (int i = 0; i < n; i++) {
                        a[i] += (ps += d[i]);
                        if (a[i] <= 100000)
                            f[a[i]]++;
                    }

                    fill(d.begin(), d.end(), 0);
                    dirty = false;
                }

                // "Just for convenience..."
                unordered_map<int, int> cache;

                int c = 0;
                for (int x : nums1) {
                    int t = q[1] - x;
                    if (t >= 0) {
                        if (!cache.count(t))
                            cache[t] = f[t];
                        c += cache[t];
                    }
                }

                ans.push_back(c);
            }
        }

        return ans;
    }
};