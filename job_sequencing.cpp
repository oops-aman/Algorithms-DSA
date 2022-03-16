#include<bits/stdc++.h>
using namespace std;
int GetMinTimeMachine(vector<int> &machine )
{
    int j=0,t=INT_MAX;
    for(int i=0;i<machine.size();i++)
    {
        if(t>machine[i])
        {
            t= machine[i];
            j=i;
        }
    }
    return j;
}
int main()
{
    int n,m;
    cout<<"Enter total number of Jobs : ";
    cin>>n;
    cout<<"Enter total number of machines: ";
    cin>>m;
    vector<int> job(n),machine(m,0);
    cout<<"Enter job completion time of all jobs: ";
    for (int i = 0; i < n; i++)
    {
        cin>>job[i];
    }
    sort(job.begin(),job.end(),greater<int>());
    int maxTime=0,j=0;
    for (int i = 0; i < n; i++)
    {

        machine[j]+=job[i];
        maxTime= max(maxTime,machine[0]);
        j= GetMinTimeMachine(machine);
    }
    cout<<"Maximum time taken to complete all the jobs: "<<maxTime<<"\n";
}