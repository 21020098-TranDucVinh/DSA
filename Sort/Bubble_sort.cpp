// lần lượt xét 2 phần tử i và i + 1 nếu A[i] > A[i + 1] thì đổi chỗ
// O(n^2)

std::vector<int> sortArray(std::vector<int> arr)
{
    int n = (int) arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) 
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
    }
    return arr;
}