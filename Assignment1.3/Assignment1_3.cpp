// 3/ Viết chương trình cho phép thực hiện các thao tác trên kiểu mảng:

#include <iostream>
#include <iomanip>

using namespace std;

void inputHandArray1_way(int arr[] , int n);                     // nhập mảng
void outputArray1_way(int arr[] , int n);                        // xuất mảng
int size_array(int arr);                                         // lấy kích thước mảng
int partition(int a[] , int low , int high);                     // chia trái phải
void swap(int &a , int &b);                                      // hoán vị trí
void selectSort(int a[] , int numberofarray);                    // sắp xếp chọn
void insertSort(int a[] , int numberofarray);                    // sắp xếp chèn
void bubleSort(int a[] , int numberofarray);                     // sắp xếp nổi bọt
void quickSort(int a[] , int low , int high);                    // sắp xếp nhanh
void heapSort(int arr[], int n);                                 // heapsort
int sequentialSearch(int arr[] , int n , int x);                 // Tìm kiếm tuần tự
int binarySearch(int arr[], int l, int r, int x);                // Tìm kiếm nhị phân




int main () {
    //---------------------------------------Hàm nhập, xuất mảng.------------------------------------
    int n; cout <<"Nhap so lượng phan tu cua mang : ";
    cin >> n;
    int *array = new int[n+1];
    inputHandArray1_way(array, n);
    outputArray1_way(array, n);
    
    //---------------------------------------Lấy kích thước mảng.-------------------------------------
    cout << "\nKich thuoc cua mang la : " << size_array(*array);
    
    //---------------------------------Lấy phần tử tại vị trí nào đó.---------------------------------
    int k;
    cout<<"\nNhap vi tri phan tu ban can thao tac k = " ;
    cin >> k;
    cout<<"Gia tri cua phan tu tai vi tri array[" << k - 1 << "] la : " << array[k-1];
    
    //Sắp xếp tăng, giảm (Chọn trực tiếp, Chèn trực tiếp, Nổi bọt BubbleSort, QuickSort, HeapSort, ShellSort, RadixSort)
    bubleSort(array, n);
    cout << "\nSau khi sap xep t duoc day nhu sau : ";
    outputArray1_way(array, n);
    
    //-----------------Tìm phần tử nào đó trong mảng (tuần tự, nhị phân, nội suy).--------------------
    int h; cout << "\nNhap gia tri can tim trong mang : "; cin >> h;
    if (sequentialSearch(array, n, h) == -1) cout << "KHONG TIM THAY GIA TRI " << h << " TRONG MANG !!!" << endl;
    else cout << "VI TRI TUONG UNG VOI GIA TRI " << h << " LA PHAN TU THU " << sequentialSearch(array, n, h) + 1 << endl;
    return 0;
}

void inputHandArray1_way(int arr[] , int n){                     // nhập mảng
    for ( int i = 0 ; i < n ; i ++){
        cout << "Nhap a[" << i <<"] = ";
        cin >> arr[i];
    }
}

void outputArray1_way(int arr[] , int n){                        // xuất mảng
    for ( int i = 0 ; i < n ; i ++){
        cout << arr[i] << " ";
    }
}

int size_array(int arr){                                         // lấy kích thước mảng
    int *size = &arr;
    return sizeof(size);
}

void swap(int &a , int &b){     // hoán vị trí
    int temp = a ;
    a = b;
    b = temp;
}

void selectSort(int a[] , int numberofarray){                    // sắp xếp chọn
    for ( int i = 0 ; i < numberofarray - 1 ; i++){
        int min = i , j;
        for ( j = i + 1 ; j < numberofarray ; j++){
            if ( a[j] < a[min] ) min = j;
        }
        swap(a[i] , a[min]);
    }
}

void insertSort(int a[] , int numberofarray){                    // sắp xếp chèn
    for ( int i = 1; i < numberofarray ; i++){
        int key = a[i] , j = i - 1;
        while ( j >= 0 && key < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void bubleSort(int a[] , int numberofarray){                      // sắp xếp nổi bọt
    for ( int i = 0 ; i < numberofarray - 1 ; i++){
        bool haveswap = false;
        for ( int j = 0 ; j < numberofarray - i - 1; j++){
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                haveswap = true;
            }
        }
        if ( haveswap == false) break;
    }
}

int partition(int a[] , int low , int high){                     // chia trái phải
    int left = low;
    int right = high - 1;
    int pivot = a[high];
    while ( true ){
        while (a[left] < pivot && left <= right) left++;
        while (a[right] > pivot && left <= right) right--;
        if ( left >= right ) break;
        swap(a[left] , a[right]);
        left++; right--;
    }
    swap(a[left] , a[high]);
    return left;
}

void quickSort(int a[] , int low , int high){                    // sắp xếp nhanh
    if ( low < high ){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);              // sắp xếp bên trái
        quickSort(a, pi + 1 , high);            // sắp xếp bên phải
    }
}

void heap(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i){
        swap(arr[i], arr[largest]);
        heap(arr, n, largest);
    }
}

void heapSort(int arr[], int n){                                 // heapsort
    for (int i = n / 2 - 1; i >= 0; i--) heap(arr, n, i);
    for (int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}

int sequentialSearch(int arr[], int n , int x){                  // Tìm kiếm tuần tự
    int i = 0 ;
    while (i <n && arr[i]!=x){
        i = i+1;
        if (i == n) return -1;
    }
    return (i);
}

int binarySearch(int arr[], int l, int r, int x) {               // Tìm kiếm nhị phân
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x)   return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

