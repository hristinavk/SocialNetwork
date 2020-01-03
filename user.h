#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User
{
public:
    User();
    User(const string &name, const string &eMail, int age);
    bool addFriend(const string &nameOfFriend, const string& typeOfFriendship = "normal");
    bool findBlockedUser (const string& name) const;
    void blockUser(const string& name);
    int countFriends() const;
    bool unfriend (const string& name);
    bool unblock (const string& name);
    string getName() const;
    string getEmail() const;
    int getAge() const;
    vector<string> getBestie() const;
    vector<string> getRelative() const;
    vector<string> getNormal() const;
    void printFriends () const;



private:
    string name;
    string eMail;
    int age;
    vector<string> bestie;
    vector<string> relative;
    vector<string> normal;
    vector<string> blocked;

};

#endif // USER_H
