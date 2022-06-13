#include<bits/stdc++.h>
using namespace std;

static bool comp(pair<int,int> &i1,pair<int,int> &i2)
    {
        return (double)i1.first/i1.second>(double)i2.first/i2.second;
    }

    double fractionalKnapsack(int w, vector<pair<int,int>> item, int n,vector<pair<int,double>> &selected)
    {
        sort(item.begin(),item.end(),comp); 
        double ans=0;
        
        for (int i=0;i<n;i++)
        {
            if (item[i].second<=w)
            {
                ans+=item[i].first;
                w-=item[i].second;
                selected.push_back({item[i].first,1});
            }
            else
            {
                ans+=item[i].first*((double)w/item[i].second);
                selected.push_back({item[i].first,(double)w/item[i].second});
                break;
            }
        }
        return ans;
    }
int main()
{
    int n;
    cout<<"Enter the n:"<<endl;
    cin>>n;
    vector<int> value(n,0);
    vector<int> weight(n,0);
    cout<<"enter n values:"<<endl;
    for (int i=0;i<n;i++)
        cin>>value[i];
    cout<<"enter n weight:"<<endl;
    for (int i=0;i<n;i++)
        cin>>weight[i];
    cout<<"Enter Maximum weight of Knapsack"<<endl;
    int w;
    cin>>w;

    vector<pair<int,int>> item(n,{0,0});
    for (int i=0;i<n;i++)
        item[i]={value[i],weight[i]};
    
    vector<pair<int,double>> selected;
    cout<<"Maximum Value:"<<fractionalKnapsack(w,item,n,selected)<<endl;
    cout<<"Item Weight:"<<endl;
    for (int i=0;i<selected.size();i++)
       cout<<selected[i].first<<"-"<<selected[i].second<<endl;
}
