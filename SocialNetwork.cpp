#include <iostream>
#include "SocialNetwork.h"
#include <string.h>

void SocialNetwork::init(std::string networkName, int minAge)
{
	this->minAge = minAge;
	this->networkName = networkName;
	this->ProfileList.init();
}

void SocialNetwork::clear()
{
	this->minAge = NULL;
	this->networkName = "";
	this->ProfileList.clear();
}

std::string SocialNetwork::getNetworkName() const
{
	return this->networkName;
}

int SocialNetwork::getMinAge() const
{
	return this->minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (this->minAge > profile_to_add.getOwner()->getAge())
	{
		return false;
	}

	this->ProfileList.add(profile_to_add);
	return true;
}

std::string SocialNetwork::getWindowsDevices() const
{
	std::string windowsList = "";
	ProfileNode* firstProfile = this->ProfileList.get_first();
	DeviceNode* firstDevice = firstProfile->get_data().getOwner()->getDevices().get_first();
	if (firstProfile->get_data().getOwner()->getDevices().get_first()->get_data().getOS() == "")
	{
		return;
	}

	while (firstProfile->get_next())
	{
		while (firstDevice->get_next())
		{
			if (firstDevice->get_data().isActive())
			{
				windowsList = windowsList + "[" + std::to_string(firstDevice->get_data().getID()) + ", " + firstDevice->get_data().getOS() + "], ";
			}
			firstDevice = firstDevice->get_next();
		}

		firstProfile = firstProfile->get_next();
		firstDevice = firstProfile->get_data().getOwner()->getDevices().get_first();
	}

	while (firstDevice->get_next())
	{
		if (firstDevice->get_data().isActive())
		{
			windowsList = windowsList + "[" + std::to_string(firstDevice->get_data().getID()) + ", " + firstDevice->get_data().getOS() + "], ";
		}
		firstDevice = firstDevice->get_next();
	}

	return windowsList;
}