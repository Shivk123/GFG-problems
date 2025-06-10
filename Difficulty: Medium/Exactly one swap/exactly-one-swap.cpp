class Solution {
  public:
    int countStrings(string &s) {
        int sum=0;
        bool flag=false;
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            sum+=i-freq[s[i]-'a'];
            if(freq[s[i]-'a'])flag=true;
            freq[s[i]-'a']++;
        }
        
        return sum+flag;
    }
};
