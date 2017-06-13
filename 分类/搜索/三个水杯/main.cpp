//#include <iostream>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//struct Statue
//{
//    int St_v1,St_v2,St_v3,Count;
//};
//struct Ma
//{
//    int Ma_v1,Ma_v2,Ma_v3;
//    bool operator < (const Ma &m1)const
//    {
//        if(Ma_v1!=m1.Ma_v1)
//            return m1.Ma_v1<Ma_v1;
//        else if(Ma_v2!=m1.Ma_v2)
//            return m1.Ma_v2<Ma_v2;
//        else
//            return m1.Ma_v3<Ma_v3;
//    }
//};
//int n,v1,v2,v3,e1,e2,e3;
//void bfs()
//{
//    queue<Statue> Q;
//    map<Ma,int> m;
//    Ma ma;
//    Statue cur,next;
//    cur.St_v1=v1,cur.St_v2=0,cur.St_v3=0,cur.Count=0;
//    Q.push(cur);
//    while(!Q.empty())
//    {
//        cur=Q.front();
//        Q.pop();
//        ma.Ma_v1=cur.St_v1;ma.Ma_v2=cur.St_v2;ma.Ma_v3=cur.St_v3;
//        m[ma]++;
//        if(cur.St_v1==e1&&cur.St_v2==e2&&cur.St_v3==e3)
//        {
//            cout<<cur.Count<<endl;
//            return;
//        }
//        if(cur.St_v1>(v2-cur.St_v2))///1->2
//        {
//            next.St_v1=cur.St_v1-(v2-cur.St_v2);
//            next.St_v2=v2;
//        }
//        else
//        {
//            next.St_v2=cur.St_v1+cur.St_v2;
//            next.St_v1=0;
//        }
//        next.St_v3=cur.St_v3;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        m[ma]++;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v1>(v3-cur.St_v3))
//        {
//            next.St_v1=cur.St_v1-(v3-cur.St_v3);
//            next.St_v3=v3;
//        }
//        else
//        {
//            next.St_v3=cur.St_v1+cur.St_v3;
//            next.St_v1=0;
//        }
//        next.St_v2=cur.St_v2;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        m[ma]++;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v2>(v1-cur.St_v1))
//        {
//            next.St_v2=cur.St_v2-(v1-cur.St_v1);
//            next.St_v1=v1;
//        }
//        else
//        {
//            next.St_v1=cur.St_v2+cur.St_v1;
//            next.St_v2=0;
//        }
//        next.St_v3=cur.St_v3;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        m[ma]++;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v2>(v3-cur.St_v3))
//        {
//            next.St_v2=cur.St_v2-(v3-cur.St_v3);
//            next.St_v3=v3;
//        }
//        else
//        {
//            next.St_v3=cur.St_v2+cur.St_v3;
//            next.St_v2=0;
//        }
//        next.St_v1=cur.St_v1;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        m[ma]++;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v3>(v1-cur.St_v1))
//        {
//            next.St_v3=cur.St_v3-(v1-cur.St_v1);
//            next.St_v1=v1;
//        }
//        else
//        {
//            next.St_v1=cur.St_v3+cur.St_v1;
//            next.St_v3=0;
//        }
//        next.St_v2=cur.St_v2;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        m[ma]++;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v3>(v2-cur.St_v2))
//        {
//            next.St_v3=cur.St_v3-(v2-cur.St_v2);
//            next.St_v2=v2;
//        }
//        else
//        {
//            next.St_v2=cur.St_v2+cur.St_v3;
//            next.St_v3=0;
//        }
//        next.St_v1=cur.St_v1;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        m[ma]++;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//    }
//    cout<<"-1"<<endl;
//
//}
//int main()
//{
//    cin>>n;
//    while(n--)
//    {
//        cin>>v1>>v2>>v3>>e1>>e2>>e3;
//        bfs();
//    }
//    return 0;
//}

