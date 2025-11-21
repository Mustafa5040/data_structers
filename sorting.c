#include <stdio.h>
#include <stdlib.h>


#define DEBUG 0
#if DEBUG
  #define DPRINT(...) printf(__VA_ARGS__)
#else
  #define DPRINT(...)
#endif



void merge(int* arr, size_t length, int l, int r, int m);



void selectionSort(int *arr, size_t length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int index_of_smallest = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[index_of_smallest])
            {
                index_of_smallest = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index_of_smallest];
        arr[index_of_smallest] = temp;
    }
}
void insertionSort(int *arr, size_t length)
{
    for (int p = 1; p < length; p++)
    {

        int temp = arr[p];
        int i;
        for (i = p; i > 0 && arr[i - 1] > temp; i--)
        {
            arr[i] = arr[i - 1];
            DPRINT("ic i:  %d\n", i);
        }
        DPRINT("dis i: %d\n", i);
        arr[i] = temp;
    }
}

// O(N^2) Time Complexity.
void bubbleSort(int *arr, size_t length)
{

    for (int i = 0; i < length - 1; i++) // for i. largest number
    {
        // last i numbers are already sorted.This is the actual sort process.
        DPRINT("arr[i]: %d\n", arr[i]);
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swapping with XOR
                DPRINT("arr[j]: %d\n", arr[j]);
                arr[j] = arr[j + 1] ^ arr[j];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
            }
        }
    }
}

// TO DO: TAMAMEN POINTER ARITMETIĞINE GEÇİR *(arr + i) gibi...
void mergeSort(int* arr,size_t length, int l, int r){ //recursive
    if(l < r){
        int mid = (int) ( (l+r) / 2 );
        mergeSort(arr,length,l,mid); // left arr
        mergeSort(arr,length,mid+1,r); // right arr
        merge(arr,length,l,r,mid);
    }

}
void merge(int* arr, size_t length, int l, int r, int m){
    DPRINT("-------------MERGE ITERATION-----------------\nLEFT: %d, MID: %d, RIGHT: %d\n",l,m,r);
    int* l_arr = malloc( (m-l+1)*sizeof(int));
    int* r_arr = malloc( (r-m) * sizeof(int));
    
    DPRINT("PRINTING INITIAL ARRAY: ");
    for(int i = 0; i < length; i++){
        DPRINT("%d,",arr[i]);
    }
    DPRINT("\n");
    

    //copy left array
    for(int i = 0; i+l <= m; i++){
        DPRINT("LEFT copying of %d to %d: %d\n",arr[l],arr[m], arr[i+l]);
        l_arr[i] = arr[i+l];
    }
    //copy right array
    for(int i = 0; i+m+1 <= r; i++){
        DPRINT("RIGHT copying of %d to %d: %d\n",arr[m+1],arr[r], arr[i+m+1]);
        r_arr[i] = arr[i + m + 1];
    }



    // actual merging
    int l_ptr = 0;
    int r_ptr = 0;
    int arr_ptr = l;

    while(arr_ptr < length && l_ptr < (m-l+1) && r_ptr < (r-m)){

        if(l_arr[l_ptr] < r_arr[r_ptr] ){
            DPRINT("l_arr < r_arr, indexs: %d < %d, elements: %d < %d\n",l_ptr,r_ptr,l_arr[l_ptr],r_arr[r_ptr]);
            arr[arr_ptr] = l_arr[l_ptr];
            arr_ptr++;
            l_ptr++;
        }

        else{
            DPRINT("r_arr <= l_arr, indexs: %d < %d, elements: %d < %d\n",r_ptr,l_ptr,r_arr[r_ptr],l_arr[l_ptr]);
            arr[arr_ptr] = r_arr[r_ptr];
            arr_ptr++;
            r_ptr++;
        }

    }

    //check for any remainings on both of the lists
    while(l_ptr < (m - l + 1) && arr_ptr < length){
        arr[arr_ptr] = l_arr[l_ptr];
        arr_ptr++;
        l_ptr++;
    }
    while(r_ptr < (r-m) && arr_ptr < length){
        arr[arr_ptr] = r_arr[r_ptr];
        arr_ptr++;
        r_ptr++;
    }

    DPRINT("MERGED PARTITION: ");

    for(int i = 0; i < arr_ptr; i++){
        DPRINT("%d,",arr[i]);
    }
    DPRINT("\n");

    free(l_arr);
    free(r_arr);
    DPRINT("------------------END OF MERGE--------------------\n");

}

int lomuto_partition(int* arr, size_t length,int l, int r){

    int i = -1;
    int j = 0;

    while(j+l < r){

        if(arr[j+l] < arr[r]){

            int temp = arr[++i + l];
            arr[i + l] = arr[j + l];
            arr[j + l] = temp;
        }
        j++;
    }
    int temp = arr[i+l+1];
    arr[i+l+1] = arr[r];
    arr[r] = temp;
    return i+l+1;   
}

void quickSort(int* arr, size_t length, int l, int r){
    if(l < r){
    int m = lomuto_partition(arr,length,l,r);
    quickSort(arr,length,l,m-1); // left partition
    quickSort(arr,length,m+1,r); // right partition
    }
   
}


int main()
{
    int arr[] = {23, 78, 45, 8, 56, 32};
    //int arr[] =  {10,80,30,90,40};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    //mergeSort(arr, length,0,length-1);
    quickSort(arr,length,0,length-1);
    DPRINT("-------------PRINTING ARR------------\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", arr[i]); 

    }
    printf("\n");
}