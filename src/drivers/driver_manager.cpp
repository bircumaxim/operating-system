#include <drivers/driver_manager.h>

DriverManager::DriverManager(){
    
}

DriverManager::~DriverManager(){
    
}

void DriverManager::addDriver(Driver* drv){
    drivers[numDrivers] = drv;
    numDrivers++;
}


void DriverManager::activateAllDivers(){
    for(int i = 0; i < numDrivers; i++){
	drivers[i]->activate();
    }
}