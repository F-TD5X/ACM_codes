<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[111][111];
int n,k;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n >>k;
	if(n*n<k) return puts("-1");
	else{
		int cnt=0;
		bool flag=1;
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				if(cnt<k){
					if(k-cnt==1 && i==j){
						m[i][j]=1;cnt++;
					}
					else if(k-cnt==1 && i!=j && i<n-1){
						m[i+1][i+1]=1;cnt++;
					}
					else if(k-cnt>=2){
						m[i][j]=m[j][i]=1;cnt+=i==j?1:2;
					}
					else
						flag=0;
				}
		if(!flag) return puts("-1");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout << m[i][j] <<" ";
			cout << endl;
		}
	}
	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[111][111];
int n,k;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n >>k;
	if(n*n<k) return puts("-1");
	else{
		int cnt=0;
		bool flag=1;
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				if(cnt<k){
					if(k-cnt==1 && i==j){
						m[i][j]=1;cnt++;
					}
					else if(k-cnt==1 && i!=j && i<n-1){
						m[i+1][i+1]=1;cnt++;
					}
					else if(k-cnt>=2){
						m[i][j]=m[j][i]=1;cnt+=i==j?1:2;
					}
					else
						flag=0;
				}
		if(!flag) return puts("-1");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout << m[i][j] <<" ";
			cout << endl;
		}
	}
	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m[111][111];
int n,k;


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("A.in","r",stdin);
    //freopen("A.out","w",stdout);
#endif
	cin >> n >>k;
	if(n*n<k) return puts("-1");
	else{
		int cnt=0;
		bool flag=1;
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				if(cnt<k){
					if(k-cnt==1 && i==j){
						m[i][j]=1;cnt++;
					}
					else if(k-cnt==1 && i!=j && i<n-1){
						m[i+1][i+1]=1;cnt++;
					}
					else if(k-cnt>=2){
						m[i][j]=m[j][i]=1;cnt+=i==j?1:2;
					}
					else
						flag=0;
				}
		if(!flag) return puts("-1");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout << m[i][j] <<" ";
			cout << endl;
		}
	}
	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
