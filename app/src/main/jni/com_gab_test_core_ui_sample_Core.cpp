#include "com_gab_test_core_ui_sample_Core.h"

#include "AndroidGabCoreWrapper.h"
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
