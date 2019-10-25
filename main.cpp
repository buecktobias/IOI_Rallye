#include <iostream>
#include <vector>


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


int calculateDayFor(const vector<int>& cars, const vector<int>& motorBikes, const int& changeCost, Vehicle v){
    int cars_sum = sum(cars); // TODO could be improved by only calculating the sum ones for both vehicles!
    int bikes_sum = sum(motorBikes);
    int result = 0;
    for (unsigned long i = 0; i < cars.size(); i++) {
        const int car = cars[i];
        const int motorBike = motorBikes[i];


        int othersSum;
        int currentSum;
        vector<int> current;
        vector<int> other;
        if (v == Vehicle(Car)) {
            // car
            current = cars;
            other = motorBikes;
            currentSum = cars_sum;
            othersSum = bikes_sum;
        } else {
            // motor bike
            current = motorBikes;
            other = cars;
            currentSum = bikes_sum;
            othersSum = cars_sum;
        }

        if (othersSum + changeCost < currentSum) {
            // it is only one change possible so after you changed you can break the for loop
            // and add all the remaining costs
            result += changeCost; // the costs to change has to be added
            result += othersSum;
            break;
        }

        if(v == Vehicle(Car)){
            result += car;
        }else{
            result += motorBike;
        }

        cars_sum -= car;
        bikes_sum -= motorBike;
    }
    return result;

}

int calculateDay(const vector<int>& cars, const vector<int>& motorBikes, const int& changeCost) {
    int smallestResult = INT32_MAX;
    for (Vehicle startVehicle: {Vehicle(Car), Vehicle(MotorBike)}) {
        int result = calculateDayFor(cars, motorBikes, changeCost, startVehicle);
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
    // Input
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

    return 0;
}