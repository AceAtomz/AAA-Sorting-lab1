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

void printSorts(vector<int> times){
    ofstream fw("C:\\Users\\User\\Documents\\GitHub\\AAA-Sorting-lab1\\data.txt", ofstream::out);

    //check if file was successfully opened for writing
    if (fw.is_open())
    {
      //store array contents to text file
      for (int i = 0; i < 20; i++) {
        fw << times[i];
        if(i!=19) fw << ",";
        //else fw << "\n";
      }
      fw.close();
    }
    else cout << "Problem with opening file";

    fw.close();
}

int main(){
    for(int n=size;n<maxsize;n+=size){
        int total_time = 0;
        for(int i=0;i<runs;i++){
            vector<int> OGnums = generateNums(size);

            auto start = chrono::high_resolution_clock::now();
            vector<int> SSnums = SelectionSort(OGnums, size);

            auto finish = chrono::high_resolution_clock::now();
            int time_elapsed = chrono::duration_cast<chrono::nanoseconds>(finish-start).count();
            total_time += time_elapsed;
        }
        int average_time = total_time / runs;
        times.push_back(average_time);
        //cout << average_time << endl;
    }

    printSorts(times);

    //vector<int> BSnums = BubbleSort(OGnums, size);
    //vector<int> BESnums = BubbleEscapeSort(OGnums, size);

    return 0;
}

