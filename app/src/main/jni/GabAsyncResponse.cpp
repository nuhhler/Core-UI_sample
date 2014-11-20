#include "GabAsyncResponse.h"

GabAsyncResponse::GabAsyncResponse(const GabContact& theContact)
{
    myContact = theContact;
}

GabAsyncResponse::GabAsyncResponse(const GabAsyncResponse& theOther)
{
    *this = theOther;
}

GabAsyncResponse& GabAsyncResponse::operator=(const GabAsyncResponse& theOther)
{
    myContact = theOther.myContact;
    return *this;
}

const GabContact& GabAsyncResponse::GetContact() const
{
    return myContact;
}