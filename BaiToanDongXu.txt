// hello world của quy hoạch động
// Cho bạn các đồng xu có giá trị c_1, c_2,..., c_k. 
// Nhiệm vụ của bạn là lấy ít xu nhất có thể sao cho tổng giá trị 
// của chúng bằng TT cho trước. Lưu ý rằng, không giới hạn số lần 
// sử dụng một loại đồng xu.

int value[T+1] //T là tổng giá trị các đồng xu mà đề bài cho trước, value là số xu ít nhất để đạt tổng giá trị T
int solve(int x) {
  value[0] = 0;
  for (int x = 1; x <= n; x++) {
    value[x] = INF;
    for (auto c : coins) { //Với các giá trị c của đồng xu
      if (x-c >= 0) {
        value[x] = min(value[x], value[x-c]+1);
      }
    }
  }
}