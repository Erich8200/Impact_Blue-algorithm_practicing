#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define N 3

using namespace std;

class Job
{
private:
    int request;
    int allocated;
    int need;
public:
    Job(int r,int a):request(r),allocated(a){ need = request > allocated ? request - allocated : 0; }
    Job() { }
    int finish();
    int getNeed() { return need; }
    friend bool cmp(Job a,Job b);
};

int  Job::finish()
{
    int ret = allocated;
    request = need = allocated = 0;
    return ret;
}

bool cmp(Job a,Job b)
{
    return a.need < b.need;
}

vector<Job> jobArr;

int main()
{
    freopen("input10.txt","r",stdin);
    int m = 0;
    cin >> m;
    while(m--)
    {
        int n = 0;
        bool ans = true;
        cin >> n;
        jobArr.clear();
        for(int i = 0;i < n;i++)
        {
            int a = 0,r = 0;
            cin >> a >> r;
            jobArr.push_back(Job(r,a));
        }
        sort(jobArr.begin(),jobArr.end(),cmp);

        int srcSum = 0;
        for(vector<Job>::iterator it = jobArr.begin();it < jobArr.end();it++)
        {
            if(srcSum < it->getNeed())
            {
                ans = false;
                break;
            }
            else
                srcSum += it->finish();
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    fclose(stdin);
    return 0;
}
