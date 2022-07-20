/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'. */

class solution
{
    vector<int> isValid(string s)
    {
        map<char, char> parens = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> open;
        for (char c : s)
        {
            if (parens.count(c))
            {
                open.push(c);
            }
            else if (!open.empty() && parens[open.top()] == c)
            {
                open.pop();
            }
            else
                return false;
        }
        return open.empty();
    }
}