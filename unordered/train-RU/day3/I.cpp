#include<bits/stdc++.h>
using namespace std;
char s2[1001];
int ans;
int len;
int slen;
char ss[101];
int ext[1001];

void getnext()
{
   ext[0]=0;
   int k=0;
   int j=1;
   while(j<=slen)
   {
      if(k==0||ss[k]==ss[j])
      {
         k++;
         j++;
         if (ss[j] != ss[k])
              ext[j] = k;
        else
             ext[j] = ext[k];
      }
      else
      {
         k=ext[k];
      }
   }
}

int main()
{
    scanf("%s%s",ss,s2);
    slen=strlen(ss);
    getnext();
    len=strlen(s2);
    int k=0;
    int pos=0,npos=0;
    int ii=0;
    for(int i=0;i<=slen;i++)
      cout<<ext[i]<<" ";
    //for(int i=0;i<len;i++)
    //{
        //if(s2[i]==ss[k]||k==-1)
        //{
        //    k++;
        //}
        //else
       // {
      //      k=next[k];
     //   }
    //}
    return 0;
}
