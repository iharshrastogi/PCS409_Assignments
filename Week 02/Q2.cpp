#include<iostream>
using namespace std;
void sumtok(int arr[],int n)
{
    for (int i=0;i<n-2;i++)
    {
        for (int j=i+1;j<n-1;j++)
        {
            for (int k=i+1;k<n;k++)
            {
                if (arr[i]+arr[j]==arr[k])
                  cout<<i+1<<","<<j+1<<","<<k+1<<endl;
            }
        }
    }
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
        sumtok(arr,n);
    }
}
