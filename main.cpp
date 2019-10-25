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
    int smallestResult = INT32_MAX;


    int cars_sum = sum(cars);
    int bikes_sum = sum(motorBikes);

    for (Vehicle startVehicle: {Vehicle(Car), Vehicle(MotorBike)}) {
        int result = 0;
        for (unsigned long i = 0; i < cars.size(); i++) {
            const int car = cars[i];
            const int motorBike = motorBikes[i];

            cars_sum -= car;
            bikes_sum -= motorBike;
            int othersSum;
            int currentSum;
            vector<int> current;
            vector<int> other;
            if (startVehicle == Vehicle(Car)) {
                // car
                current = cars;
                other = motorBikes;
                currentSum = cars_sum;
                othersSum = bikes_sum;
                result += car;
            } else {
                // motor bike
                current = motorBikes;
                other = cars;
                currentSum = bikes_sum;
                othersSum = cars_sum;
                result += motorBike;
            }

            if (othersSum + changeCost < currentSum) {
                change(startVehicle);
                result += changeCost;
                break;
            }
        }

        if(result < smallestResult){
            smallestResult = result;
        }

    }
    return smallestResult;
}


int calculate(const vector<int>& cars, const vector<int>& motorBikes, const int& lengthDay, const int& changeCost){
    int result = 0;
    for(unsigned long day=0; day < cars.size(); day+=lengthDay){
        vector<int> dayCars (cars.begin() + day, cars.begin() + day + lengthDay);
        vector<int> dayMotorBikes(motorBikes.begin() + day, motorBikes.begin() + day + lengthDay);
        result += calculateDay(dayCars, dayMotorBikes, changeCost);
    }
    return result;
}


int main() {
    /* Input
    int testCases;
    cin >> testCases;
    for(int testCase=0; testCase < testCases;testCase++){
        int days, checkpoints, costToChange;
        cin >> days;
        cin >> checkpoints;
        cin >> costToChange;
        int lengthOfDay = checkpoints + 1;
        int amountOfWieAuchImmerManDasNennt = days * lengthOfDay;
        vector<int> cars;
        vector<int> motorBikes;
        cars.resize(amountOfWieAuchImmerManDasNennt);
        motorBikes.resize(amountOfWieAuchImmerManDasNennt);
        for(int i= 0; i < amountOfWieAuchImmerManDasNennt;i++){
            cin >> cars[i];
        }
        for(int i= 0; i < amountOfWieAuchImmerManDasNennt;i++){
            cin >> motorBikes[i];
        }
        cout << "Case #" << testCase + 1 << ": " << calculate(cars, motorBikes, lengthOfDay, costToChange) << endl;


    }
    */

    vector<int> cars       {1,1,   20,20};
    vector<int> motorBikes {20,20,  1,1};
    cout << calculate(cars,motorBikes,2,100);
    return 0;
}