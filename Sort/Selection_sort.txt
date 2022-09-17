// Mỗi lần duyệt phần tử thứ i tìm phần tử nhỏ nhất
void SelectionSort(int a[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int min = a[i];
        int index = i;
        for (int j = i + 1; j <= n; j++)
            if (min > a[j])
            {
                min = a[j];
                index = j;
            }
        int tmp;
        tmp = a[i];
        a[i] = a[index];
        a[index] = tmp;
    }
}

