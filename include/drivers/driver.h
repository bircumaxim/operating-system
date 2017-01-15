#ifndef __OPERATING_SYSTEM__DRIVERS__DRIVER__H
#define __OPERATING_SYSTEM__DRIVERS__DRIVER__H

class Driver{
    public:
	Driver();
	~Driver();
	virtual void activate();
	virtual int reset();
	virtual void deactivate();
};

#endif