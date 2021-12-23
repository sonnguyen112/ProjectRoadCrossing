#include "VehicleFactory.h"

Vehicle* VehicleFactory::getVehicle(VehicleType vehicleType) {
	if (vehicleType == CAR) return new Car();
	if (vehicleType == TRUCK) return new Truck();
	return nullptr;
}