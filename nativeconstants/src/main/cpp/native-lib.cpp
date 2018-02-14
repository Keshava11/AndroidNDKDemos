//
// Created by ravi on 2/13/18.
//
#include <jni.h>
#include <string>
#include <android/log.h>

#define TAG "AndroidNDKDemos"


extern "C" {

// Define keys/Values for all the string constants
const char *mStringConstantKeys[] = {"base_url", "api_key", "user_email", "user_pass"};

const char *mStringConstantValues[] = {"http://www.mocky.io/", "AIzerrsu67t6", "test@email.com",
                                       "test@123"};

// Define keys/values for all the integer constants
const char *mIntegerConstantKeys[] = {"db_version", "max_reversal_attempt", "phone_number",
                                      "nrc_length"};
const int mIntegerConstantValues[] = {1, 3, 11, 6};


// Method  to return constant integer
jint
Java_com_ravi_androidndkdemos_NDKDemosActivity_getMyInts(JNIEnv *env,
                                                                                   jobject instance,
                                                                                   jstring iKeyName_) {
    // Check for the key
    const char *keyName = env->GetStringUTFChars(iKeyName_, 0);

    // Value to be returned
    int value = -1; // Default

    for (int index = 0; index < 4; index++) {
        int compResult = strcmp(keyName, mIntegerConstantKeys[index]);
        if (compResult == 0) {
            value = mIntegerConstantValues[index];
            break;
        }
    }

    __android_log_print(ANDROID_LOG_INFO, TAG, "String constant resolved for key %s is  %d",
                        keyName, value);

    env->ReleaseStringUTFChars(iKeyName_, keyName);

    return value;
}


// Method to return constant string based on the key
jstring
Java_com_ravi_androidndkdemos_NDKDemosActivity_getMyStrings(JNIEnv *env,
                                                                                      jobject instance,
                                                                                      jstring iKeyName_) {
    const char *keyName = env->GetStringUTFChars(iKeyName_, 0);

    // Value to be returned to the caller method
    const char *value = "Default"; // Default

    for (int index = 0; index < 4; index++) {
        int compResult = strcmp(keyName, mStringConstantKeys[index]);
        if (compResult == 0) {
            value = mStringConstantValues[index];
            break;
        }
    }

    __android_log_print(ANDROID_LOG_INFO, TAG, "String constant resolved for key %s is  %s",
                        keyName, value);

    env->ReleaseStringUTFChars(iKeyName_, keyName);

    return env->NewStringUTF(value);
}


}
