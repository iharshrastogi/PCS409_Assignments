#include<bits/stdc++.h>
using namespace std;

 static bool sortbyfirst(pair<int,int> &p1,pair<int,int> &p2)
 {
     return p1.first<p2.first;
 }
 int JobScheduling(int start[],int dead[], int n) 
    { 
        vector<pair<int, int> > vec(n);
        for(int i=0; i<n; i++) 
        {
            vec[i]=make_pair(start[i],dead[i]);
        }
        
        sort(vec.begin(), vec.end(), sortbyfirst);
        int maxi=vec[0].second;
        for (int i=0;i<n;i++)
            maxi=max(maxi,vec[i].second);
            
        int temp[maxi+1];
        for (int i=1;i<=maxi;i++)
           temp[i]=-1;
           
        int jobs=0;
        
        for (int i=0;i<n;i++)
        {
            for (int j=vec[i].second;j>0;j--)
            {
                if (temp[j]==-1)
                {
                    int x=j,count=0;
                    while (x>0 && temp[x]==-1)
                    {
                        x--;
                        count++;
                    }
                    if (count>=vec[i].first)
                    {
                        int count2=vec[i].first,x2=j;
                        while (count2--)
                        {
                            temp[j]=vec[i].first;
                            x2--;
                        }
                        jobs++;
                        break;
                    }
                }
            }
        }
     return jobs;
    } 

int main()
{
    int n;
    cout<<"Enter the n:";
    cin>>n;
    cout<<"Enter the n  time:"<<endl;
    int start[n];
    for (int i=0;i<n;i++)
        cin>>start[i];
    cout<<"Enter the n deadlines:"<<endl;
    int dead[n];
    for (int i=0;i<n;i++)
        cin>>dead[i];

    
    cout<<JobScheduling(start,dead,n);
    
}
