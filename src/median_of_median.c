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
  int i, j, pivot;

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

int p(int A[], int n){ //数列Aとその要素数nによって中央値の中央値を出す関数
  int i, j, l;
  int AA[N];
for(i = 0; i < n; i++){ //AA[]にA[]をコピー
  AA[i] = A[i];
}
l = n;
  for(i = j = 0; 5*i <= l-5 ;i++){
  AA[i] = quick_select(AA+5*i,5,2);
    j++;
}
    if(l % 5 != 0){
      AA[j] = quick_select(AA+5*j, l % 5, l % 10);
      l = j + 1;
}
    else l = j;
return quick_select(AA, l, l/2);
}

int median_of_median(int A[], int n, int k){
  int i, j, l, pivot;
// 真ん中の要素をピボットとする
  pivot = p(A,n);
  for(i = 0; i < n; i++){
    if(pivot == A[i]) l = i;
  }
  A[l] = A[0];
  A[0] = pivot;
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

  if(j == k+1) return pivot;
  else if(j < k+1) return median_of_median(A+j, n-j, k-j);
  else return median_of_median(A+1, j-1, k);
}


int main(){
  int i,n,k;

  scanf("%d%d", &n, &k);
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
printf("%d\n", median_of_median(A,n,k));
}
