#ifndef GAB_CORE_H
#define GAB_CORE_H

#include "GabCoreDef.h"
#include "GabContact.h"
#include "GabAsyncResponse.h"
#include "GabGui.h"

#include <list>
using namespace std;

class GabCore
{
public:
    GAB_CORE_EXPORT GabCore();

    GAB_CORE_EXPORT int GetNumberOfContacts() const;
    GAB_CORE_EXPORT GabAsyncResponse AddContact(const GabContact& theContact);
    GAB_CORE_EXPORT GabAsyncResponse AddRandContact();


private:
    GabGui* getGui();
    GabCore(const GabCore& theOther);
    GabCore& operator=(const GabCore& theOther);


private:
    std::list<GabContact> myList;
};

#endif