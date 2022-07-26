/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string s = "";
        if (strs.size() == 1 || strs[0].empty())
        {
            return strs[0];
        }
        for (int i = 0; i < strs[0].length(); i++)
        {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
            {
                if (i > strs[j].length())
                {
                    return s;
                }
                if (strs[j][i] != ch)
                {
                    return s;
                }
            }
            s.push_back(ch);
        }
        return s;
    }
};