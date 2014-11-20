#include "com_gab_test_core_ui_sample_Core.h"

#include "AndroidGabCoreWrapper.h"
#include "AndroidGui.h"
#include <AndroidLog.h>


/*
 * Class:     com_gab_test_core_ui_sample_Core
 * Method:    GetNumberOfContacts
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_gab_test_core_1ui_1sample_Core_GetNumberOfContacts
  (JNIEnv *, jclass)
{
    ANDROID_LOG_INFO( "run GetNumberOfContacts" );
    return AndroidGabCoreWrapper::GetNumberOfContacts();
}

/*
 * Class:     com_gab_test_core_ui_sample_Core
 * Method:    AddContact
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_gab_test_core_1ui_1sample_Core_AddContact
  (JNIEnv * pEnv, jclass, jstring theContactName)
{
    ANDROID_LOG_INFO( "run AddContact" );
    const char* tmpStr =  pEnv->GetStringUTFChars( theContactName, NULL);

    const std::string& res = AndroidGabCoreWrapper::AddContact( std::string( tmpStr ) );

    pEnv->ReleaseStringUTFChars( theContactName, tmpStr);

    return pEnv->NewStringUTF(res.c_str());
}

/*
 * Class:     com_gab_test_core_ui_sample_Core
 * Method:    startWaitingContacts
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_gab_test_core_1ui_1sample_Core_startWaitingContacts
  (JNIEnv *, jclass)
{
    ANDROID_LOG_INFO( "run startWaitingContacts" );
    AndroidGabCoreWrapper::startWaitingContacts();
}

  /*
   * Class:     com_gab_test_core_ui_sample_Core
   * Method:    init
   * Signature: ()V
   */
  JNIEXPORT void JNICALL Java_com_gab_test_core_1ui_1sample_Core_init
    (JNIEnv *pEnv, jclass)
{
    ANDROID_LOG_INFO( "run init" );
    pEnv->GetJavaVM( &AndroidGui::JVM);

    jclass jclassLocalRef = pEnv->FindClass("com/gab/test/core_ui_sample/Core");
    if( jclassLocalRef == NULL )
    {
        ANDROID_LOG_ERROR("init: can't find class 'Core'");
        return;
    }
    AndroidGui::JCLASS = (jclass)pEnv->NewGlobalRef( jclassLocalRef );

    AndroidGui::MID_ADD_CONTACT = pEnv->GetStaticMethodID( AndroidGui::JCLASS, "incomingContact",
                                                                               "(Ljava/lang/String;)V" );
    if( AndroidGui::MID_ADD_CONTACT == NULL )
    {
        ANDROID_LOG_ERROR("init: cant find Core.incomingContact(String)");
        return;
    }
}