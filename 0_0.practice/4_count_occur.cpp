//count number of occurences of a word
#include<bits/stdc++.h>
using namespace std;
void countWord(vector<string> list)
{
map<string,int> mpp;

for(auto i : list)
{
    if(mpp.find(i)==mpp.end())
    {
        mpp.insert({i,1}); 
        //or mpp[i]++;
    }
    else{
        auto it=mpp.find(i);
        (*it).second++;
    }
}
for(auto i =mpp.begin(); i!=mpp.end();i++)
{
    cout<< (*i).first <<" "<<(*i).second<<endl ;
}
}
int main() {
    vector<string> list = {"hello", "world", "hello"};
    countWord(list);
}