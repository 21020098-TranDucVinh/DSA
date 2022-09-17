// A[i] <= 10^6
// min của dãy = minValue, max của dãy = maxValue
// O(maxValue)

int Count[1000005];
std::vector<int> sortArray(std::vector<int> arr)
{   
    int maxVal = 0;
    for (int i = 0; i < (int) arr.size(); ++i) {
        int x = arr[i];

        /// tìm giá trị lớn nhất của dãy
        maxVal = max(maxVal, x);

        /// đếm xem số lần xuất hiện của giá trị x trong dãy 
        Count[x]++;
    }

    vector<int> ans;
    for (int i = 1; i <= maxVal; ++i) 
        for (int j = 1; j <= Count[i]; ++j) ans.push_back(i);
    return ans;
}