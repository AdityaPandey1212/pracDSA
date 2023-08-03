#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
	//make the stack of pair of charcater since we need to know what are the last two elements present in stack apart from the current element
        stack<pair<char,char>> st;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
			// for empty stack push current character and a '#'  in it
                st.push({s[i],'#'});
            }
            else
            {
			// main condition
                if(s[i]=='c')
                {
				// if we get previous char as b and previous to previous as a then we will pop twice
                    if(st.top().first=='b' && st.top().second=='a')
                    {
					//corner case
					// we atleast need two have stack of size two if we see this conditon else its not possible
                        if(st.empty())  return false;
                        st.pop();
                        if(st.empty())  return false;
                        st.pop();
                    }
                    else
                    {
					// push the current element with previous first elemnt in the stack if you dont get a 'c'
                        st.push({s[i],st.top().first});
                    }
                }
                else
                {
				// push the current element with previous first elemnt in the stack if you dont get a 'c'
                    st.push({s[i],st.top().first});
                }
            }
        }
        return st.empty();
    }
};