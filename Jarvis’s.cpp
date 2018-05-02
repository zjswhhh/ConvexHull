#include<stdio.h>
#include<iostream>
#include<vector>
//#define LOCAL
using namespace std;

struct Point
{
	int x, y;
};

/*  
	return 0 for colinear
	return 1 for clockwise 
	return 2 for counter-clockwise 
*/
int orient(Point a, Point b, Point c){
	int tmp = (b.y - a.y)*(c.x - b.x) - (c.y-b.y)*(b.x-a.x);
	if(tmp==0) return 0;
	return tmp>0? 1:2;
}

int distance(Point a, Point b){
	int tmp1 = (a.x - b.x)*(a.x - b.x);
	int tmp2 = (a.y - b.y)*(a.y - b.y);
	return tmp1+tmp2;
}

void convex_hull(Point points[], int n){
	if(n<3) return;

	vector<int> res;

	int l=0; //leftmost point 
	for(int i=1; i<n; i++){
		if(points[i].x < points[l].x){
			l=i;
		} else if(points[i].x == points[l].x) {
			if(points[i].y < points[l].x)
				l=i;
		}
	} 

	int r=0; //rightmost point 
	for(int i=1; i<n; i++){
		if(points[i].x > points[r].x){
			r=i;
		} else if(points[i].x == points[l].x) {
			if(points[i].y > points[l].x)
				r=i;
		}
	} 


	int a=l, b;
	// res.push_back(points[a]);
	// b = (a+1)%n;
	// for(int i=0; i<n; i++){
	// 	if(orient(points[a], points[i], points[b])==2)
	// 		b = i;
	// }
	// a = b;
	// int flag = 1; // flag for colinear condition 
	do{
		res.push_back(a+1);
		b = (a+1)%n;
		for(int i=0; i<n; i++){
			if(orient(points[a], points[i], points[b])==2){
				b = i;
				// flag = 0;
			} else if(orient(points[a], points[i], points[b])==0){
				if(distance(points[a], points[i]) > distance(points[a], points[b]))
					b = i;
			}
		}
		// if(flag) {
		// 	res.push_back(r+1);
		// 	break;
		// }
		a = b;
	} while(a!=l);

	cout<<res[0]<<" ";
	for(int j=res.size()-1; j>0; j--){
		cout<<res[j]<<" ";
	}
	cout<<endl;

}

int main(){
	#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

	int k, n;
	int x, y;
	cin>>k;
	while(k){
		k--;
		cin>>n;
		Point points[n];
		for(int i=0; i<n; i++){
			cin>>x>>y;
			Point p = {x, y};
			points[i] = p;
		}
		convex_hull(points, n);
	}
    return 0;
}