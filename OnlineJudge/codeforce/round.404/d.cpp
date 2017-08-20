<<<<<<< HEAD
<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
const ll m=1e9+7;
const int factRange = 1000000;
ll fact[factRange];

ll extraGcd(ll a,ll b,ll &x,ll &y){
	if(!a){
		x=0;y=1;return b;
	}
	ll x1,y1;
	ll d=extraGcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return d;
}

ll F(ll n) {
	return (n < 0) ? 0 : fact[n];
}

ll addMod(ll a,ll b){
	return (a+b)%m;
}

ll mulMod(ll a,ll b){
	return (a*b)%m;
}

void Init() {
	fact[0] = 1;
	for (int i = 1; i < factRange; i++) {
		fact[i] = mulMod(fact[i-1], i);
	}
}

ll divMod(ll a,ll b){
	ll x,y;
	ll g=extraGcd(a,b,x,y);
	x=(x%m+m)%m;
	return mulMod(a,x);
}

ll C(ll k,ll n){
	return divMod(F(n),mulMod(F(n-k),F(k)));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
	cin >> s;
	Init();
	vector<int> ol(s.size()),cr(s.size());
	
	ol[0]=((s[0]=='(')?1:0);
	for(int i=1;i<s.size();i++)
		ol[i]=ol[i-1]+((s[i]=='(')?1:0);
	
	cr[s.size()-1]=((s[s.size()-1]==')')?1:0);
	for(int i=s.size()-2;i>=0;i--){
		cr[i]=cr[i+1]+((s[i]==')')?1:0);
	}
	
	ll res=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='(' || cr[i]==0){
			continue;
		}
		ll add=C(ol[i],ol[i]+cr[i]-1);
		res=addMod(res,add);
	}
	printf("%I64d\n",res);

	return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
const ll m=1e9+7;
const int factRange = 1000000;
ll fact[factRange];

ll extraGcd(ll a,ll b,ll &x,ll &y){
	if(!a){
		x=0;y=1;return b;
	}
	ll x1,y1;
	ll d=extraGcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return d;
}

ll F(ll n) {
	return (n < 0) ? 0 : fact[n];
}

ll addMod(ll a,ll b){
	return (a+b)%m;
}

ll mulMod(ll a,ll b){
	return (a*b)%m;
}

void Init() {
	fact[0] = 1;
	for (int i = 1; i < factRange; i++) {
		fact[i] = mulMod(fact[i-1], i);
	}
}

ll divMod(ll a,ll b){
	ll x,y;
	ll g=extraGcd(a,b,x,y);
	x=(x%m+m)%m;
	return mulMod(a,x);
}

ll C(ll k,ll n){
	return divMod(F(n),mulMod(F(n-k),F(k)));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
	cin >> s;
	Init();
	vector<int> ol(s.size()),cr(s.size());
	
	ol[0]=((s[0]=='(')?1:0);
	for(int i=1;i<s.size();i++)
		ol[i]=ol[i-1]+((s[i]=='(')?1:0);
	
	cr[s.size()-1]=((s[s.size()-1]==')')?1:0);
	for(int i=s.size()-2;i>=0;i--){
		cr[i]=cr[i+1]+((s[i]==')')?1:0);
	}
	
	ll res=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='(' || cr[i]==0){
			continue;
		}
		ll add=C(ol[i],ol[i]+cr[i]-1);
		res=addMod(res,add);
	}
	printf("%I64d\n",res);

	return 0;
}
>>>>>>> e30efc2bee7b85c64b5cc40b21a84d4cb2f8cc56
=======
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
const ll m=1e9+7;
const int factRange = 1000000;
ll fact[factRange];

ll extraGcd(ll a,ll b,ll &x,ll &y){
	if(!a){
		x=0;y=1;return b;
	}
	ll x1,y1;
	ll d=extraGcd(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return d;
}

ll F(ll n) {
	return (n < 0) ? 0 : fact[n];
}

ll addMod(ll a,ll b){
	return (a+b)%m;
}

ll mulMod(ll a,ll b){
	return (a*b)%m;
}

void Init() {
	fact[0] = 1;
	for (int i = 1; i < factRange; i++) {
		fact[i] = mulMod(fact[i-1], i);
	}
}

ll divMod(ll a,ll b){
	ll x,y;
	ll g=extraGcd(a,b,x,y);
	x=(x%m+m)%m;
	return mulMod(a,x);
}

ll C(ll k,ll n){
	return divMod(F(n),mulMod(F(n-k),F(k)));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
	cin >> s;
	Init();
	vector<int> ol(s.size()),cr(s.size());
	
	ol[0]=((s[0]=='(')?1:0);
	for(int i=1;i<s.size();i++)
		ol[i]=ol[i-1]+((s[i]=='(')?1:0);
	
	cr[s.size()-1]=((s[s.size()-1]==')')?1:0);
	for(int i=s.size()-2;i>=0;i--){
		cr[i]=cr[i+1]+((s[i]==')')?1:0);
	}
	
	ll res=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='(' || cr[i]==0){
			continue;
		}
		ll add=C(ol[i],ol[i]+cr[i]-1);
		res=addMod(res,add);
	}
	printf("%I64d\n",res);

	return 0;
}
>>>>>>> f02e15c16e5c2d0b5fec3c050b7fc6ea46695739
