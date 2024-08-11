//Check if a substring is present in a given string.
#include<bits/stdc++.h>
using namespace std;
bool check(string s,string word)
{  int i=0;
        for(int j=0;j<s.size();j++)
        {   if(i!=word.size())
            {
                if(word[i]==s[j])
                {
                 i++;
                }
                else{
                    i=0;
                }
            }
            else{
                return true;
            }
        }
    return false;
}
int main()
{
    string s= "hello world";
    string word ="worr";
    if(check(s,word))
    cout<<"true";
    else
    cout<<"false";
}
// space o(1)
//time( o(N))