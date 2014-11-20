#ifndef _AndroidGabCoreWrapper_
#define _AndroidGabCoreWrapper_

#include <string>
class GabCore;
//class std::string;

class AndroidGabCoreWrapper
{
private:
   static GabCore& getInstance();

public:
   static int GetNumberOfContacts();
   static std::string AddContact(const std::string& theContactName);
   static void startWaitingContacts();
};


#endif