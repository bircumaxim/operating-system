#ifndef __OPERATING_SYSTEM__DRIVERS__DRIVER_MANAGER__H
#define __OPERATING_SYSTEM__DRIVERS__DRIVER_MANAGER__H

#include <drivers/driver.h>

class DriverManager{
    private:
	Driver* drivers[265];
	int numDrivers;
	
    public:
	DriverManager();
	~DriverManager();
	void addDriver(Driver*);
	void activateAllDivers();
};

#endif