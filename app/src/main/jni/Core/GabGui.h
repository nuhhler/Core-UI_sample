#pragma once

class GabAsyncResponse;

class GabGui
{
public:
    virtual void AddContact( const GabAsyncResponse& ) = 0;
};