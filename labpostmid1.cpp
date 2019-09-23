#include<bits/stdc++.h>

using namespace std; 
  
int partition(double arr[], int l, int r, double k); 

// void isort(double *a,int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         double temp=a[i];
//         for(int j=i;j>0;j--)
//         {
//             if(a[j-1]>a[i])
//                 a[j]=a[j-1];
//             else {
//                 a[j]=temp;
//                 break;
//             }
//         }
//     }
// }
 
double findMedian(double arr[], int n) 
{ 
    sort(arr, arr+n);  // Sort the array 
    return arr[n/2];   // Return middle element 
} 
  
double kthSmallest(double arr[], int l, int r, int k) 
{ 
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1,i; 
        double median[(n+4)/5];
        for (i=0; i<n/5; i++) 
            {
                median[i] = findMedian(arr+l+i*5, 5); 
            }
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
        double medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
        int pos = partition(arr, l, r, medOfMed); 

        if (pos-l == k-1) 
           {return arr[pos];}
        if (pos-l > k-1) 
            return kthSmallest(arr, l, pos-1, k); 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
} 
  
void swap(double *a, double *b) 
{ 
    double temp = *a; 
    *a = *b; 
    *b = temp; 
} 

int partition(double arr[], int l, int r, double x) 
{ 
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 

    swap(&arr[i], &arr[r]); 

    return i; 
} 

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        long long x,y;
        double d[k];
        for(int i=0;i<k;i++)
        {
            cin>>x>>y;
            d[i]=sqrt(x*x+y*y);
        }
        cout<<kthSmallest(d, 0, k-1, (k+1)/2)<<endl;
    }
    return 0; 
}