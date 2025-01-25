/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
    
2. Open brackets must be closed in the correct order.

3. Every close bracket has a corresponding open bracket of the same type.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) { 
    int len = strlen(s);
    char stack[len];
    int top = -1;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            top++;
            stack[top] = s[i];
        } else {
            if (stack[top] == ' ')
            {
                return false;
            }
            if (s[i] == ')' && stack[top] != '(')
            {
                return false;
            }
            else if (s[i] == '}' && stack[top] != '{')
            {
                return false;
            }
            else if (s[i] == ']' && stack[top] != '[')
            {
                return false;
            }
            top--;
        }
    }
    return true;
}

int main() { 

    //char s[] = "{[]}";

    char s[] = "([)]";

    //char s[] = "()";

    if (isValid(s))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}
