// Chia để trị
// Chia đôi mảng thành 2 mảng con. Giả sử 2 mảng con đã được sắp xếp
// thì trộn 2 mảng với nhau. Cách sắp xếp 2 mảng con cũng chia 2 mảng nhỏ
// O(n * log(n)

vector<int> Merge_Sort(vector<int> A) {
    int n = (int) A.size(), k = (n-1) / 2;

    vector<int> B, C;
    for (int i = 0; i <= k; ++i) B.push_back(A[i]);
    for (int i = k+1; i < (int) A.size(); ++i) C.push_back(A[i]);

    if ((int) B.size() > 1) B = Merge_Sort(B);
    if ((int) C.size() > 1) C = Merge_Sort(C);

    A.clear();
    A.resize(B.size() + C.size());
    merge(B.begin(), B.end(), C.begin(), C.end(), A.begin()); // compare

    return A;
}