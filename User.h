#pragma once
#include <iostream>	
#include <string.h>
#include "DeviceList.h"

class User
{
public:
	//methods
	void init(unsigned int id, std::string username, unsigned int age);
	void clear();
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices();
	void addDevice(Device newDevice);
	bool checkIfDevicesAreOn() const;

private:
	//fields
	int id;
	std::string userName;
	int age;
	DevicesList list;
};

