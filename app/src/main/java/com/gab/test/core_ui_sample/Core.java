package com.gab.test.core_ui_sample;

import android.app.Activity;
import android.util.Log;

/**
 * Created by sdv on 19.11.14.
 */
public class Core {
    native static int GetNumberOfContacts();
    native static String AddContact(String theContactName);
}
