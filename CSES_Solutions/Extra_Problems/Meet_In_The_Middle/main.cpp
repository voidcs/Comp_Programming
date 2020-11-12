#include bitsstdc++.h
 
using namespace std;
typedef long long ll;
const int maxN = 40;
 
int N, t[maxN];
ll x, sum, cnt;
mapll,int freq;
 
int main(){
	scanf(%d %lld, &N, &x);
	for(int i = 0; i  N; i++)
		scanf(%d, &t[i]);
	
	if(N == 1){
		if(x == t[0])	printf(1n);
		else 			printf(0n);
		return 0;
	}
	
	for(int i = 0; i  (1(N2-1)); i++){
		sum = 0;
		for(int j = 0; j  N2-1; j++)
			if(i&(1j))
				sum += t[j];
		freq[sum]++;
	}
	
	for(int i = 0; i  (1((N+1)2+1)); i++){
		sum = 0;
		for(int j = 0; j  (N+1)2+1; j++)
			if(i&(1j))
				sum += t[N2-1+j];
		if(freq.find(x-sum) != freq.end())
			cnt += freq[x-sum];
	}
	
	printf(%lldn, cnt);
}