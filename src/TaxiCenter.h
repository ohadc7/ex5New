#ifndef EX1_VERSION_1_1_TAXICENTER_H
#define EX1_VERSION_1_1_TAXICENTER_H

#include "Driver.h"
#include "Trip.h"
#include "Passenger.h"
#include "BfsAlgorithm.h"
#include "InputParsing.h"

/*
 * This class is responsible for communication with all the drivers, cabs and trips.
 * It should make them work in coordination and cooperation.
 */
class TaxiCenter {
private:
    vector<Driver> listOfDrivers;
    vector<Driver> listOfAvialbeDrivers;
    vector<Trip *> listOfTrips;
    vector<Cab *> listOfCabs;
    BfsAlgorithm<Point> bfsInstance;
public:
    //constructor
    TaxiCenter(BfsAlgorithm<Point> &bfsInstance);

    //add driver to the taxi center
    void addDriver(Driver driver);

    //add cab to the taxi center
    void addCab(Cab *cab);

    // allocate the trips that were received in the system to the appropriate drivers
    // and command each of them to drive to the end point of its trip
    void startDriving();

    //get list of the drivers
    const vector<Driver> &getListOfDrivers() const;

    //get list of the trips
    const vector<Trip *> &getListOfTrips() const;

    //return the current location of a specific driver (according to its id number)
    //(if no such driver in the system, throw "no driver found")
    Point getDriverLocation(int driverId);

    //add a trip to the taxi center
    void addTrip(Trip *trip);

    //create a trip (according to the parameters that are given in the 'parsed trip data' struct)
    //and add the trip to the taxi center
    void createTrip(InputParsing::parsedTripData);

    //get cab that is belonging to the taxi center (according to the cab id).
    //(if no such cab in the system, throw "no cab found")
    Cab *getCab(int id);

    //destructor
    ~TaxiCenter();
};


#endif