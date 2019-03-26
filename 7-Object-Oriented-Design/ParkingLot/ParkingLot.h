#include <string>
#include <set>

using std::string;
using std::set;

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

class ParkingLot {

};

class MultiLevelParking {
};

} // ParkingLot namespace ends


