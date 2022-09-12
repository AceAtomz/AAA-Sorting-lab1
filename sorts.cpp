#include <iostream>
#include <cstring>
#include <vector>
#include <random>
using namespace std;

vector<int> generateNums(int N){
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> dist(1, 10);
    int number = dist(generator); // a random number
    cout << number << endl;
}

void main(){
    vector<int> J = generateNums(5);
}