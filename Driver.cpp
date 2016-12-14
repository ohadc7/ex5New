#include "Driver.h"



Driver::Driver(int id, int age, Status_Of_Marriage status, int yearsOfExperience, Cab *cab) :
        id(id), age(age), status(status), yearsOfExperience(yearsOfExperience), cabOfDriver(cab){
    numOfTrips =1;
    averageSatisfactions = 0;
}

int Driver::getId() const {
    return id;
}

int Driver::getAge() const {
    return age;
}

Status_Of_Marriage Driver::getStatus() const {
    return status;
}

int Driver::getYearsOfExperience() const {
    return yearsOfExperience;
}

double Driver::getSatisfactions() const {
    return averageSatisfactions;
}

Cab* Driver::getInfoCab() const{
    return cabOfDriver;
}

Point Driver::currentPlace() {
    return currentLocation;
}

void Driver::clientSatisfactions(int clientSatisfactions){
    if((numOfTrips==0) || (numOfTrips ==1)){
        averageSatisfactions = clientSatisfactions;
    }else{
        averageSatisfactions = (averageSatisfactions+clientSatisfactions)/numOfTrips;
    }
    if(averageSatisfactions>5){
        averageSatisfactions=5;
    }else if(averageSatisfactions<1){
        averageSatisfactions =1;
    }
    numOfTrips++;
}

bool Driver::isAvailable() {
    return true;
}

vector<Passenger> Driver::getListOfPassengers() const{
    return listOfPassengers;
}

void Driver::addPassenger(Passenger passenger) {
    listOfPassengers.push_back(passenger);
}

void Driver::setCurrentLocation(Point pointNewLocation) {
    currentLocation = pointNewLocation;
}

