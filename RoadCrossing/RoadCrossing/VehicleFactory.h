#pragma once
#include "Vehicle.h"

class VehicleFactory
{
public:
	Vehicle* getVehicle(VehicleType vehicleType);
};

