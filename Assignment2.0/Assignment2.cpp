#include <iostream>
using namespace std;

void input(int *a, int n){
    for(int i = 0; i < n; i++){
        cout<<"Phan tu thu "<<i<<":";
        cin >> a[i];
    }
}



void output(int a[], int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

bool ascending(int l, int r){
    return l > r;
}

bool descending(int l, int r){
    return l < r;
}

void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void selectionSort(int arr[], int n, bool (*func_ptr)(int, int)=ascending){
    int i, j, min_idx;
 
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++){
            if((*func_ptr)(arr[min_idx],arr[j]))
                min_idx = j;
        }
 
        swap(arr[min_idx], arr[i]);
    }
}

void bubbleSort(int arr[], int n, bool (*func_ptr)(int, int) =ascending){
    int i, j;
    for (i = 0; i < n-1; i++){         
       for (j = 0; j < n-i-1; j++){
           if ((*func_ptr)(arr[j], arr[j + 1]))
              swap(arr[j], arr[j+1]);
       }
    }
}

void insertionSort(int arr[], int n, bool (*func_ptr)(int , int)=ascending){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && (*func_ptr)(arr[j],key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition (int arr[], int low, int high, bool (*func_ptr)(int , int)){ 
    int pivot = arr[high]; // pivot 
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (!(*func_ptr)(arr[j],pivot)) 
        { 
            i++;
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high, bool (*func_ptr)(int, int)=ascending) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high, func_ptr); 
  
        quickSort(arr, low, pi - 1, func_ptr); 
        quickSort(arr, pi + 1, high, func_ptr); 
    } 
} 


// void quickSort(int *a,int left,int right,bool CompFunc(int ,int ))
//     {
//         int i=left;int j=right;
//         int x=*(a+(left+right)/2);
//         do
//         {
//             while(CompFunc(*(a+i),x)) i++; 
//             while(CompFunc(x,*(a+i))) j--; 
//             if(i<=j)
//                 {
//                     swap(*(a+i),*(a+j));
//                     i++;j--;
//                 }
//         } while (i<=j);
//         if(i<right) quickSort(a,i, right,CompFunc);
//         if(j>left) quickSort(a,left, j,CompFunc);
//     }
void quickSortUtility(int a[], int n, bool (*func_ptr)(int , int)=ascending){
   quickSort(a, 0, n - 1, func_ptr);
 }
void sorting(void (*func_ptr)(int*, int, bool (*func)(int, int)), int a[], int n, bool (*f)(int, int)=ascending){
    (*func_ptr)(a,n,f);
}

int search(int a[], int n, int x, bool (*func_ptr)(int , int)=ascending){
    int d = 0;
    int c = n-1; 
    int g;
    do {
       g = (d+c)/2;
       if (x == *(a+g)) return g;
       else 
            if (!func_ptr(x, *(a+g))) c = g-1;
            else d = g+1;
    } while (d<=c);
    return -1;
}

int main(){
    int n;
    cout<<"Nhập số phần tử của mảng:"; cin >> n;
    int *a = new int[n];
    cout<<"Nhập mảng a:"<<endl;
    input(a,n);
    cout<<"Mảng vừa nhập:";
    output(a,n);
    cout<<"Mảng theo thứ tự tăng dần sx bằng pp selectionSort:"<<endl;
    sorting(selectionSort, a,n);
    output(a,n);
    cout<<"Mảng theo thứ tự giảm dần sx bằng pp bubbleSort:"<<endl;
    sorting(bubbleSort, a, n, descending);
    output(a,n);
    cout<<"Mảng theo thứ tự tăng dần sx bằng pp quickSort:"<<endl;
    sorting(quickSortUtility,a,n,ascending);
    output(a,n);
    cout<<"Mảng theo thứ tự giảm dần sx bằng pp insertionSort:"<<endl;  
    sorting(insertionSort,a,n,ascending);
    output(a,n);
    int k;
    cout<<"Nhập k bất kỳ: "; cin>>k;
    cout << search(a,n,k,ascending);
    return 0;
}



