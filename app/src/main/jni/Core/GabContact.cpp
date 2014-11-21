#include "GabContact.h"

GabContact::GabContact()
{
    myName = "";
}

GabContact::GabContact(const std::string& theName)
{
    myName = theName;
}

GabContact::GabContact(const GabContact& theOther)
{
    *this = theOther;
}

GabContact& GabContact::operator=(const GabContact& theOther)
{
    myName = theOther.myName;
    return *this;
}

const std::string& GabContact::GetName() const
{
    return myName;
}