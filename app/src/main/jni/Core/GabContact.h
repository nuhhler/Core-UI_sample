#ifndef GAB_CONTACT_H
#define GAB_CONTACT_H

#include "GabCoreDef.h"
#include <string>

using namespace std;

class GabContact
{
public:
    GAB_CORE_EXPORT GabContact();
    GAB_CORE_EXPORT GabContact(const std::string& theName);
    GAB_CORE_EXPORT GabContact(const GabContact& theOther);
    GAB_CORE_EXPORT GabContact& operator=(const GabContact& theOther);

    GAB_CORE_EXPORT const std::string& GetName() const;

private:
    std::string myName;
};

#endif