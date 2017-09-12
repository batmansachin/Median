#include <bits/stdc++.h>
using namespace std;

inline void scanint(int *x){
	register char c = getchar_unlocked();
	*x = 0;
	while(c < 48 || c > 57){
		c = getchar_unlocked();
	}
	while(c > 47 && c < 58 ){
		*x = *x*10 + c-48;
		c = getchar_unlocked();
	}
}

double KthElement(int *a,int start1,int end1,int *b,int start2,int end2,int k){
	if(start1 > end1-1)return b[start1 + k -1];
	if(start2 > end2-1) return a[start2 + k -1];
	if(k == 1) return min(a[start1],b[start2]);
	int aMax = INT_MAX;
	int bMax = INT_MAX;
	if((start1 + k/2 - 1) < end1) aMax = a[start1 + k/2 -1];
	if((start2 + k/2 - 1) < end2) bMax = b[start2 + k/2 -1];
	if(aMax < bMax){
		return KthElement(a , start1+k/2 , end1 , b , start2 ,end2,k-k/2);
	}
	else{
		return KthElement(a , start1 , end1 , b , start2+k/2 ,end2,k-k/2);
	}
}

int main(void){
	int n;
	int m;
	printf("Enter the Size of 1st Array\n");
	scanint(&n);
	
	int a[n];
	printf("Enter the Element of 1st array\n");
	for(int i = 0;i<n;i++){
		scanint(&a[i]);
	}
	printf("Enter the Size of nd Array");
	scanint(&m);
	int b[m];
	printf("Enter the Element of 2nd array\n");
	for(int i = 0;i<m;i++){
		scanint(&b[i]);
	}
	double ans = 0;
	int l = (n+m+1)/2;
	int r = (n+m+2)/2;
	
	if(l==r){
		
		ans = KthElement(a,0,n,b,0,m,l);
	}
	else{
		
		ans = (KthElement(a,0,n,b,0,m,l)+KthElement(a,0,n,b,0,m,r))/2.0;
	}
	cout<<ans<<endl;
	return 0;
}