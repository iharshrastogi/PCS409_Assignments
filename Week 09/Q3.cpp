#include<bits/stdc++.h>
using namespace std;

int minimum_comp(int arr[],int n)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i=0;i<n;i++)
      pq.push(arr[i]);
    
    int res=0;
    while (pq.size()>=2)
    {
        int temp=pq.top();
        pq.pop();
        temp+=pq.top();
        pq.pop();

        res+=temp;
        pq.push(temp);
    }

    return res;

    
}
int main()
{
    int n;
    cout<<"Enter the n:"<<endl;
    cin>>n;
    cout<<"Enter the n number in array:"<<endl;
    int arr[n];
    for (int i=0;i<n;i++)
       cin>>arr[i];

    cout<<"Minimum Computation:"<<minimum_comp(arr,n);
}
