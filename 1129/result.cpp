/*
 * =====================================================================================
 *
 *       Filename:  result.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/07/2010 11:08:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ming Chen (chm), mingchen@cse.buaa.edu.cn
 *        Company:  Beihang University
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

using namespace std;
bool map[26][26];
int n,ans;
int color[26];
bool check(int position,int color_index)
{
    for(int i=0;i<n;i++)
    {
        if(map[position][i]&&color[i]==color_index) return false; 
        /* postion 和 i 相邻，而 i 已经染成了 color_index */
    }
    return true;
}
 
void DFS(int index,int used_color_num)
{
    if(used_color_num>=ans) return;
    if(index==n) 
    {
        ans=used_color_num;
        return;
    }
    for(int i=1;i<=used_color_num;i++)
    {
        if(check(index,i)) /* 可以染成第 i 个颜色*/
        {
            color[index]=i;
            DFS(index+1,used_color_num);
            color[index]=0;
        }
    }
    used_color_num++; /* 不得不染成新的颜色 */
    color[index]=used_color_num;
    DFS(index+1,used_color_num);
    color[index]=0;
}
 
int main()
{
    char temp_str[30];
    while(scanf("%d",&n)&&n)
    {
        memset(map,0,sizeof(map));
        memset(color,0,sizeof(color));
        ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            scanf("%s",temp_str);
            for(int j=2;temp_str[j]!='\0';j++)
            {
                map[i][temp_str[j]-'A']=true;
            }
        }
        DFS(0,0);
        if(ans==1) printf("%d channel needed.\n",ans);
        else printf("%d channels needed.\n",ans);
    }
    return 0;
}
