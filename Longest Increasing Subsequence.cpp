// Bài toán dãy con tăng dài nhất

// O(n^2)
for (int i = 0; i < n; i++) {
  solve[i] = 1;
    for (int j = 0; j < i; j++) {
    if (array[j] < array[i]) {
      solve[i] = max(solve[i],solve[j]+1);
    }
  }
}

// O(n log k)
// Duy trì một mảng được sắp xếp. Tìm kiếm nhị phân
// Gọi mảng L là một mảng sao cho L(i) đại diện cho giá trị kết thúc 
// nhỏ nhất của tất cả các dãy con tăng dài nhất có độ dài i được tìm 
// từ trước đó. Như vậy, ta có thể tìm kiếm nhị phân mảng L để xác định
// dãy con tăng dài nhất có thể mà ta có thể tạo bằng cách thêm phần tử
// hiện tại A[i] — chỉ cần tìm chỉ số của phần tử cuối cùng trong 
// L nhỏ hơn A[i].

#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

void print_array(const char *s, int a[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i) printf(", ");
    else printf("%s: [", s);
    printf("%d", a[i]);
  }
  printf("]\n");
}

void reconstruct_print(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("[%d", a[x]);
  for (; !s.empty(); s.pop()) printf(", %d", s.top());
  printf("]\n");
}

int main() {
  int n = 11, A[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
  int L[MAX_N], L_id[MAX_N], P[MAX_N];
	// L_id thứ tự của ptu trong L, P[i] là vị trí của ptu lớn nhất trong A vẫn nhỏ hơn A[i]
  int LIS = 0, lis_end = 0;
  for (int i = 0; i < n; ++i) {
    int pos = lower_bound(L, L + LIS, A[i]) - L; //binary search
    L[pos] = A[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos - 1] : -1;
    if (pos + 1 > LIS) {
      LIS = pos + 1;
      lis_end = i;
    }

    printf("Considering element A[%d] = %d\n", i, A[i]);
    printf("LIS ending at A[%d] is of length %d: ", i, pos + 1);
    reconstruct_print(i, A, P);
    print_array("L is now", L, LIS);
    printf("\n");
  }

  printf("Final LIS is of length %d: ", LIS);
  reconstruct_print(lis_end, A, P);
  return 0;
}