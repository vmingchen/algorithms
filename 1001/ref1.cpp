/*
 * =====================================================================================
 *
 *       Filename:  ref1.cpp
 *
 *    Description:  POJ 1001, from http://hi.baidu.com/stlnkm/blog/item/df5380fd3fce2640d7887d14.html
 *
 *        Version:  1.0
 *        Created:  04/19/2009 10:18:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  BUAA.edu
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>
using namespace std;
string Expon(string base,int t);
int main()
{
string base;
int exp;
while(cin>>base>>exp)
{
   cout<<Expon(base,exp)<<endl;
}
return 0;
}
#define maxbit 200
string Expon(string base,int t)    //求幂
{
int res[maxbit],bs[maxbit],tmp[maxbit];
memset(bs,0,sizeof(bs));
memset(tmp,0,sizeof(tmp));
int i,j=0;
int dpl=base.find_first_of('.'); //记录底数小数点位置
for(i=base.length()-1;i>=0;i--)
{
   if(base[i]!='.')
   {
    bs[j]=base[i]-'0';
    tmp[j]=base[i]-'0';
    j++;
   }
}
int k,p,h;
for(i=1;i<t;i++)     //t次幂
{
   memset(res,0,sizeof(res));
   for(k=0;k<j;k++)
   {
    for(p=0;p<j*i;p++)     //模拟乘法运算
     res[k+p]+=bs[k]*tmp[p];
    for(h=0;h<k+p;h++)     //处理进位
    {
     res[h+1]+=res[h]/10; //高位
     res[h]%=10;     //低位
    }
   }
   memcpy(tmp,res,sizeof(res));
}
i=maxbit-1;
while(tmp[i]==0)    //去除前导零
   i--;
j=0;
while(tmp[j]==0)    //去除后缀零
   j++;
int dot=(base.length()-dpl-1)*t-1;   //计算小数点位置
string rslt;
if(i<=dot)
{
   rslt+='.';
   for(h=0;h<dot-i;h++)
    rslt+='0';
}
for(h=i;h>=j;h--)
{
   if(h==dot)
    rslt+='.';
   rslt+=('0'+tmp[h]);
}
if(j>=dot)
{
   for(h=0;h<j-dot-1;h++)
    rslt+='0';
}
return rslt;
}