//#include <iostream>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//struct Statue
//{
//    int St_v1,St_v2,St_v3,Count;
//};
//struct Ma
//{
//    int Ma_v1,Ma_v2,Ma_v3;
//    bool operator < (const Ma &m1)const
//    {
//        if(Ma_v1!=m1.Ma_v1)
//            return m1.Ma_v1<Ma_v1;
//        else if(Ma_v2!=m1.Ma_v2)
//            return m1.Ma_v2<Ma_v2;
//        else
//            return m1.Ma_v3<Ma_v3;
//    }
//};
//int n,v1,v2,v3,e1,e2,e3;
//void bfs()
//{
//    queue<Statue> Q;
//    map<Ma,int> m;
//    Ma ma;
//    Statue cur,next;
//    cur.St_v1=v1,cur.St_v2=0,cur.St_v3=0,cur.Count=0;
//    Q.push(cur);
//    while(!Q.empty())
//    {
//        cur=Q.front();
//        Q.pop();
//        ma.Ma_v1=cur.St_v1;ma.Ma_v2=cur.St_v2;ma.Ma_v3=cur.St_v3;
//        cout<<ma.Ma_v1<<' '<<ma.Ma_v2<<' '<<ma.Ma_v3<<endl;
//        m[ma]++;
//        cout<<m[ma]<<endl;
//        if(cur.St_v1==e1&&cur.St_v2==e2&&cur.St_v3==e3)
//        {
//            cout<<cur.Count<<endl;
//            return;
//        }
//        if(cur.St_v1>(v2-cur.St_v2))///1->2
//        {
//            next.St_v1=cur.St_v1-(v2-cur.St_v2);
//            next.St_v2=v2;
//        }
//        else
//        {
//            next.St_v2=cur.St_v1+cur.St_v2;
//            next.St_v1=0;
//        }
//        next.St_v3=cur.St_v3;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        cout<<ma.Ma_v1<<' '<<ma.Ma_v2<<' '<<ma.Ma_v3<<endl;
//        m[ma]++;
//        cout<<"1->2"<<endl;
//        cout<<m[ma]<<endl;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v1>(v3-cur.St_v3))
//        {
//            next.St_v1=cur.St_v1-(v3-cur.St_v3);
//            next.St_v3=v3;
//        }
//        else
//        {
//            next.St_v3=cur.St_v1+cur.St_v3;
//            next.St_v1=0;
//        }
//        next.St_v2=cur.St_v2;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        cout<<ma.Ma_v1<<' '<<ma.Ma_v2<<' '<<ma.Ma_v3<<endl;
//        m[ma]++;
//        cout<<"1->3"<<endl;
//        cout<<m[ma]<<endl;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v2>(v1-cur.St_v1))
//        {
//            next.St_v2=cur.St_v2-(v1-cur.St_v1);
//            next.St_v1=v1;
//        }
//        else
//        {
//            next.St_v1=cur.St_v2+cur.St_v1;
//            next.St_v2=0;
//        }
//        next.St_v3=cur.St_v3;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        cout<<ma.Ma_v1<<' '<<ma.Ma_v2<<' '<<ma.Ma_v3<<endl;
//        m[ma]++;
//        cout<<"2->1"<<endl;
//        cout<<m[ma]<<endl;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v2>(v3-cur.St_v3))
//        {
//            next.St_v2=cur.St_v2-(v3-cur.St_v3);
//            next.St_v3=v3;
//        }
//        else
//        {
//            next.St_v3=cur.St_v2+cur.St_v3;
//            next.St_v2=0;
//        }
//        next.St_v1=cur.St_v1;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        cout<<ma.Ma_v1<<' '<<ma.Ma_v2<<' '<<ma.Ma_v3<<endl;
//        m[ma]++;
//        cout<<"2->1"<<endl;
//        cout<<m[ma]<<endl;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v3>(v1-cur.St_v1))
//        {
//            next.St_v3=cur.St_v3-(v1-cur.St_v1);
//            next.St_v1=v1;
//        }
//        else
//        {
//            next.St_v1=cur.St_v3+cur.St_v1;
//            next.St_v3=0;
//        }
//        next.St_v2=cur.St_v2;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        cout<<ma.Ma_v1<<' '<<ma.Ma_v2<<' '<<ma.Ma_v3<<endl;
//        m[ma]++;
//        cout<<"3->1"<<endl;
//        cout<<m[ma]<<endl;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//        if(cur.St_v3>(v2-cur.St_v2))
//        {
//            next.St_v3=cur.St_v3-(v2-cur.St_v2);
//            next.St_v2=v2;
//        }
//        else
//        {
//            next.St_v2=cur.St_v2+cur.St_v3;
//            next.St_v3=0;
//        }
//        next.St_v1=cur.St_v1;
//        ma.Ma_v1=next.St_v1;ma.Ma_v2=next.St_v2;ma.Ma_v3=next.St_v3;
//        cout<<ma.Ma_v1<<' '<<ma.Ma_v2<<' '<<ma.Ma_v3<<endl;
//        m[ma]++;
//        cout<<"3->2"<<endl;
//        cout<<m[ma]<<endl;
//        cout<<m.count(ma)<<(bool)(m.count(ma)==1)<<endl;
//        if(m[ma]==1)
//        {
//            next.Count=cur.Count+1;
//            Q.push(next);
//        }
//    }
//    cout<<"-1"<<endl;
//
//}
//int main()
//{
//    cin>>n;
//    while(n--)
//    {
//        cin>>v1>>v2>>v3>>e1>>e2>>e3;
//        bfs();
//    }
//    return 0;
//}

















