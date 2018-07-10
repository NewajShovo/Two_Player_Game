#include<bits/stdc++.h>

#define Write freopen("out.txt","w",stdout)
#define Read freopen("in.txt","r",stdin)

#define si(a)           scanf("%d",&a)
#define sii(a,b)        scanf("%d %d",&a,&b)
#define siii(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sl(a)           scanf("%lld",&a)
#define sll(a,b)        scanf("%lld %lld",&a,&b)
#define slll(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)

#define lli long long
#define m_p make_pair
#define p_b push_back


#define lim 10000000000
#define mod 200
#define Max 10000010
#define PI acos(-1.0)

///*** set bit and check bit**
#define IsComp(n)  (arr[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) arr[n>>6]|=(1<<((n>>1)&31))
using namespace std;

/** Direction Array **/
//int dirx[]= {1,0,-1,0};
//int diry[]= {0,1,0,-1};

/*** Translator Functions***/
//int ToInt(string s){int r = 0;stringstream sin(s);sin >> r;return r;}
//double ToDouble(string s) { double r = 0; stringstream sin(s); sin >> r; return r; }
//string ToString(int n)  {  string s;    stringstream convert;convert << n;s = convert.str();return s;}
/****My code goes from here***/

int nd=1,mov;
int ami,computer,a,rem;
int dp[100][100];


int Mx_node=0;
void display()
{
    for(int i=0; i<a; i++)
    {
        cout<<"**";
    }
    cout<<"*";
    cout<<endl;
    cout<<"|";
    for(int i=0; i<a; i++)
    {
        if(i==ami-1||i==computer-1) cout<<"*|";
        else cout<<" |";
    }
    cout<<endl;
    for(int i=0; i<a; i++)
    {
        cout<<"**";
    }
    cout<<"*";
    cout<<endl;
}

int fnc(int a,int lvl,int k)
{
    if(k==1 && a<=0) return 1;
    else if (k==0 && a<=0) return -1;
    int p=0;
    for(int i=1; i<=mov; i++)
    {
        p=fnc(a-i,lvl+1,1^k);
        if(dp[a][lvl]==0) dp[a][lvl]=p;
        else
        {
            if(k==1) dp[a][lvl]=min(dp[a][lvl],p);
            else dp[a][lvl]=max(dp[a][lvl],p);
        }
    }



    return dp[a][lvl];

}
int pc(int a)
{
    int val;
    for(int i=1; i<=mov; i++)
    {
        val=fnc(a-i,2,0);
        memset(dp,0,sizeof(dp));
        if(val==-1) return i;
    }


    return (rand()%mov)+1;
}
void my_turn()
{
    cout<<"How many steps do you want to cross??"<<endl;
    int x;
    cin>>x;
    ami+=x;
    rem=rem-x;
    cout<<"MY MOVE:"<<endl;
    display();
}
int main()
{
    cout<<"Enter the length of the grid"<<endl;
    cin>>a;
    ami=1;
    computer=a;
    cout<<"Enter the maximum limit of one move"<<endl;
    cin>>mov;

    display();
    rem=a-2;
    while(rem)
    {
        int change=pc(rem);
        cout<<"PC MOVES"<<endl;

        computer=computer-change;
        rem=rem-change;
        display();
        if(rem==0)
        {
            cout<<"You Lost the Game!!!!!!!"<<endl;
            break;
        }
        my_turn();
        if(rem==0)
        {
            cout<<"You Won the Game!!!!!!!"<<endl;
            break;
        }


    }
}
