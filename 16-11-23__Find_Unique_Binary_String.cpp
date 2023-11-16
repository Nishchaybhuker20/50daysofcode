class Solution {
public:
    string binGenerate(string curr, int n, unordered_set<string> binSet) {
        if (curr.size() == n) {
            if (binSet.find(curr) == binSet.end()) return curr;
            return "";
        }
        
        string addZero = binGenerate(curr + "0", n, binSet);
        if (addZero.size() > 0) return addZero;

        return binGenerate(curr + "1", n, binSet);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> binSet;

        for(string s: nums){
            binSet.insert(s);
        }
        return binGenerate("", n, binSet);
    }
};