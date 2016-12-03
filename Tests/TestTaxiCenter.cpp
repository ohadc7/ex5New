#include "gtest/gtest.h"
#include "../TaxiCenter.h"
#include "../StandardCab.h"

class TestTaxiCenter: public ::testing::Test {

protected:
    Grid* grid = new Grid(10,10);
    BfsAlgorithm<Point> bfs = BfsAlgorithm<Point>(grid);
    TaxiCenter taxiCenter = TaxiCenter(bfs);
    Point reuvenSourcePoint = Point(2,2);
    Point reuvenDestinationPoint = Point(1,0);
    Passenger reuven = Passenger(reuvenSourcePoint, reuvenDestinationPoint, false);
    Driver driver1  = Driver(555555555, 80, WIDOWED, 50);
    Driver driver2 = Driver(121212121, 40, MARRIED, 3);
    StandardCab* cabForDriver1;
    StandardCab* cabForDriver2;

    virtual void SetUp() {
        cabForDriver1 = new StandardCab(1122233, HONDA, BLUE);
        cabForDriver2 = new StandardCab(4455566, FIAT, WHITE);
    }

    virtual void TearDown() {
        delete cabForDriver1;
        delete cabForDriver2;
    }

};

TEST_F(TestTaxiCenter, SanityChecks) {
    //check that no drivers and no trips when taxiCenter is initialized
    ASSERT_EQ(taxiCenter.getListOfDrivers().empty(), true);
    ASSERT_EQ(taxiCenter.getListOfTrips().empty(), true);
    //check addDriver(Driver) method and getListOfDrivers() method
    taxiCenter.addDriver(driver1);
    list<Driver> driversList = taxiCenter.getListOfDrivers();
    ASSERT_EQ(driversList.size(), 1);
    Driver taxiCenterDriver = driversList.front();
    ASSERT_EQ(taxiCenterDriver.getId(), 555555555);

    //check orderATrip, chooseBestDriver, createTrip, sendTaxi methods
    //("orderATrip" is checked explicitly and the other 3 methods are checked implicitly)
    taxiCenter.orderATrip(reuven);
    list<Trip> taxiCenterListOfTrip = taxiCenter.getListOfTrips();
    ASSERT_EQ(taxiCenterListOfTrip.size(), 1);
    Trip taxiCenterTrip = taxiCenterListOfTrip.front();
    ASSERT_EQ(taxiCenterTrip.getNumberOfPassengers(), 1);
    ASSERT_EQ(taxiCenterTrip.getStartingPoint(), reuvenSourcePoint);
    ASSERT_EQ(taxiCenterTrip.getEndingPoint(), reuvenDestinationPoint);

    taxiCenter.addDriver(driver2);
    Point driver1Position = driver2.currentPlace();
    Point driver1PositionAccordingToTaxiCenter = taxiCenter.getDriverLocation(driver2);
    ASSERT_EQ(driver1PositionAccordingToTaxiCenter, driver1Position);

    /*
     * comment: currently, I don't check the ability of chooseBestDriver method to find
     * the closet driver because the initial position of created driver isn't defined in
     * ex1 and we don't have methods that will make 2 drivers to be in 2 different positions.
    */
}
