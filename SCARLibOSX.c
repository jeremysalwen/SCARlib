/*
 * SCARLibOSX.c
 *
 *  Created on: Jul 21, 2009
 *      Author:
 */
#include <Carbon/Carbon.h>
#include "edu_js_SCARlib_SCARLib.h"

typedef struct {
	int x;
	int y;
} point;
int main() {
	CFArrayRef array = CGWindowListCopyWindowInfo(kCGWindowListOptionOnScreenOnly,
			kCGNullWindowID);
	CFIndex array_length = CFArrayGetCount(array);
	for (CFIndex i = 0; i < array_length; i++) {
		CFDictionaryRef dictionary = CFArrayGetValueAtIndex(array, i);
		CFStringRef name = CFDictionaryGetValue(dictionary, kCGWindowName);
		if(name) {
		int length=CFStringGetMaximumSizeForEncoding(CFStringGetLength(name),kCFStringEncodingASCII);
		char * cstr=malloc(length+1);
		CFStringGetCString(name,cstr,length+1,kCFStringEncodingASCII);
		printf("%s + %i\n",cstr,CFDictionaryGetValue(dictionary,kCGWindowLayer));
		free(cstr);}
		else{
		printf("Null!\n");
		}
	}
}
point UserClickSomewhere() {
	//TODO
}
JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_UserFindWindow(
		JNIEnv * env, jobject class, jlong xconnection) {
	point loc=UserClickSomewhere();

}

JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_XOpenDisplay__(
		JNIEnv * env, jobject class) {
	return 0;
}

JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_XOpenDisplay__Ljava_lang_String_2(
		JNIEnv * env, jobject class, jstring name) {
	return 0;
}

JNIEXPORT void JNICALL Java_edu_js_SCARlib_SCARLib_XCloseDisplay(JNIEnv * env,
		jobject class, jlong connection) {
}

JNIEXPORT jobject JNICALL Java_edu_js_SCARlib_SCARLib_getWindowLocation(
		JNIEnv * env, jobject class, jlong display, jlong window) {

}

JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_getWindowByName(
		JNIEnv * env, jobject class, jlong xconnection, jstring name) {

}
JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_getRootWindow(JNIEnv * env,
		jobject obj, jlong connection) {
}
JNIEXPORT void JNICALL Java_edu_js_SCARlib_SCARLib_ActivateWindow(JNIEnv * env,
		jobject obj, jlong connection, jlong window) {
}
JNIEXPORT jobject JNICALL Java_edu_js_SCARlib_SCARLib_GetWindowDimensions(
		JNIEnv * env, jobject obj, jlong connection, jlong window) {
}

JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_getWindowByNamePart(
		JNIEnv *env, jobject obj, jlong display, jstring name,
		jboolean casematters) {
}

JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_GetWindowBySize(
		JNIEnv * env, jobject obj, jlong display, jint width, jint height) {
}
