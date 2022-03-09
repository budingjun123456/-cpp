#include<queue>
#include<iostream>   
using namespace std;
#define _ ios_base::sync_with_stdio(0),cin.tie(0)
const int b[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};//八个方向 
char mp[105][105];//存输入的初始状态 
int n,m;
struct Node//记录坐标 
{
 int x;
 int y;
};   //bfs深度搜索 
void bfs(int e,int f)
{
     Node temp;   //临时结构体储存 
     temp.x=e;
     temp.y=f;
     queue<Node>q;   
     q.push(temp);
     while(q.size())
     {
          Node cur=q.front();
          q.pop();
          mp[cur.x][cur.y]='*';
          for(int i=0;i<8;i++)
          {
              Node next;
              next.x=cur.x+b[i][0];
              next.y=cur.y+b[i][1];
              if(next.x<0||next.y<0||next.y>m||next.x>n)
                      continue;       
              if(mp[next.x][next.y]!='@')
                      continue;
              q.push(next);     
          }
     }
}
int main( )
{
       while((scanf("%d%d",&n,&m))!=EOF)
       {
             if(m==0) break;
             for(int i=0;i<n;i++)
             {
                    scanf("%s",&mp[i]);
             }
             int ans=0;      
             for(int i=0;i<n;i++)
             {
                   for(int j=0;j<m;j++)
                   {
                         if(mp[i][j]=='@')
                         {
                               ans++;
                               bfs(i,j);
                         }
                    }
             }
             printf("%d\n",ans);     
      }
      return 0;
}
//1 1
//*
//3 5
//*@*@*
//**@**
//*@*@*
//1 8
//@@****@*
//5 5
//****@
//*@@*@
//*@**@
//@@@*@
//@@**@
//0 0
