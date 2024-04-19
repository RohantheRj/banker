#include<string.h>
#include<stdio.h>
int n,m,i,j,k,flag,safe;
int a[50][50],av[15],max[50][50],finish[10],need[50][50],req[10];
char s[50],str[5];
void get_data()
{
printf("\nEnter number of processes : ");
scanf("%d",&n);
printf("\nEnter number of resources : ");
scanf("%d",&m);
printf("\n Enter allocation matrix : ");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("\n Enter MAX matrix");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("\nEnter Available Array : ");
for(i=0;i<m;i++)
scanf("%d",&av[i]);
for(i=0;i<n;i++)
finish[i]=0;
}
void put_data()
{
printf("\nAllocation matrix is.......\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("\nMax matrix is.......\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d\t",max[i][j]);
}
printf("\n");
}
printf("\nAvailable Array is.....\n");
for(i=0;i<m;i++)
printf("%d\t",av[i]);
printf("\nFinish Array\n");
for(i=0;i<n;i++)
printf("%d\t",finish[i]);
}

void calc_need()
{
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
need[i][j]=max[i][j]-a[i][j];
}
}
printf("\nNeed array is.....\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d\t",need[i][j]);
}
printf("\n");
}
}
int check_need(int i)
{
flag=0;
for(j=0;j<m;j++)
{
if(need[i][j] > av[j])
{
flag=1;
break;
}
}
return flag;
}
void safe_state()
{
for(i=0;i<n;i++)
finish[i]=0;
strcpy(s,"\0");
for(i=0;i<n;i++)
{
if(check_need(i)==0)
{
for(k=0;k<m;k++)
av[k]=av[k]+a[i][k];
sprintf(str,"%d",i);
strcat(s,"P");
strcat(s,str);
strcat(s," ");
puts(s);
}
else
finish[i]=1;
}//for
}
void res_req()
{
safe=0;
printf("Enter the process number\n");
scanf("%d",&i);
printf("Enter the request\n");
for(k=0;k<m;k++)
scanf("%d",&req[k]);
for(k=0;k<m;k++)
{
if(req[k] > need[i][k] || req[k] > av[k])
{
safe=1;
break;
}
}
printf("\nEnter available array");
for(j=0;j<m;j++)
scanf("%d",&av[j]);
if(safe==0)
{
printf("The request can be granted \n");
for(k=0;k<m;k++)
{
av[k]=av[k]-req[k];
a[i][k]=a[i][k]+req[k];
need[i][k]=need[i][k]-req[k];
}
printf("\nNeed array is.....\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d\t",need[i][j]);
}
printf("\n");
}
}
else
printf("\nThe request can not be granted");
}
void main()
{
int p,f;
f=0;
get_data();
put_data();
calc_need();
aaa: safe_state();
for(k=0;k<n;k++)
{
if(finish[k]==1)
{
if(check_need(k)==0)
{
for(p=0;p<m;p++)
av[p]=av[p]+a[k][p];
sprintf(str,"%d",k);
strcat(s,"P");
strcat(s,str);
strcat(s," ");
finish[k]=0;
}
else
f=1;
}
}
if(f==0)
{
printf("System is in safe state");
printf("\nSafe sequence\n");
puts(s);
}
else
printf("System is not in safe state");
res_req();
put_data();
if (safe==0)
goto aaa;
}
