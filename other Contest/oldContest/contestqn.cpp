#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isAnagram(string a, string b) {
    sort ( a.begin(),a.end() );
    sort ( b.begin(),b.end() ); 
    if (a==b)
        return 1;
    return 0;   
}

vector<string> removeAnagrams(vector<string>& words) {
    for (int i = 1; i<words.size(); i++)   
    {
            if (isAnagram(words[i],words[i-1]) ) 
            {
                words.erase(words.begin()+(i));
                i=0;
            }
                
        
    }
    return words;
}
int main() 
{
    vector<string> words{"a","b","c","d","e"};
    removeAnagrams(words);
    
    for (auto i:words)
        cout<<i<<" ";
    return 0;
}