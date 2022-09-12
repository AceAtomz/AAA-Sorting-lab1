#include <iostream>
#include <cstring>
#include <vector>
#include <random>
using namespace std;

int size = 5;

vector<int> generateNums(int N){
    vector<int> arr;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> dist(1, 1000000);
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

int main(){
    vector<int> OGnums = generateNums(size);
    vector<int> SSnums = SelectionSort(OGnums, size);
    vector<int> BSnums = BubbleSort(OGnums, size);
    vector<int> BESnums = BubbleEscapeSort(OGnums, size);

    string OGprinted =  "OG: ";
    string SSprinted = "SS: ";
    string BSprinted = "BS: ";
    string BESprinted = "BE: ";
    for(int i=0; i<size;i++){
        OGprinted += to_string(OGnums[i]) + " ";
        SSprinted += to_string(SSnums[i]) + " ";
        BSprinted += to_string(BSnums[i]) + " ";
        BESprinted += to_string(BESnums[i]) + " ";
    }

    cout << OGprinted << endl << SSprinted << endl << BSprinted << endl << BESprinted << endl;

    return 0;
}

