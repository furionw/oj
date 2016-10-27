/* ***********************************************
Author        :axp
Created Time  :2016/10/16 13:07:56
TASK		  :A.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll;
const int inf = 1<<30;
const int md = 1e9+7;
const int N = 2000+10;
int n,m;
int T;
double dp[N][N];
bool vis[N][N];

double f(int x,int y)
{
	double &re=dp[x][y];
	if(vis[x][y])return re;
	vis[x][y]=1;
	re=0;
	if(x==n || y==m)return re=1;
	re+=1.0*(n-x)/(n+m-x-y)*f(x+1,y);
	if(x>y+1)re+=1.0*(m-y)/(n+m-x-y)*f(x,y+1);
	return re;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("large-out.txt","w",stdout);
    scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof vis);
		double ans=f(0,0);
		printf("Case #%d: %.8lf\n",kase,ans);
	}
    return 0;
}
