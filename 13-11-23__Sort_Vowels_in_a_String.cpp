#pragma GCC optimize("O3")
class Solution {
public:
    string sortVowels(string s) {
        const string vowels="AEIOUaeiou";
        string v;
        vector<int> pos;
        int n=s.size();
        #pragma unroll
        for(int i=0; i<n; i++){
            if (vowels.find(s[i])!=-1){
                v.push_back(s[i]);
                pos.push_back(i);
            }        
        }
        sort(v.begin(), v.end());
        int count=0;
        #pragma unroll
        for(int i:pos){
            s[i]=v[count++];
        }
      
        return s;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();