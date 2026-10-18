class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector <int> check(260, 0);
        int length= 0, res= 0;
        int l= 0, r= 0;
        while(r < s.size())
        {
            if(!check[(unsigned char)s[r]]) 
            {
                length++;
                check[(unsigned char)s[r]]= true;
            }
            else
            {
                res= max(res, length);
                while(s[l] != s[r])
                {
                    check[(unsigned char)s[l]]= false;
                    l++;
                    length--;
                }
                l++;
            }
            r++;
        }
        res= max(res, length);
        return res;
    }
};
