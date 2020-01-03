#include "user.h"
#include "string.h"
#include <iostream>

User::User(){}

User::User(const string& name, const string& eMail, int age)
{
    this->name = name;
    this->age = age;
    this->eMail = eMail;
}

bool User::addFriend(const string& nameOfFriend, const string &typeOfFriendship)
{
    if (findBlockedUser(nameOfFriend))
        return false;
    if(typeOfFriendship == "bestie")
    {
        bestie.push_back(nameOfFriend);
    }
    else if (typeOfFriendship == "relative")
    {
        relative.push_back(nameOfFriend);
    }
    else if (typeOfFriendship == "normal")
    {
        normal.push_back(nameOfFriend);
    }
    return false;

}

bool User::findBlockedUser (const string& name) const
{
    for (vector<string>::const_iterator i = blocked.begin(); i != blocked.end(); i++)
    {
        if (*i == name )
            return true;
    }
    return false;
}

void User::blockUser (const string &name)
{
    blocked.push_back(name);
    for(vector<string>::iterator i = normal.begin(); i != normal.end(); i++)
    {
        if (*i == name)
        {
            normal.erase(i);
            return;
        }
    }
    for(vector<string>::iterator i = relative.begin(); i != relative.end(); i++)
    {
        if (*i == name)
        {
            normal.erase(i);
            return;
        }
    }
    for(vector<string>::iterator i = bestie.begin(); i != bestie.end(); i++)
    {
        if (*i == name)
        {
            normal.erase(i);
            return;
        }
    }

}

string User::getName() const
{
    return name;
}
string User::getEmail() const
{
    return eMail;
}
int User::countFriends() const
{
    return (bestie.size() + relative.size() + normal.size());
}

bool User::unblock (const string& name)
{
    for(vector<string>::iterator i = blocked.begin(); i != blocked.end(); i++)
    {
        if (*i == name)
        {
            blocked.erase(i);
            return true;
        }
    }
    return false;
}

bool User::unfriend(const string& name)
{
    for(vector<string>::iterator i = normal.begin(); i != normal.end(); i++)
    {
        if (*i == name)
        {
            normal.erase(i);
            return true;
        }
    }
    for(vector<string>::iterator i = relative.begin(); i != relative.end(); i++)
    {
        if (*i == name)
        {
            normal.erase(i);
            return true;
        }
    }
    for(vector<string>::iterator i = bestie.begin(); i != bestie.end(); i++)
    {
        if (*i == name)
        {
            normal.erase(i);
            return true;
        }
    }
    return false;
}
int User::getAge() const
{
    return age;
}
void User::printFriends () const
{
    for(vector<string>::const_iterator i = normal.begin(); i != normal.end(); i++)
        std::cout << *i << " " ;
    for(vector<string>::const_iterator i = relative.begin(); i != relative.end(); i++)
        std::cout << *i << " " ;
    for(vector<string>::const_iterator i = bestie.begin(); i != bestie.end(); i++)
        std::cout << *i << " " ;
    std::cout << std::endl;
}
vector<string> User::getBestie() const
{
    return bestie;
}
vector<string> User::getRelative() const
{
    return relative;
}
vector<string> User::getNormal() const
{
    return normal;
}
