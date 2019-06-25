#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}


/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
  int i, j, k, pivot;
    if (n == 1) return;
else  pivot = A[n/2];
      A[n/2] = A[0];
      A[0] = pivot;
  for(i = j = k = 1; i < n; i++){
    if(A[i] < pivot){
      swap(A+i, A+j),swap(A+k,A+j);
      j++, k++;
    }
    if(A[i] == pivot){
      swap(A+i, A+j);
      j++;
    }
  }
  swap(A + 0, A + k-1);
    if(k == 1 && j == n) return;
    if(k == 1 || k == 2) return quick_sort(A+j,n-j);
    if(j == n) return quick_sort(A+0,k-2);
    else return  quick_sort(A+0,k-1), quick_sort(A+j,n-j);
}

int main(){
  int i,n;
//  A[0] = 0;
//  A[1] = 17; //原始元
//  for(i=2;i<N;i++){
//    A[i] = (long long int) A[i-1] * A[1] % N;
//  }
scanf("%d", &n);
for(i = 0; i < n; i++){
  scanf("%d", &A[i]);
}

//  quick_sort(A, N);
//  for(i=0;i<N;i++){
//    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
//  }

 quick_sort(A,n)  ;
  for(i = 0;i < n;i++){
    printf("%d\n",A[i]);
  }
}
