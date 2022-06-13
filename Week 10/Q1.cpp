#include<bits/stdc++.h>
using namespace std;

static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
   {
    return (a.second < b.second);
   }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int> > vec(n);
        for(int i=0; i<n; i++) 
        {
            vec[i]=make_pair(start[i],end[i]);
        }
        
        sort(vec.begin(), vec.end(), sortbysec);
        
        int ans=1;
        int last_end=vec[0].second;
        cout<<"("<<vec[0].first<<","<<vec[0].second<<")"<<endl;
        for (int i=1;i<n;i++)
        {
            if (vec[i].first>=last_end)
            {
                ans++;
                last_end=vec[i].second;
                cout<<"("<<vec[i].first<<","<<vec[i].second<<")"<<endl;
            }
        }
        return ans;
    }

int main()
{
    int n;
    cout<<"Enter the n:";
    cin>>n;
    cout<<"Enter the n start time:"<<endl;
    int start[n];
    for (int i=0;i<n;i++)
        cin>>start[i];
    cout<<"Enter the n end time:"<<endl;
    int end[n];
    for (int i=0;i<n;i++)
        cin>>end[i];

    cout<<maxMeetings(start,end,n)<<endl;    
}
