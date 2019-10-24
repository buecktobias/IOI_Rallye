#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


enum Vehicle{
    Car=0,
    MotorBike=1
};


int sum(const vector<int>& abc){
    int result = 0;
    for(int n:abc){
        result += n;
    }
    return result;
}


void change(Vehicle& v){
    if(v == Car){
        v = Vehicle(MotorBike);
    }else{
        v = Vehicle(Car);
    }
}


int calculateDay(const vector<int>& cars, const vector<int>& motorBikes, const int& changeCost){
    int cars_sum = sum(cars);
    int bikes_sum = sum(motorBikes);

    auto v = Vehicle(Car);
    for(unsigned long i = 0; i < cars.size();i++){

        cars_sum -= cars[i];
        bikes_sum -= motorBikes[i];

    }



    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}