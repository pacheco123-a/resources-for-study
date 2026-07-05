#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;
struct Point{
    double x,y;
};
bool cmpX(const Point& a,const Point&b){
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
bool cmpY(const Point& a,const Point&b){
    return a.y<b.y;
}
double dist(const Point &a,const Point &b){
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return dx*dx+dy*dy;
}
vector<Point> p;
double closestpair(int l,int r)
{
    if(r-l<=3)//如果小，直接算
    {
        double ans=1e100;
        for(int i=l;i<r;i++) 
        {
            for(int j=i+1;j<r;j++)
            {
                ans=min(ans, dist(p[i], p[j]));
            }
        }
    // 按 y 排序，方便后面合并
        sort(p.begin()+l,p.begin()+r,cmpY);
        return ans;
    }
    //如果多就拆成两部分
    int mid=(l+r)/2;
    double midx=p[mid].x;
    double minleft=closestpair(l,mid);
    double minright=closestpair(mid,r);
    double ans=min(minleft,minright);
    inplace_merge(p.begin() + l, p.begin() + mid, p.begin() + r, cmpY);

    vector<Point> strip;//靠近中线的所有点
    for(int i=l;i<r;i++)//遍历所有的p可能会费时
    {
        double dx=p[i].x-midx;
        if(dx*dx<ans)
        {
            strip.push_back(p[i]);
        }
    }
    int m=strip.size();
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m&&j<=i+7;j++)
        {
            double dy=strip[j].y-strip[i].y;
            if(dy*dy>=ans) break;
            ans=min(ans,dist(strip[i],strip[j]));
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin>>n&&n!=0)
    {
        p.resize(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i].x>>p[i].y;
        }
        sort(p.begin(),p.end(),cmpX);//根据横坐标排序
        double mindist=closestpair(0,n);
        double r=sqrt(mindist)/2.0;
        cout<<fixed<<setprecision(2)<<r<<endl;
    }
    return 0;
}