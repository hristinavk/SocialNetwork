#include "socialnetwork.h"
#include <iostream>
#include <list>

bool SocialNetwork::addUser(const string& name, const string& eMail, int age)
{
    for (vector<User>::const_iterator i = users.begin(); i != users.end(); i++)
    {
        if (i->getName() == name)
            return false;
    }
    User temp(name,eMail,age);
    users.push_back(temp);
    return true;
}

void SocialNetwork::addUser(const User& other)
{
    users.push_back(other);
}

bool SocialNetwork::deleteUser(const string& email)
{
    for (vector<User>::iterator i = users.begin(); i != users.end(); i++)
    {
        if (i->getEmail() == email )
        {
            users.erase(i);
            return true;
        }
    }
    return false;
}

bool SocialNetwork::link(const string& name1, const string& name2, const string& type )
{
    bool user1 = false, user2 = false;
    for (vector<User>::iterator i = users.begin(); i != users.end(); i++)
    {
        if (i->getName() == name1)
        {
          i->addFriend(name2, type);
          user1 = true;
        }

        else if  (i->getName() == name2)
        {
            i->addFriend(name1, type);
            user2 = true;
        }
    }
    if (user1 && user2)
        return true;
    return false;
}

bool SocialNetwork::find(const string& name) const
{
    for (vector<User>::const_iterator i = users.begin(); i != users.end(); i++)
    {
        if (i->getName() == name)
        {
            std::cout << "User: Name " << name << std::endl
                      << "Age: "<< i->getAge() <<  std::endl;
            i->printFriends();
            return true;
        }
    }
    return false;
}
bool SocialNetwork::ban (const string& name1,const string& name2)
{
    for (vector<User>::iterator i = users.begin(); i != users.end(); i++)
    {
        if (i->getName() == name1)
        {
            i->blockUser(name2);
            return true;
        }
    }
    return false;
}

void SocialNetwork::delink(const string& name1, const string& name2)
{
    for(vector<User>::iterator i = users.begin(); i != users.end(); i++)
    {
        if (i->getName() == name1)
            i->unfriend(name2);

        else if (i->getName() == name2)
            i->unfriend(name1);

    }
}

 vector<User> SocialNetwork::getUsers () const
 {
     return users;
 }

void SocialNetwork::mostFriendly (const string& name) const
{
    vector<User> temp(users);
    list<User> l;

    int cnt = 0;
    for (vector<User>::iterator i = temp.begin(); i != temp.end(); i++)
    {
        if(i->getName() != name)
       {
           l.push_back(*i);

       }
    }
        bool swapped = true;
        list<User>::iterator start = l.begin();
        list<User>::iterator j;
        list<User>::iterator end = l.end();
        while(start != end )
        {
            j = start;
            start++;
        }
        end = j;
        while (swapped)
        {
            swapped = false;

            for (list<User>::iterator i = start, j = start; i != end; i++)
            {
                j = i;
                j++;
                if (i->countFriends() <  j->countFriends())
                {
                    swap(*i, *j);
                    swapped = true;
                }
            }


            if (!swapped)
                break;

            swapped = false;

            --end;

            for (list<User>::iterator i = end,j = end ; j != start; --i)
            {
                j = i;
                j--;
                if (i->countFriends() > j->countFriends())
                {
                    swap(*i,*j);
                    swapped = true;
                }
            }

            ++start;
        }

        for (list<User>::iterator i = l.begin(); i != l.end() && cnt < 30; cnt++ ,i++)
        {
            std::cout << i->getName() << " ";
        }
 }




void SocialNetwork::recommend(const string& name) const
{
    int cnt = 0,bst = 0;
    for (vector<User>::const_iterator i = users.begin(); i != users.end(); i++)
    {
        if (i->getName() == name)
        {
            if(i->getBestie().empty() && i->getNormal().empty() && i->getRelative().empty())
                mostFriendly(name);

            if(!i->getBestie().empty())
            {
                for (vector<string>::const_iterator j = i->getBestie().begin();
                     bst < 30 && cnt < 30 && j != i->getBestie().end();bst++, cnt++, j++)
                    std::cout << i->getBestie()[bst] << " ";
            }
            bst = 0;
            if(!i->getRelative().empty() && cnt < 30)
            {
                for (vector<string>::const_iterator j = i->getRelative().begin();
                     bst < 30 && cnt < 30 && j != i->getRelative().end();bst++,cnt++, j++)
                    std::cout << i->getRelative()[bst] << " ";
            }
            bst = 0;
            if (!i->getNormal().empty() && cnt < 30)
            {
                for (vector<string>::const_iterator j = i->getNormal().begin();
                     bst < 30 && cnt < 30 && j != i->getNormal().end();bst++,cnt++, j++)
                    std::cout << i->getNormal()[bst] << " ";
            }
            std::cout << std::endl;



            return;
        }
    }
}
