#include<iostream>
using namespace std;
int Binary_search_Firstoccurence(int arr[],int n,int key)
{
    int res=0;
    int low=0,high=n-1;
   
    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if (key==arr[mid])
        {
            res=mid;
            high=mid-1;
        }
        else if (key>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return res;
}
int Binary_search_Lastoccurence(int arr[],int n,int key)
{
    int flag=0;
    int low=0,high=n-1;
    int res=0;

    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if (key==arr[mid])
        {
            flag=1;
            res=mid;
            low=mid+1;
        }
        else if (key>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    if (flag==0)
        return -1;
    return res;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;i++)
           cin>>arr[i];
        int key;
        cin>>key;

        int first=Binary_search_Firstoccurence(arr,n,key);
        int last=Binary_search_Lastoccurence(arr,n,key);
        if (last!=-1)
          cout<<key<<"-"<<last-first+1<<endl;
        else
          cout<<"Key not present"<<endl;
    }
}
