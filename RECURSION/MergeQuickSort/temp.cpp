#include<iostream>
#include<string>

using namespace std;

bool (string a, string b) {
        sort ( a.begin(),a.end() );
        sort ( b.begin(),b.end() ); 
        if (a==b)
            return 1;
        return 0;   
    }

vector<string> removeAnagrams(vector<string>& words) {
        for (int i = 1; i<words.size(); i++)   
        {
             if (isAnagram(words[i],words[i-1])
                 words.erase(words.begin+i-1);
        }
        return words;
    }

int main() 
{
    vector<string> str{"hello", "world"}
    removeAnagrams("hello","world");
    cout<<str;
    return 0;
}