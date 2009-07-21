#include "edu_js_SCARlib_SCARLib.h"
#include <X11/Xlib.h>
#include "dsimple.h"
#include <limits.h>

typedef struct {
	int x;
	int y;
} point;

JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_UserFindWindow(JNIEnv * env, jobject class, jlong xconnection) {
  	Display * display=(Display *)xconnection;
  	Window result;
  	result=Select_Window(display,1,1);  //The true makes it ignore window manager 
  	return result;
  	}
  	
JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_XOpenDisplay__
  (JNIEnv * env, jobject class) {
  	return (jlong)XOpenDisplay(NULL);
  }
  
  JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_XOpenDisplay__Ljava_lang_String_2
  (JNIEnv * env, jobject class, jstring name) {
  	const char * cname=(*env)->GetStringUTFChars(env,name,0);
  	Display * result=XOpenDisplay(cname);
  	(*env)->ReleaseStringUTFChars(env,name,cname);
  	return (jlong)result;
  }
  
  JNIEXPORT void JNICALL Java_edu_js_SCARlib_SCARLib_XCloseDisplay
  (JNIEnv * env, jobject class , jlong connection) {
  	Display * c=(Display *) connection;
  	XCloseDisplay(c);
  }
  
  JNIEXPORT jobject JNICALL Java_edu_js_SCARlib_SCARLib_getWindowLocation
  (JNIEnv * env, jobject class, jlong display, jlong window) {
  	XWindowAttributes w;
  	XGetWindowAttributes((Display *) display, (Window)window,&w);
  	int resultx, resulty;
  	Window childreturn;
  	XTranslateCoordinates((Display *)display,window,w.root,0,0,&resultx,&resulty,&childreturn);
  	jclass javapoint=(*env)->FindClass(env,"java/awt/Point");
  	jobject javaobj=(*env)->NewObject(env,javapoint,(*env)->GetMethodID(env,javapoint,"<init>","()V"));
  	(*env)->CallVoidMethod(env,javaobj,(*env)->GetMethodID(env,javapoint,"setLocation","(II)V"),resultx,resulty);
  	return javaobj;
  }
  	
  JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_getWindowByName
  (JNIEnv * env, jobject class, jlong xconnection, jstring name) {
    const char * cname=(*env)->GetStringUTFChars(env,name,0);
    Window result=Window_With_Name((Display *)xconnection,XDefaultRootWindow((Display *)xconnection),cname);
    (*env)->ReleaseStringUTFChars(env,name,cname);
    return result;
  }
  JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_getRootWindow
  (JNIEnv * env, jobject obj, jlong connection) {
  	return XDefaultRootWindow((Display *)connection);
  }
  JNIEXPORT void JNICALL Java_edu_js_SCARlib_SCARLib_ActivateWindow
  (JNIEnv * env, jobject obj, jlong connection, jlong window) {
  	XSetInputFocus((Display *)connection,(Window)window,RevertToNone,CurrentTime);
  }
  JNIEXPORT jobject JNICALL Java_edu_js_SCARlib_SCARLib_GetWindowDimensions
  (JNIEnv * env, jobject obj, jlong connection, jlong window) {
  	  	XWindowAttributes w;
  	XGetWindowAttributes((Display *) connection, (Window)window,&w);
   	jclass javapoint=(*env)->FindClass(env,"java/awt/Point");
  	jobject javaobj=(*env)->NewObject(env,javapoint,(*env)->GetMethodID(env,javapoint,"<init>","()V"));
  	(*env)->CallVoidMethod(env,javaobj,(*env)->GetMethodID(env,javapoint,"setLocation","(II)V"),w.width,w.height);
  	return javaobj;
  }
  
  JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_getWindowByNamePart
  (JNIEnv *env , jobject obj, jlong display, jstring name, jboolean casematters) {
  	const char * cname=(*env)->GetStringUTFChars(env,name,0);
  	Window result=Window_With_Name_Part((Display *)display, XDefaultRootWindow((Display *)display),cname, casematters);
  	(*env)->ReleaseStringUTFChars(env,name,cname);
  	return result;
  }
  
  JNIEXPORT jlong JNICALL Java_edu_js_SCARlib_SCARLib_GetWindowBySize
  (JNIEnv * env, jobject obj, jlong display, jint width, jint height) {
  	return Window_With_Size((Display *)display,XDefaultRootWindow((Display *)display),width,height);
  }