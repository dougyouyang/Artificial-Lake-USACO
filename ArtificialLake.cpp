//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
pair<int, int> graph[100002];
long long n, w[100001], h[100001];
long long ans[100001];

int main()
{
    int low=1000001, p;
    long long amount=0;
    int i;
    
    cin >> n;
    h[0]=1000001, h[n+1]=1000001;
    for(i=1;i<=n;i++)
        cin >> w[i] >> h[i], graph[i].first=i-1, graph[i].second=i+1;
    for(i=1;i<=n;i++)
        if(h[i]<low)
            low=h[i], p=i;
    
    while(h[graph[p].first]<=1000000 || h[graph[p].second]<=1000000){
        int po;
        if(h[graph[p].first]>=h[graph[p].second])
            po=graph[p].second;
        else
            po=graph[p].first;
        if(h[po]>h[p]){
            ans[p]=amount+w[p], amount+=(h[po]-h[p])*w[p], w[po]+=w[p];
            graph[graph[p].first].second=graph[p].second, graph[graph[p].second].first=graph[p].first;
        }
        p=po;
    }
    ans[p]=amount+w[p];
    
    for(i=1;i<=n;i++)
        cout << ans[i] << endl;
    
    return 0;
}
