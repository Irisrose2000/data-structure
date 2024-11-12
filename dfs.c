#include<stdio.h>
int stack[20],top=-1,a[20][20],vis[20];
int pop();
void push(int item);
void dfs(int s,int n);
void main()
{
int n,i,s,ch,j;
printf("ENTER THE NUMBER VERTICES ");
scanf("%d",&n);
printf("enter the adjacency matrix");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("THE ADJACENCY MATRIX IS\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d",a[i][j]);
}
printf("\n");
}

for(i=1;i<=n;i++)
vis[i]=0;
printf("ENTER THE SOURCE VERTEX ");
scanf("%d",&s);
dfs(s,n);
}

void dfs(int s,int n)
{
int p,i;
push(s);
vis[s]=1;
p=pop();
if(p!=0)
printf("%d",p);
while(p!=0)
{
for(i=1;i<=n;i++)
if((a[p][i]!=0)&&(vis[i]==0))
{
push(i);
vis[i]=1;
}
p=pop();
if(p!=0)
printf(" %d",p);
}
for(i=1;i<=n;i++)
if(vis[i]==0)
dfs(i,n);
}
void push(int item)
{
if(top==19)
printf("stack FULL");
else
{
    stack[++top]=item;
}

}

int pop()
{
int k;
if(top==-1)
return(0);
else
{
k=stack[top--];
return(k);
}
}


