class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = countBit(arr[i]) * 10001 + arr[i];
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < n; i++) {
            res[i] %= 10001;
        }
        return res;
    }

private:
    int countBit(int n) {
        int res = 0;
        while (n != 0) {
            res += (n & 1);
            n >>= 1;
        }
        return res;
    }
};