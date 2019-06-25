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

int quick_select(int A[], int n, int k){
  int i, j, l, pivot;
  int AA[N];
  for(i = 0; i < n; i++){
    AA[i] = A[i]
  }
  l = n
  While(l > 5){
    for(i = j = 0; 5*i < l ;i++){
    AA[i] = AA[5*i+2];
      j++;
  }
    l = j;
  if(k - 5*j == 1){
    AA[j] = AA[5*j+1];
    l = j + 1;
  }
  else if(k - 5*j == 2){
    AA[j] = (AA[5*j+1] + AA[5*j+2]) / 2;
    l = j + 1;
  }
  else if(k - 5*j == 3){
    AA[j] = AA[5*j+2];
    l = j + 1;
  }
  else if(k - 5*j == 4){
    AA[j] = (AA[5*j+2] + AA[5*j+3]) / 2;
    l = j + 1;
  }
  }
  if(l - 5*j == 1){
    pivot = AA[5*j+1];
  }
  else if(l - 5*j == 2){
    pivot = (AA[5*j+1] + AA[5*j+2]) / 2;
  }
  else if(l - 5*j == 3){
    pivot = AA[5*j+2];
  }
  else if(l - 5*j == 4){
    pivot = (AA[5*j+2] + AA[5*j+3]) / 2;
  }
  else pivot = AA[5*j+3];

// 真ん中の要素をピボットとする
  pivot = A[n/2];
  A[n/2] = A[0];
  A[0] = pivot;
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

  if(j == k+1) return pivot;
  else if(j < k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+1, j-1, k);
}


int main(){
  int i,n;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
//  A[0] = 0;
//  A[1] = 17; //原始元
//  for(i=2;i<N;i++){
//    A[i] = (long long int) A[i-1] * A[1] % N;
//  }
//  for(i=0;i<N;i++){
//    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
//  }
//}
quick_select(A,n)  ;
 for(i = 0;i < n;i++){
   printf("%d\n",A[i]);
 }
}
