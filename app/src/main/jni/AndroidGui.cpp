#include "AndroidGui.h"
#include "./Core/GabAsyncResponse.h"
#include "./Core/GabContact.h"
#include "AndroidLog.h"

JavaVM* AndroidGui::JVM = NULL;
jclass AndroidGui::JCLASS = NULL;
jmethodID AndroidGui::MID_OnIncomingContact = NULL;
jobject AndroidGui::OBJECT = NULL;

void AndroidGui::AddContact( const GabAsyncResponse& theResponse )
{
    ANDROID_LOG_INFO( "run AndroidGui::AddContact" );
    JNIEnv* pEnv = getJniEnv();
    if( pEnv != NULL )
    {
        const GabContact& aCont = theResponse.GetContact();
        const std::string& stdName = aCont.GetName();
        ANDROID_LOG_INFO( "AndroidGui::AddContact get std name" );
        const char* chName = stdName.c_str();
        ANDROID_LOG_INFO( "AndroidGui::AddContact name: %s", chName );

        jstring jName = pEnv->NewStringUTF( chName );
        ANDROID_LOG_INFO( "run AndroidGui::AddContact name created" );
        getJniEnv()->CallVoidMethod(OBJECT, MID_OnIncomingContact, jName);
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