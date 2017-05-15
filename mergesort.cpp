


#include <iostream>
using namespace std;
#define N 10
bool myless(int a, int b)
{
	return (a<b)?true:false;
}
int aux[N];
void merge(int a[],int lo,int mid,int hi)
{
	int i = lo,j = mid+1;
	for(int k = lo; k <= hi; k++)
		aux[k] = a[k];
	for(int k = lo;k<=hi;k++)
		if(i>mid) a[k] = aux[j++];
		else  if(j>hi) a[k] = aux[i++];
		else if(myless(aux[j],aux[i])) a[k] = aux[j++];
		else a[k] = aux[i++];
}

void mergesort(int a[], int lo,int hi)
{
	if(hi<=lo) return;
	int mid = lo + (hi - lo)/2;
	mergesort(a,lo,mid);
	mergesort(a,mid+1,hi);
	merge(a,lo,mid,hi);
}

int main()
{
	int a[10] = {4,2,1,7,3,9,0,6,8,5};
	mergesort(a, 0, 9);
	for(int i = 0;i<10;i++) cout<<a[i]<<endl;
	return 1;
}
