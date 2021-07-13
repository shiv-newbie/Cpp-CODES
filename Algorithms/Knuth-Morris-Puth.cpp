// Knuth-Morris-Prat Algorithm
// Used to find substrings with O(n + m), n = length of text & m = length of substr

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <set>

using namespace std;

vector<int> LPS(string s, vector<int> f)                // Longest proper suffix
{
    int len = s.length(), j = 0;
    
    for(int i = 1; i < len; i++)
    {
        j = f[i-1];
        
        while(j > 0 && s[i] != s[j])
            j = f[j-1];
        
        if(s[i] == s[j])
        {
            f[i] = f[i-1] + 1;
            j++;
        }
    }
    return f;
}

vector<int> KMP(string par, string sub)                 // Knuth-Morris-Puth Algorithm
{
    vector<int> f(sub.length(), 0), big(par.length(), 0);
    f = LPS(sub, f);
    int p_len = par.length(), sub_len = sub.length();
    
    int i = 0;
    int j = 0;
    while(i < p_len)
    {
        if(i < p_len && par[i] != sub[j])
        {
            if(j != 0)
                j = f[j-1];
            else
                i++;
        }
        
        if(par[i] == sub[j])
            j++, i++;
        
        if(j == sub_len)
        {
            printf("Found pattern at index %d \n", i - j);
            big[i-j] = 1;
        }
    }
    
    
    return big;
}

int main()
{
    string s = "ABABDABACDABABCABAB";
    vector<int> f(s.length(), 0);
    
    f = KMP("ABABDABACDABABCABAB", "ABAB");

    return 0;
}

/*
ab
abcdc
 */
