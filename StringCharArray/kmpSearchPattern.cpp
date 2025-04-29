#include<bits/stdc++.h>
using namespace std;

#define ll long long

void print(vector<int> &v)
{
    for (auto i : v)
        cout << i <<" ";
}

void generateLPS(vector<int> &lps, string &pat, int &n){
    lps[0] = 0;

    int len = 0;
    int i = 1;
    while (i < n){
        if (pat[i] == pat[len]){
            lps[i++] = ++len;
        }
        else {
            if (len > 0){
                len--;
            }
            else {
                lps[i++] = 0;
            }
        }
    }
}

vector<int> search(string& pat, string& txt) {
    int patLen = pat.size(), n = txt.size();

    vector<int> lps(patLen);

    generateLPS(lps, pat, patLen);

//    print(lps);

    vector<int> res;

    int i = 0, j = 0;
    while (i < n){
        if (txt[i] == pat[j]){
            i++;
            j++;
        }
        else {
            if (j > 0){
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
        if (j == patLen){
            res.push_back(i-j);
            j = lps[j-1];
        }
    }

    return res;
}

int main() {
    string pat = "aba";
    string txt = "aabcde";
    search(pat, txt);
    return 0;
}
