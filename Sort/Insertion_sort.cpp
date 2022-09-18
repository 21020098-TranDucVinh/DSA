// O(n^2)
// Xem dãy cần sắp xếp gồm 2 dãy 
// Đích: các phần tử đã sắp đúng vị trí
// Nguồn Các phần tử còn lại của dãy
// Trong mỗi bước lặp, chèn lần lượt các phần tử ở dãy nguồn vào dãy
// đích để được 1 dãy đích được sắp.

void InsertionSort(int a[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        int j = i - 1;
        bool ok = false;
        int temp = a[i];
        while ((j >= 1) && !ok)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                ok = true;
        }
        a[j + 1] = temp;
    }
}
