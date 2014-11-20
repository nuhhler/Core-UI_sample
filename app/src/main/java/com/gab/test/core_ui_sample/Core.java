package com.gab.test.core_ui_sample;

import android.util.Log;

/**
 * Created by sdv on 19.11.14.
 */
public class Core {
    static final String JNI_TAG = "Log From JNI";

    static {
        try {
            System.loadLibrary("core");
            init();
        } catch (UnsatisfiedLinkError ex) {
            Log.e(JNI_TAG, ex.getMessage());
        }
        catch( NoClassDefFoundError ex) {
            // can't find class 'Core'
            Log.e(JNI_TAG, ex.getMessage());
        }
        catch(  NoSuchMethodError ex) {
            // can't find Core.incomingContact(String)
            Log.e(JNI_TAG, ex.getMessage());
        }
        catch (Throwable ex) {
            Log.e(JNI_TAG, ex.getMessage());
        }
    }

    native static int GetNumberOfContacts();
    native static String AddContact(String theContactName);
    native static void startWaitingContacts();
    native static void init();
    static void incomingContact(String theName)
    {
        Log.i(JNI_TAG, "incomingContact " + theName);
    }
}
