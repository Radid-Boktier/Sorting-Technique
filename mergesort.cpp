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
// Time Complexity O(N*log2(N))
// Space Complexity O(N)
void merge(int ar[], int l, int mid, int r)
{
    vector<int> v;
    int left = l;
    int right = mid + 1;
    // cout<<"left "<<l<<"  "<<"right "<<right<<"     "<<"mid "<<mid<<endl;
    while (left <= mid && right <= r)
    {
        if (ar[left] <= ar[right])
        {
            v.push_back(ar[left]);
            left++;
        }
        else
        {
            v.push_back(ar[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        v.push_back(ar[left]);
        left++;
    }
    while (right <= r)
    {
        v.push_back(ar[right]);
        right++;
    }
    // for(auto u:v) cout<<u<<" ";
    // cout<<endl;
    for (int i = l; i <= r; i++)
        ar[i] = v[i - l];
    // for (int i = 0; i < 5; i++) cout<<ar[i]<<" ";
    cout << endl;
}
void mergeSort(int ar[], int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(ar, l, mid);
    mergeSort(ar, mid + 1, r);
    merge(ar, l, mid, r);
    return;
}
int main()
{
    optimize();
    int t = 1;
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    mergeSort(ar, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    return 0;
}
