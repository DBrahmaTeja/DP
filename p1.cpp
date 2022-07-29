#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>a1,vector<int>a2)
{
    if(a1[1]<a2[1])
    return true;
    return false;
}
int main()
{
    int capacity=11;
    
    vector<vector<int>>arr;
    arr.push_back({3,2,7});
    arr.push_back({3,7,9});
    arr.push_back({8,3,9});

    int max_interval=0;
    for(int i=0;i<arr.size();i++)
    {
        max_interval=max(max_interval,arr[i][2]);
    }
    vector<int>prefix(max_interval+1);
    for(int i=0;i<arr.size();i++)
    {
        int temp_cap=arr[i][0];
        int st=arr[i][1];
        int end=arr[i][2];
        prefix[st]+=temp_cap;
        prefix[end]-=temp_cap;
    }
    
    for(int i=1;i<prefix.size();i++)
    {
        prefix[i]+=prefix[i-1];
    }
    for(int i=0;i<prefix.size();i++)
    {
        if(prefix[i]>capacity)
        {
           return false;
        }
    }
    return true;
}