#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
class VehicleFactory
{
public:
	static Vehicle* getVehicle(VehicleType vehicleType, float posX, float posY);
};

