#include <iostream>
using namespace std;

void merge(int arr[],int l,int mid,int h)
{
    int count=0;
    int i=l,j=mid+1;
    int temp[h-l+1];
    int k=0;
    
    while (i<=mid && j<=h)
    {
        if (arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            count+=mid-i+1;
        }
    }
    for (;i<=mid;)
         temp[k++]=arr[i++];
         
    for (;j<=h;)
         temp[k++]=arr[j++];
         
    for (int f=0;f<k;f++)
        arr[f+l]=temp[f];
}
void merge_sort(int arr[],int l,int h)
{
    if (l<h)
    {
        int mid=l+(h-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

void find_duplicates(int arr[],int n,int k)
{
    int flag=0;
    int i=0,j=n-1;
    while (i<j)
    {
        if (arr[i]+arr[j]==k)
        {
            flag=1;
            cout<<arr[i]<<"+"<<arr[j]<<"="<<k<<endl;;
            i++;j--;
        }
        else if (arr[i]+arr[j]<k)
           i++;
        else 
           j--;
    }
    if (flag==0)
       cout<<"No such pair exist"<<endl;
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
        merge_sort(arr,0,n-1);
        find_duplicates(arr,n,key);
    }
    return 0;
}
