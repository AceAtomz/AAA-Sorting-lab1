#include <iostream>
#include <cstring>
#include <vector>
#include <random>
using namespace std;

vector<int> generateNums(int N){
    vector<int> arr;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for(int i=0; i<N;i++){
        arr.push_back(dist(generator));  // some random numbers
        cout << arr[i] << endl;
    }

    return arr;
}

int main(){
    vector<int> nums = generateNums(5);
    return 0;
}

