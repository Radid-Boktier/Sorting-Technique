#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define optimize()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);

#define MOD 1000000007
const double PI = acos(-1);
const int MX = 1e7 + 123;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

const int mx = 1e5 + 123;

// Time Complexity O(N log(N))
// Space Complexity O(1)

int Sort(int ar[], int l, int r)
{
    int i = l, j = r;
    int pivot = ar[l];
    while (i < j)
    {
        while (pivot >= ar[i] && i < r)
            i++;
        while (pivot < ar[j] && j > l)
            j--;
        if (i < j)
            swap(ar[i], ar[j]);
    }
    swap(ar[l], ar[j]);
    return j;
}
void quickSort(int ar[], int low, int high)
{
    if (low < high)
    {
        int pIndex = Sort(ar, low, high);
        quickSort(ar, low, pIndex - 1);
        quickSort(ar, pIndex + 1, high);
    }
    return;
}
int main()
{
    optimize();
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    quickSort(ar, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    return 0;
}
