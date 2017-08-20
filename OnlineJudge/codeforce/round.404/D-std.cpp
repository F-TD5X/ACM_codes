<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdint>

using namespace std;
typedef long long ll;
int mod = (int)1e9 + 7;

int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) { 
	if (!a) {
		x = 0;
		y = 1;
		return b;
	}
	int64_t x1, y1;
	int64_t d = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

inline int addMod(int a, int b, int m = mod) {
	return ((int64_t)a + b) % m;
}

inline int mulMod(int a, int b, int m = mod) {
	return ((int64_t)a * b) % m;
}

inline int divMod(int a, int b, int m = mod) {
	int64_t x, y;
	int64_t g = extGcd(b, m, x, y);
	if (g != 1) {
		cerr << "Bad gcd!" << endl;
		for (;;);
	}
	x = (x % m + m) % m;
	return mulMod(a, x, m);
}

const int factRange = 1000000;
int fact[factRange];

inline void precalcFactorials() {
	fact[0] = 1;
	for (int i = 1; i < factRange; i++) {
		fact[i] = mulMod(fact[i-1], i);
	}
}

inline int F(int n) {
	return (n < 0) ? 0 : fact[n];
}

inline int C(int k, int n) {
	return divMod(F(n), mulMod(F(n-k), F(k)));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
	string s;
	cin >> s;
	precalcFactorials();
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
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdint>

using namespace std;
typedef long long ll;
int mod = (int)1e9 + 7;

int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) { 
	if (!a) {
		x = 0;
		y = 1;
		return b;
	}
	int64_t x1, y1;
	int64_t d = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

inline int addMod(int a, int b, int m = mod) {
	return ((int64_t)a + b) % m;
}

inline int mulMod(int a, int b, int m = mod) {
	return ((int64_t)a * b) % m;
}

inline int divMod(int a, int b, int m = mod) {
	int64_t x, y;
	int64_t g = extGcd(b, m, x, y);
	if (g != 1) {
		cerr << "Bad gcd!" << endl;
		for (;;);
	}
	x = (x % m + m) % m;
	return mulMod(a, x, m);
}

const int factRange = 1000000;
int fact[factRange];

inline void precalcFactorials() {
	fact[0] = 1;
	for (int i = 1; i < factRange; i++) {
		fact[i] = mulMod(fact[i-1], i);
	}
}

inline int F(int n) {
	return (n < 0) ? 0 : fact[n];
}

inline int C(int k, int n) {
	return divMod(F(n), mulMod(F(n-k), F(k)));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
	string s;
	cin >> s;
	precalcFactorials();
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
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdint>

using namespace std;
typedef long long ll;
int mod = (int)1e9 + 7;

int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) { 
	if (!a) {
		x = 0;
		y = 1;
		return b;
	}
	int64_t x1, y1;
	int64_t d = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

inline int addMod(int a, int b, int m = mod) {
	return ((int64_t)a + b) % m;
}

inline int mulMod(int a, int b, int m = mod) {
	return ((int64_t)a * b) % m;
}

inline int divMod(int a, int b, int m = mod) {
	int64_t x, y;
	int64_t g = extGcd(b, m, x, y);
	if (g != 1) {
		cerr << "Bad gcd!" << endl;
		for (;;);
	}
	x = (x % m + m) % m;
	return mulMod(a, x, m);
}

const int factRange = 1000000;
int fact[factRange];

inline void precalcFactorials() {
	fact[0] = 1;
	for (int i = 1; i < factRange; i++) {
		fact[i] = mulMod(fact[i-1], i);
	}
}

inline int F(int n) {
	return (n < 0) ? 0 : fact[n];
}

inline int C(int k, int n) {
	return divMod(F(n), mulMod(F(n-k), F(k)));
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
#endif
	string s;
	cin >> s;
	precalcFactorials();
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