//#include <iostream>
//#include <stdio.h>
//#include <map>
//#include <queue>
//using namespace std;
//int m[3];
//int z_m[3];
//struct zhuang_tai{
//    int L[3];
//    int sum;
//    bool operator < (const zhuang_tai &a)const      ///重载<运算符用于结构体排序
//    {
//            if(a.L[0]==L[0])
//                if(a.L[1]==L[1])
//                    if(a.L[2]==L[2]);
//                    else
//                        return a.L[2]<L[2];
//                else
//                    return a.L[1]<L[1];
//            return a.L[0]<L[0];
//    }
//}ans;
//queue<zhuang_tai>q;
//map<zhuang_tai,int>mp;
//
//int pan(zhuang_tai a)        ///判断是否与目标状态相同
//{
//    if(a.L[0]==z_m[0]&&a.L[2]==z_m[2]&&a.L[1]==z_m[1])
//        return 1;
//    return 0;
//}
//void swp(int a ,int b,int c)
//{
//    zhuang_tai ans1;
//    if(ans.L[a]<(m[b]-ans.L[b]))///如果第一个杯子水小于要倒的杯子剩余容量就全部倒到第二个杯子
//    {
//        ans1.L[a]=0;
//        ans1.L[b]=ans.L[b]+ans.L[a];
//    }
//    else                        ///否则把第二个杯子倒满
//    {
//        ans1.L[a]=ans.L[a]-(m[b]-ans.L[b]);
//        ans1.L[b]=m[b];
//    }
//    ans1.L[c]=ans.L[c];
//    ans1.sum=0;
//    if(!mp.count(ans1))         ///判断三种杯子状态是否出现过，如果没有出现过就入队
//    {
//        mp[ans1]++;
//        ans1.sum=ans.sum+1;
//        q.push(ans1);
//    }
//}
//int main()
//{
//
//    int w;cin>>w;
//    while(w--)
//    {
//        while(!q.empty())
//            q.pop();
//        mp.clear();
//        cin>>m[0]>>m[1]>>m[2];
//        cin>>z_m[0]>>z_m[1]>>z_m[2];
//        ans.L[0]=m[0];
//        ans.L[1]=0;
//        ans.L[2]=0;
//        ans.sum=0;
//        q.push(ans);
//        int summ=0;
//        while(!q.empty())
//        {
//            ans=q.front();
//            summ++;
//            q.pop();
//            if(pan(ans))  ///判断是否与目标状态相同
//            {
//                cout<<ans.sum<<endl;
//                 goto go;      ///跳过输出-1的情况
//            }
//            swp(0,1,2);    ///六种相互倒的状态
//            swp(0,2,1);
//            swp(1,0,2);
//            swp(1,2,0);
//            swp(2,1,0);
//            swp(2,0,1);
//        }
//        cout<<-1<<endl;
//        go:;
//    }
//    return 0;
//}
