#include "Trip.h"

Trip::Trip(int rideId, Point startingPoint, Point endingPoint, int numOfPassengers, double taarif)
        : rideId(rideId), startingPoint(startingPoint), endingPoint(endingPoint),
          numOfPassengers(numOfPassengers) {
    rateOfTrip = taarif;
    passedMeters = 0;
}

int Trip::getRideId() const {
    return rideId;
}

const Point &Trip::getStartingPoint() const {
    return startingPoint;
}

const Point &Trip::getEndingPoint() const {
    return endingPoint;
}

const list <Passenger> &Trip::getCustomers() const {
    return customers;
}

int Trip::getNumberOfPassengers() const {
    return (int) customers.size();
}

double Trip::getRateOfTrip() const {
    return rateOfTrip;
}

int Trip::getPassedMeters() const {
    return passedMeters;
}

Trip::~Trip() {
}


