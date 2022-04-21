#include<iostream>
using namespace std;
void insertion_sort(int A[],int n)
{
    int comparisions=0,shift=0;
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            comparisions++;
            A[j + 1] = A[j];
            j--;
        }
        shift++;
        A[j + 1] = x;
    }
    cout<<"Comparisions:"<<comparisions<<endl;
    cout<<"Shift:"<<shift<<endl;

    for (int i=0;i<n;i++)
           cout<<A[i]<<" ";
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

        insertion_sort(arr,n);
    }
}
