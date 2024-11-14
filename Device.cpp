#include <iostream>
#include "Device.h"
#include <string.h>

/*
this function initialize the variable of the class
input: the id, the type, the os
output: none
*/
void Device::init(unsigned int id, DeviceType type, std::string os)
{
	this->id = id;
	this->type = type;
	this->OS = os;
	this->is_active = true;
}

/*
This function returns the id
input: none
output: the id
*/
unsigned int Device::getID() const
{
	return this->id;
}

/*
This function returns the type
input: none
output: the type
*/
DeviceType Device::getType() const
{
	return this->type;
}

/*
This function returns the os
input: none
output: the os
*/
std::string Device::getOS() const
{
	return this->OS;
}

/*
This function checks if the device is active
input: none
output: if the device is active
*/
bool Device::isActive() const
{
	return this->is_active;
}

/*
This function actives the device
input: none
output: none
*/
void Device::activate()
{
	this->is_active = true;
}

/*
This function deactives the device
input: none
output: none
*/
void Device::deactivate()
{
	this->is_active = false;
}