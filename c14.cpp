#include <iostream>
using namespace std;
#include <stack>

// Function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    if (expr.length() == 0)
        return true;
    // Declare a stack to hold the previous brackets.
    stack<char> temp;
    for (int i = 0; i < expr.length(); i++)
    {
        if (temp.empty())
        {
            temp.push(expr[i]);
        }
        else if ((temp.top() == '(' && expr[i] == ')') )
        {
            temp.pop();
        }
        else
        {
            temp.push(expr[i]);
        }
    }
    if (temp.empty())
    {
        return true;
    }
    return false;
}

// Driver code
int main()
{
    string a;
    getline(cin,a);
    string expr = "";
    for (int i=0;i<a.length();i++)
    {
        if (a[i] == '(' || a[i] == ')')
            expr+=a[i];
    }
    // Function call
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}


