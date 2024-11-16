#include <iostream>
#include <string.h>
#include "Profile.h"

void Profile::init(User owner)
{
	this->user = owner;
	this->page.init();
	this->friendList.init();
}

void Profile::clear()
{
	this->friendList.clear();
	this->page.claerPage();
	this->user.clear();
}

User Profile::getOwner() const
{
	return this->user;
}

void Profile::setStatus(std::string new_status)
{
	this->page.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	this->page.addLineToPosts("\n" + post);
}

void Profile::addFriend(User friend_to_add)
{
	this->friendList.add(friend_to_add);
}

std::string Profile::getPage() const
{
	return "Status" + this->page.getStatus() + "\n*******************\n*******************\n" + this->page.getPosts();
}

std::string Profile::getFriends() const
{
	std::string friendList = "";
	UserNode* firstFriend = this->friendList.get_first();
	if (firstFriend->get_data().getUserName() == "")
	{
		return;
	}

	while (firstFriend->get_next())
	{
		friendList = friendList + "," + firstFriend->get_data().getUserName();
		firstFriend = firstFriend->get_next();
	}

	friendList = friendList + "," + firstFriend->get_data().getUserName();
	return friendList;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	std::string sameLengthFriendList = "";
	UserNode* firstFriend = this->friendList.get_first();
	if (firstFriend->get_data().getUserName == "")
	{
		return;
	}

	while (firstFriend->get_next())
	{
		if (firstFriend->get_data().getUserName().length() == this->user.getUserName().length())
		{
			sameLengthFriendList = sameLengthFriendList + "," + firstFriend->get_data().getUserName();
		}
		firstFriend = firstFriend->get_next();
	}

	if (firstFriend->get_data().getUserName().length() == this->user.getUserName().length())
	{
		sameLengthFriendList = sameLengthFriendList + "," + firstFriend->get_data().getUserName();
	}
	return sameLengthFriendList;
}