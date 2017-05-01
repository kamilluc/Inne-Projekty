#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void mergesort(int*T,int l, int r);

void merge(int*T,int l, int i, int r){
	int *B=new int[i-l+1];
	int *C=new int[r-i];
	int b=0;
	int c=0;
	int k=l;
	do{
	B[b] = T[l+b++];
	}while(b<=i);
	do{
		C[c] = T[l+b++];
	}while(l+b<=r);
	b=0;
	c=0;
	do{
		if(B[b]<=C[c])
			T[k++]=B[b++];
		else
			T[k++]=C[c++];
	}while(b<=(i-l+1) && c<=r-i);
	
	if(b<=i-l+1)
		for(int j=b; j<=i-l+1; j++)
			B[j]=T[k++];
	else
		for(int j=c; j<=r-i; j++)
			C[j]=T[k++];
}

void QuickSort(int *t, int l, int r);

template <typename T>
long partition (T*A, long l, long r){
	T x=A[r];
	long i=l-1;
	for(;l<r;++l)
		if(A[l]<=x)
			swap(A[++i],A[l]);
//	swap(A[i+l],A[r]);	???
	return i+l;
}
int main(){
	srand( time( NULL ) );
	
	int tab[10];
	
	for(int i=0;i<10;i++){
		tab[i]=(rand()%100)+1;
	}
	
	for(int i=0;i<10;i++){
		cout<<tab[i]<<endl;
	}
	
	cout<<endl<<endl;
	
	mergesort(tab,0,9);
	
	
	for(int i=0;i<10;i++){
		cout<<tab[i]<<endl;
	}
	
	
	return 0;
}


void QuickSort(int *t, int l, int r){
	if (l<r){
		long p=partition(t,l,r);
		QuickSort(t,l,p-1);
		QuickSort(t,p+1,r);
	}
}

void mergesort(int*T,int l, int r){
	if(l<r){
		int i=(r+l)/2;
		mergesort(T,l,i);
		mergesort(T,i+1,r);
		merge(T,l,i,r);
	}
}
