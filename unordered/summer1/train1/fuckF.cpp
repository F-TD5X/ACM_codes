  
using namespace std;  
typedef long long LL;  
  
int a[110];  
int main()  
{  
    int n,cnt,i;  
    while(~scanf("%d",&n)){  
        cnt = 0;  
        for(i = 0;i < n;i++){  
            scanf("%d",&a[i]);  
            if(a[i] == 0) cnt ++;  //只能休息  
            else if(i && a[i] == 3) {    
                if(a[i - 1] == 1) a[i] = 2;  //前一天是1，那么今天只能是2  
                else if(a[i - 1] == 2) a[i] = 1; //前一天是2.那么今天只能是1  
            }  
            else if(a[i] == a[i - 1] && a[i - 1] != 3) { //前一天的活动和今天的相同，只能休息  
                a[i] = 0;  
                cnt ++;  
            }  
        }  
        printf("%d\n",cnt);  
    }  
    return 0;  
}  