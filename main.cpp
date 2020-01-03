#include <iostream>
#include "user.h"
#include <iostream>
#include "socialnetwork.h"
#include <fstream>

using namespace std;

int main()
{
   bool flag = true;
   string str, str2, str3;
   int age;
   SocialNetwork sc;
   ofstream file("/home/hristina/SDPproekt/sdp.txt");
   if (!file)
   {
       cerr << "Err";
   }

   cout << "Write QUIT to stop the program" << endl;
   while (flag)
   {
       cout << "-----------------" << endl;
       cin >> str;

       if (str == "CREATE")
       {
            cin >> str2 >> str3 >> age;
            if (sc.addUser(str2,str3,age))
            {
                cout << "User " << str2 << " created!" << endl;
                if (file)
                    file << str2 << " " << str3 << " " << age << endl;

            }

            else
                cout << "FAIL: " << str2 << " already exists!" << endl;

       }
       else if (str == "DELETE")
       {
            cin >> str2;
            if (sc.deleteUser(str2))
                cout << "User " << str2 << " has been deleted!" << endl;
            else
                cout << "User " << str2 << " not found!" << endl;
       }
       else if (str == "LINK")
       {
            cin >> str2 >> str3 >> str;
           if (sc.link(str2,str3,str))
               cout << "Users " <<  str2 << " and " << str3 << " are " << str << " now!" << endl;
           else
               cout << "LINK failed!" << endl;

       }
       else if (str == "FIND")
       {
            cin >> str2;
            if (!sc.find(str2))
                cout << "None!" << endl;

       }
       else if (str == "BAN")
       {
            cin >> str2 >> str3;
            if (sc.ban(str2,str3))
                cout << "User " << str3 << " is now banned by " << str2 << endl;
       }
       else if (str == "DELINK")
       {
            cin >> str2 >> str3;
            sc.delink(str2,str3);
       }
       else if (str == "RECOMMEND")
       {
            cin >> str2;
            sc.recommend(str2);
       }
       else if (str == "QUIT")
       {
            flag = false;
       }
   }
file.close();

    return 0;
}

