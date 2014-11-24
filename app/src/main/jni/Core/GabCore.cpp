#include "GabCore.h"
#include "GabGui.h"
#include "../AndroidGui.h"
#include "../AndroidLog.h"
#include <stdlib.h>



#ifdef _WIN32
#include <windows.h>
#elif defined (__ANDROID__) || defined(__linux__) 
#include <unistd.h>
#endif

GabCore::GabCore()
{
}

GabGui* GabCore::getGui()
{
    GabGui* result = NULL;
#ifdef _WIN32
    result = NULL;
#elif defined (__ANDROID__)
    result = new AndroidGui();
#elif defined (__linux__)
    result = NULL;
#endif
    return result;
}

int GabCore::GetNumberOfContacts() const
{
    return myList.size();
}

GabAsyncResponse GabCore::AddContact(const GabContact& theContact)
{
#ifdef _WIN32
    Sleep(1000);
#elif defined (__ANDROID__) || defined (__linux__)
    sleep(5);
#endif
    myList.push_back(theContact);
    return GabAsyncResponse(theContact);
}

GabAsyncResponse GabCore::AddRandContact()
{

#ifdef _WIN32
    Sleep(5000);
#elif defined (__ANDROID__) || defined (__linux__)
    sleep(15);
#endif
    GabContact aGabContact("Random_" + myList.size() );
    myList.push_back(aGabContact);

    GabAsyncResponse result(aGabContact);
    GabGui* gui = getGui();
    if( gui != NULL )
    {
        gui->AddContact(result);
    }

    return GabAsyncResponse(result);
}