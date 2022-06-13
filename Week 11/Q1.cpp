#include<bits/stdc++.h>
using namespace std;

 bool majorityElement(vector<int>& nums)
   {
        if (nums.size()==1)
            return nums[0];
        sort(nums.begin(),nums.end());
        int count=1;
        for (int i=0;i<nums.size()-1;i++)
        {
            if (nums[i]==nums[i+1])
            {
                count++;
                if (count>nums.size()/2)
                    return true;
            }
            else
                count=1;
        }
     return false;   

    }
int main()
{
    int n;
    cout<<"Enter the n:";
    cin>>n;
    cout<<"Enter the n numbers:"<<endl;
    vector<int> nums(n,0);
    for (int i=0;i<n;i++)
        cin>>nums[i];
    if (majorityElement(nums))
       cout<<"Yes"<<endl;
    else
       cout<<"No"<<endl;

    if (n%2!=0)
        cout<<nums[n/2]<<endl;
    else{
        double x=(nums[n/2]+nums[n/2-1])/2.0;
        cout<<x<<endl;
    }
}
