#ifndef GAB_ASYNC_RESPONSE_H
#define GAB_ASYNC_RESPONSE_H

#include "GabCoreDef.h"
#include "GabContact.h"

class GabAsyncResponse
{
public:
    GAB_CORE_EXPORT GabAsyncResponse(const GabContact& theContact);
    GAB_CORE_EXPORT GabAsyncResponse(const GabAsyncResponse& theOther);
    GAB_CORE_EXPORT GabAsyncResponse& operator=(const GabAsyncResponse& theOther);

    GAB_CORE_EXPORT const GabContact& GetContact() const;

private:
    GabContact myContact;
};

#endif