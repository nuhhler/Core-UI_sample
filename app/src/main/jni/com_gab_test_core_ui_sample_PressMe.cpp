#include "com_gab_test_core_ui_sample_PressMe.h"

#include "AndroidGui.h"
#include "AndroidGabCoreWrapper.h"
#include <AndroidLog.h>

/*
 * Class:     com_gab_test_core_ui_sample_PressMe
 * Method:    startWaitingContacts
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_gab_test_core_1ui_1sample_PressMe_startWaitingContacts
  (JNIEnv * pEnv, jobject theObject)
{
    ANDROID_LOG_INFO( "run startWaitingContacts" );

    pEnv->GetJavaVM( &AndroidGui::JVM);

    AndroidGui::OBJECT = (jobject)pEnv->NewGlobalRef( theObject );
    jclass jclassLocalRef = pEnv->GetObjectClass( theObject );
    AndroidGui::MID_OnIncomingContact = pEnv->GetMethodID( jclassLocalRef, "OnIncomingContact",
                                                                           "(Ljava/lang/String;)V" );
    if( AndroidGui::MID_OnIncomingContact == NULL )
    {
        ANDROID_LOG_ERROR("init: cant find PressMe.incomingContact(String)");
        return;
    }

    AndroidGabCoreWrapper::startWaitingContacts();
}