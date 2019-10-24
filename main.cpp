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
    if(v == Vehicle(Car)){
        v = Vehicle(MotorBike);
    }else{
        v = Vehicle(Car);
    }
}


int calculateDay(const vector<int>& cars, const vector<int>& motorBikes, const int& changeCost) {
    int result = 0;


    int cars_sum = sum(cars);
    int bikes_sum = sum(motorBikes);

    for (Vehicle v: {Vehicle(Car), Vehicle(MotorBike)})
        for (unsigned long i = 0; i < cars.size(); i++) {
            int car = cars[i];
            int motorBike = motorBikes[i];

            cars_sum -= car;
            bikes_sum -= motorBike;

            if (v == Vehicle(Car)) {
                result += car;
            } else {
                result += motorBike;
            }

            if (other_v_sum + changeCost < current_v_sum) {
                change(v);
            }
        }
}



    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}