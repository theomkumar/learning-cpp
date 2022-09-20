#include<iostream>
using namespace std;
//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
//we can also using stack storage but it's not needed!

int minAddToMakeValid(string s) {
    //using stack concept without using stack storage!
 
    int stack_size = 0, add_bracket = 0;      
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            stack_size++; //push('(')
        
        else if (stack_size) //for ')' -> '(' is present in stack so we'll pop it 
                stack_size--; //pop('(')
        
        else    //for ')' if we don't have '(' so we need to add a bracket to make it valid
            add_bracket++;
    }
    
    //eg. ((() -> there's only one closing bracket which will pop one opening -> (( but these are invalid parentheses to make it valid we need to add (stack_size )more parentheses.

    add_bracket += stack_size; 
    
    return add_bracket;
}

int main() 
{
    string s = "((((())";
    cout <<"we need: "<<minAddToMakeValid(s)<<" parentheses to make it valid!\n";
    return 0;
}