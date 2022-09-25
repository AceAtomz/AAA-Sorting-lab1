#include <iostream>
#include <cstring>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <string>
using namespace std;

int size = 1000;
int maxsize = 20000;
vector<int> times;
int runs = 5;

random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> dist(1, 1000000);

vector<int> generateNums(int N){
    vector<int> arr;
    for(int i=0; i<N;i++){
        arr.push_back(dist(generator));  // some random numbers
    }
    return arr;
}

//Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

vector<int> SelectionSort(vector<int> arr, int n){
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n-1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }

    return arr;
}

vector<int> BubbleSort(vector<int> arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    return arr;
}

vector<int> BubbleEscapeSort(vector<int> arr, int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);
           swapped = true;
        }
     }

     // IF no two elements were swapped
     // by inner loop, then break
     if (swapped == false)
        break;
   }

   return arr;
}

vector<int> InsertionSort(vector<int> arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}

void merge(int array[], int const left, int const mid, int const right){
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
         indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]= rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// vector<int> MergeSort(vector<int> arr, int const left, int const right){
//     if (left >= right)
//         return; // Returns recursively

//     auto mid = left + (right - left) / 2;
//     mergeSort(arr, left, mid);
//     mergeSort(arr, mid + 1, right);
//     merge(arr, left, mid, right);

//     return arr;
// }

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
// vector<int> QuickSort(vector<int> arr, int low, int high){
//     if (low < high) {
//         /* pi is partitioning index, arr[p] is now
//         at right place */
//         int pi = partition(arr, low, high);

//         // Separately sort elements before
//         // partition and after partition
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }

//     return arr;
// }

void printSorts(string SS, string BB, string BBE, string IS){
    ofstream fw("C:\\Users\\User\\Documents\\GitHub\\AAA-Sorting-lab1\\data.txt", ofstream::out);

    //check if file was successfully opened for writing
    if (fw.is_open())
    {
      //store array contents to text file
      fw << SS << "\n" << BB << "\n" << BBE << "\n" << IS;

      fw.close();
    }
    else cout << "Problem with opening file";

    fw.close();
}

int main(){
    string SS = "";
    string BB = "";
    string BBE = "";
    string IS = "";
    string MS = "";

    for(int n=size;n<=maxsize;n+=size){
        vector<int> vec1 = generateNums(n);
        vector<int> vec2 = generateNums(n);
        vector<int> vec3 = generateNums(n);
        vector<int> vec4 = generateNums(n);
        vector<int> vec5 = generateNums(n);

        vector<vector<int>> vectors{vec1, vec2, vec3, vec4, vec5};

        //SS
        long long total_time = 0;
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            vector<int> SSnums = SelectionSort(vectors[i], n);

            auto finish = chrono::high_resolution_clock::now();
            total_time += chrono::duration_cast<chrono::nanoseconds>(finish-start).count();;
        }
        long long average_time = total_time / runs;
        SS += to_string(average_time);
        if(n!=maxsize) SS += ",";

        //BB
        total_time = 0;
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            vector<int> BBnums = BubbleSort(vectors[i], n);

            auto finish = chrono::high_resolution_clock::now();
            int time_elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start).count();
            total_time += time_elapsed;
        }
        average_time = total_time / runs;
        BB += to_string(average_time);
        if(n!=maxsize) BB += ",";

        //BBE
        total_time = 0;
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            vector<int> BBEnums = BubbleEscapeSort(vectors[i], n);

            auto finish = chrono::high_resolution_clock::now();
            int time_elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start).count();
            total_time += time_elapsed;
        }
        average_time = total_time / runs;
        BBE += to_string(average_time);
        if(n!=maxsize) BBE += ",";

        //IS
        total_time = 0;
        for(int i=0;i<runs;i++){
            auto start = chrono::high_resolution_clock::now();
            vector<int> ISnums = InsertionSort(vectors[i], n);

            auto finish = chrono::high_resolution_clock::now();
            int time_elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start).count();
            total_time += time_elapsed;
        }
        average_time = total_time / runs;
        IS += to_string(average_time);
        if(n!=maxsize) IS += ",";

        //MS
        // total_time = 0;
        // for(int i=0;i<runs;i++){
        //     auto start = chrono::high_resolution_clock::now();
        //     vector<int> MSnums = MergeSort(vectors[i], 0, n-1);

        //     auto finish = chrono::high_resolution_clock::now();
        //     int time_elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start).count();
        //     total_time += time_elapsed;
        // }
        // average_time = total_time / runs;
        // MS += to_string(average_time);
        // if(n!=maxsize) MS += ",";
    }

    printSorts(SS, BB, BBE, IS);

    return 0;
}

