#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

enum VehicleType {CAR, TRUCK};

class VehicleFactory
{
public:
	Vehicle* getVehicle(VehicleType vehicleType);
};

