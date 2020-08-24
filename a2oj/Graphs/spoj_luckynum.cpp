/*
    Author : RAJON BARDHAN
    AUST CSE 27th Batch
    All my programming success are dedicated to my mom , dad , little sister madhobi , teachers , friends and love TANIA SULTANA RIMY

    Problem Name : LUCKYNUM - Lucky Numbers ( SPOJ )
    ALGORITHM : Graph Theory
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846

typedef long long ll ;
typedef unsigned long long ull ;

/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

struct Node
{
    int div , x , y ;
    string answer ;
};
int X ;

string bfs()
{

    queue < Node > Q ;
    Node obj ;
    obj.answer="6";obj.div=6%X;obj.x=0;obj.y=1;Q.push(obj);
    obj.answer="8";obj.div=8%X;obj.x=1;obj.y=0;Q.push(obj);

    while( !Q.empty() )
    {
        Node temp = Q.front() ; Q.pop() ;

        if(temp.div==0) return temp.answer ;
        if(temp.x+temp.y==200) continue ;

        if(temp.y)
        {
            obj.answer = temp.answer+"6" ;
            obj.div = (temp.div*10+6)%X ;
            obj.x = temp.x ;
            obj.y = temp.y+1 ;
            Q.push( obj ) ;
        }
        else
        {
            obj.answer = temp.answer+"6" ;
            obj.div = (temp.div*10+6)%X ;
            obj.x = temp.x ;
            obj.y = temp.y+1 ;
            Q.push( obj ) ;

            obj.answer = temp.answer+"8" ;
            obj.div = (temp.div*10+8)%X ;
            obj.x = temp.x+1 ;
            obj.y = temp.y ;
            Q.push( obj ) ;
        }
    }

    return "-1" ;
}

int main()
{
    freopen("inputf.in","r",stdin);
    freopen("outputf.in","w",stdout);
    int T;
    scanf("%d",&T);
    while( T-- )
    {
        scanf("%d",&X);
        cout << bfs() << endl ;
    }
    return 0;
}