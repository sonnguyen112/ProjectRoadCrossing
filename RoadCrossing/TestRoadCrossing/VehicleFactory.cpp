#include "VehicleFactory.h"

Vehicle * VehicleFactory::getVehicle(VehicleType vehicleType, float posX, float posY)
{
	if (vehicleType == VehicleType::CAR) {
		return new Car(posX, posY);
	}
	else if (vehicleType == VehicleType::TRUCK) {
		return new Truck(posX, posY);
	}
}
