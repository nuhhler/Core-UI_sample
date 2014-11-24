#include "com_gab_test_core_ui_sample_PressMe.h"

#include "AndroidGui.h"
#include "AndroidGabCoreWrapper.h"
#include <AndroidLog.h>

/*
 * Class:     com_gab_test_core_ui_sample_PressMe
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_gab_test_core_1ui_1sample_PressMe_init
  (JNIEnv * pEnv, jclass)
{
    ANDROID_LOG_INFO( "run init" );
    pEnv->GetJavaVM( &AndroidGui::JVM);

    jclass jclassLocalRef = pEnv->FindClass("com/gab/test/core_ui_sample/PressMe");
    if( jclassLocalRef == NULL )
    {
        ANDROID_LOG_ERROR("init: can't find class 'PressMe'");
        return;
    }
    AndroidGui::JCLASS = (jclass)pEnv->NewGlobalRef( jclassLocalRef );

    AndroidGui::MID_OnIncomingContact = pEnv->GetMethodID( AndroidGui::JCLASS, "OnIncomingContact",
                                                                               "(Ljava/lang/String;)V" );
    if( AndroidGui::MID_OnIncomingContact == NULL )
    {
        ANDROID_LOG_ERROR("init: cant find PressMe.incomingContact(String)");
        return;
    }
}

/*
 * Class:     com_gab_test_core_ui_sample_PressMe
 * Method:    startWaitingContacts
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_gab_test_core_1ui_1sample_PressMe_startWaitingContacts
  (JNIEnv * pEnv, jobject theObject)
{
    ANDROID_LOG_INFO( "run startWaitingContacts" );
    AndroidGui::OBJECT = (jobject)pEnv->NewGlobalRef( theObject );
    AndroidGabCoreWrapper::startWaitingContacts();
}