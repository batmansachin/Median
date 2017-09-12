#include <bits/stdc++.h>
using namespace std;
inline void scanint(int *x){
	register char c = getchar_unlocked();
	*x = 0;
	while(c < 48 || c > 57){
		c = getchar_unlocked();
	}
	while(c > 47 && c < 58){
		*x = *x * 10 + c - 48;
		c = getchar_unlocked();
	}
}
priority_queue<int> max_heap_left;
priority_queue<int ,vector<int>,greater<int> > min_heap_right;
double find_median(int x , double &median){
	if(max_heap_left.size() > min_heap_right.size() ){
		if( x < median){
			min_heap_right.push(max_heap_left.top());
			max_heap_left.pop();
			max_heap_left.push(x);
		}
		else{
			min_heap_right.push(x);
		}
		median = ((double)max_heap_left.top() + (double)min_heap_right.top())/2.0;
	}
	else if(max_heap_left.size() == min_heap_right.size()){
		if(x < median){
			max_heap_left.push(x);
			median = (double)max_heap_left.top();
		}
		else{
			min_heap_right.push(x);
			median = (double)min_heap_right.top();
		}
	}
	else{
		if(x < median){
			max_heap_left.push(x);
		}
		else{
			max_heap_left.push(min_heap_right.top());
			min_heap_right.pop();
			min_heap_right.push(x);
		}
		median = ((double)min_heap_right.top() + (double)max_heap_left.top())/2.0;

	}
}
int main(void){
	int n;
	scanint(&n);
	int p;
	double median = 0;
	for(int i = 0;i<n;i++){
		scanint(&p);
		cout<< find_median(p,median)<<endl;
	}


	return 0;
}