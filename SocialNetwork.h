#pragma once
#include "ProfileList.h"

class SocialNetwork
{
public:
	//methods
	void init(std::string networkName, int minAge);
	void clear();
	std::string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices() const;

private:
	//fields
	int minAge;
	std::string networkName;
	ProfileList ProfileList;
};