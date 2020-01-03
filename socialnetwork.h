#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H

#include "user.h"


class SocialNetwork
{
public:
    bool addUser(const string& name, const string& eMail, int age);
    void addUser(const User& other);
    bool deleteUser(const string& name);
    bool link(const string& name1, const string& name2, const string& type);
    bool find(const string& name) const;
    bool ban(const string& name1,const string& name2);
    void delink(const string& name1,const string& name2);
    void recommend(const string& name) const; 
    vector<User> getUsers () const;

private:
    vector<User> users;
    void mostFriendly (const string &name) const;

};

#endif // SOCIALNETWORK_H
