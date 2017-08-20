#include <iostream>  
#include <cstring>  
  
const int MAX = 1e3 + 5;  
char arr[MAX];  
  
int main()  
{  
    scanf("%s", arr);  
    int lenth = strlen(arr);  
    int res = 0;  
    for (int i = 0; i < lenth; ++i)  
    {   
        for (int j = 0; (i - j) >= 0 && (i +j) < lenth; ++j)  
        {  
            if (arr[i - j] != arr[i + j])  
                break;  
            int tmp = 2 * j + 1;  
            if (tmp >= res)  
                res = tmp;  
        }  
        for (int j = 0; (i - j) >= 0 && (i + j + 1) < lenth; ++j)  
        {  
            if (arr[i - j] != arr[i + j + 1])  
                break;  
            int tmp = 2 * j + 2;  
            if (tmp >= res)  
                res = tmp;  
        }  
    }  
    printf("%d\n", res);  
    return 0;  
}  
