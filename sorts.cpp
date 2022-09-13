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

void printSorts(string SS, string BB, string BBE){
    ofstream fw("C:\\Users\\User\\Documents\\GitHub\\AAA-Sorting-lab1\\data.txt", ofstream::out);

    //check if file was successfully opened for writing
    if (fw.is_open())
    {
      //store array contents to text file
      fw << SS << "\n" << BB << "\n" << BBE;

      fw.close();
    }
    else cout << "Problem with opening file";

    fw.close();
}

int main(){
    string SS = "";
    string BB = "";
    string BBE = "";

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
    }

    printSorts(SS, BB, BBE);

    return 0;
}

