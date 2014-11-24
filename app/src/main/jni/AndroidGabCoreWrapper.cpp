#include "AndroidGabCoreWrapper.h"

#include "./Core/GabCore.h"
#include "./Core/GabContact.h"
#include "AndroidLog.h"
#include <unistd.h>
#include <stdlib.h>

GabCore& AndroidGabCoreWrapper::getInstance()
{
   static GabCore instance;
   return instance;
}

int AndroidGabCoreWrapper::GetNumberOfContacts()
{
    return getInstance().GetNumberOfContacts();
}

std::string AndroidGabCoreWrapper::AddContact(const std::string& theContactName)
{
    return getInstance().AddContact( GabContact(theContactName) ).GetContact().GetName();
}

void AndroidGabCoreWrapper::startWaitingContacts()
{
    while( true )
    {
        getInstance().AddRandContact();
    }
}