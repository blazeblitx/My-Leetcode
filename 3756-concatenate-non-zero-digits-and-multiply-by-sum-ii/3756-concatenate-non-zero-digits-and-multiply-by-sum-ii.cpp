class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos, digit;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        vector<long long> prefSum(m);
        for (int i = 0; i < m; i++) {
            prefSum[i] = digit[i];
            if (i)
                prefSum[i] += prefSum[i - 1];
        }

        vector<long long> pow10(m + 1);
        pow10[0] = 1;
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> hash(m + 1);
        hash[0] = 0;
        for (int i = 1; i <= m; i++)
            hash[i] = (hash[i - 1] * 10 + digit[i - 1]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R - 1];
            if (L)
                sum -= prefSum[L - 1];

            long long number =
                (hash[R] - (hash[L] * pow10[R - L]) % MOD + MOD) % MOD;

            ans.push_back((number * sum) % MOD);
        }

        return ans;
    }
};