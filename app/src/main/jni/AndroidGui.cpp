#include "AndroidGui.h"
#include "./Core/GabAsyncResponse.h"
#include "AndroidLog.h"

JavaVM* AndroidGui::JVM = NULL;
jclass AndroidGui::JCLASS = NULL;
jmethodID AndroidGui::MID_ADD_CONTACT = NULL;

void AndroidGui::AddContact( const GabAsyncResponse& theResponse )
{
    ANDROID_LOG_INFO( "run AndroidGui::AddContact" );
    JNIEnv* pEnv = getJniEnv();
    if( pEnv != NULL )
    {
        getJniEnv()->CallStaticVoidMethod(JCLASS, MID_ADD_CONTACT, pEnv->NewStringUTF("hello"));
    }
}

JNIEnv* AndroidGui::getJniEnv()
{
    JavaVMAttachArgs attachArgs;
	attachArgs.version = JNI_VERSION_1_6;
	attachArgs.name = ">>>NativeThread__Any";
	attachArgs.group = NULL;

	JNIEnv* pEnv;
	if ( JVM->AttachCurrentThread(&pEnv, &attachArgs) != JNI_OK) {
	    ANDROID_LOG_ERROR( "AndroidGui::getJniEnv: can't get JNIEnv" );
		pEnv = NULL;
	}

	return pEnv;
}