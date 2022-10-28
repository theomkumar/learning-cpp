#include<iostream>
#include<string>
#include<vector>

void permutation(std::string &s, std::vector<std::string> &v, int idx)
{
    if (idx == size(s))
    {
        v.push_back(s);
        return;
    }

    for (int i = idx; i < size(s); i++)
    {
        std::swap(s[i],s[idx]);
        //recursive call
        permutation(s,v,idx+1);
        //backtracking
        std::swap(s[i],s[idx]);
    }
}

int main()
{
    std::string s = "abc";
    std::vector<std::string> v;

    permutation(s,v,0);

    //print
    for (auto i : v)
    {
        std::cout << i <<" ";
    }
    std::cout<<std::endl;
}