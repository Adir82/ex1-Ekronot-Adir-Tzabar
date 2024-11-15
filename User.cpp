#include <iostream>
#include "User.h"
#include <string>

/*
this function initialize the variable of the class
input: the id, the username, the age
output: none
*/
void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->id = id;
	this->userName = username;
	this->age = age;
	this->list.init();
}

/*
this function clears the variable of the class
input: none
output: none
*/
void User::clear()
{
	this->id = NULL;
	this->userName = "";
	this->age = NULL;
	this->list.clear();
}

/*
This function returns the id
input:none
output: the id
*/
unsigned int User::getID() const
{
	return this->id;
}

/*
This function returns the user name
input:none
output: the user name
*/
std::string User::getUserName() const
{
	return this->userName;
}

/*
This function returns the age
input:none
output: the age
*/
unsigned int User::getAge() const
{
	return this->age;
}

/*
This function returns the refrence to the Devices
input:none
output: the refrence to the Devices
*/
DevicesList& User::getDevices()
{
	DevicesList& new_list= this->list;
	return new_list;
}

/*
This function adds a new Device to the Devices
input: a Device
output: none
*/
void User::addDevice(Device newDevice)
{
	this->list.add(newDevice);
}

/*
This function checks if all the Devices are active
input: none
output: none
*/
bool User::checkIfDevicesAreOn() const
{
	DeviceNode* head = this->list.get_first();

	while(head->get_next())
	{
		if (head->get_data().isActive() == false)
		{
			return false;
		}
	}
	
	return true;
}