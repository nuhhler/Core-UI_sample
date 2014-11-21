#pragma once

#include <jni.h>
#include "./Core/GabGui.h"


class AndroidGui: public GabGui
{
public:
    virtual void AddContact( const GabAsyncResponse& );

    static JavaVM* JVM;
    static jclass JCLASS;
    static jmethodID MID_ADD_CONTACT;

private:
    static JNIEnv* getJniEnv();
};