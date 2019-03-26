#include <string>
#include <set>
#include <vector>

using std::string;
using std::set;
using std::vector;

namespace ParkingLot {

enum VehicleSize {
  small   = 1,
  compact = 2,
  large   = 3,
};

class ParkingSpot; // forward declaration

// Different type of vehicles which can be parked
class Vehicle {

 protected:
  set<ParkingSpot * > parkingSpots;
  VehicleSize size;
  string license_plate;
  int spotsNeeded;

  void parkInSpot() {}
  void clearSpot() {}
};

class Bike : public Vehicle {
  Bike( string license_plate ) {
    license_plate = license_plate;
    size = VehicleSize::small;
    spotsNeeded = 1;
  }
};

class Car : public Vehicle {
 public:
  Car( string license_plate ) {
    license_plate = license_plate;
    size = VehicleSize::compact;
    spotsNeeded = 1;
  }
};

class Bus : public Vehicle {
  Bus( string license_plate ) {
    license_plate = license_plate;
    size = VehicleSize::large;
    spotsNeeded = 5;
  }
};


/*
  Parking Lot related classes
*/
class ParkingSpot {
 public:
  ParkingSpot( int level_, VehicleSize size_, int row_, int spotNumber_ ) {
    level = level_;
    size = size_;
    row = row_;
    spotNumber = spotNumber_;
    vehicle = NULL;
  }

  bool isAvailable() {
    return vehicle == NULL;
  }

  void removeVehicle() {
    vehicle = NULL;
  }

  void park( Vehicle *v ) {
    vehicle = v;
  }

 private:
  Vehicle *vehicle;     // vehicle currently parked
  VehicleSize size;      // max size of vehicle it can hold
  /* location of spot in Multi-level parking lot */
  int row;
  int spotNumber;
  int level;
};

// Represents a level in a multi-level parking lot
class ParkingLot {
 public:
  ParkingLot( int floorNo, int noOfSpots ) {
    floor = floorNo;
    availableSpots_ = noOfSpots;
  }
  
  int availableSpots() {
    return availableSpots_;
  }
  
  bool parkVehicle( Vehicle *v ) {
    // find a spot and update spot amd vehicle
    // decrement available spots
    return false;
  }

 private:
  int floor;
  int availableSpots_;
  vector< ParkingSpot * > spots;

  bool partAtSpot( Vehicle *v, int spotNo ) {
    // try to park vechicle starting at spotNo and park till spotNo + v.spotsNeeded.
    // used by parkVehicle method
    return false;
  }

  int findAvailableSpot() {
    // return a sport no to park at, return -1 if no spot is available
    return -1;
  }
};

class MultiLevelParking {
  MultiLevelParking( int levels ) {
    noOfLevels = levels;
    // TODO
    // Initialize parking lot for each level
  }
  
  bool parkVehicle( Vehicle *v ) {
    // park vehicle in best possible way,
    // start from level 1, if no spot available then try to park on next level
    return false;
  }

 private:
  int noOfLevels;
  vector< ParkingLot * > parkingLot; // each level in a multi-level parking lot
};

} // ParkingLot namespace ends
