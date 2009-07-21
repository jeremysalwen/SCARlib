all: libSCARLib.so libSCARLib.jnilib
libSCARLib.so: SCARLibX11.o dsimple.o clientwin.o
	cc -lX11 -shared -Wl,-soname,libSCARLib.so -o libSCARLib.so SCARLibX11.o dsimple.o clientwin.o
SCARLibX11.o: SCARLibX11.c edu_js_SCARlib_SCARLib.h 
	cc -I"/usr/lib/jvm/java-6-openjdk/include" -I"/usr/lib/jvm/java-6-openjdk/include/linux" -fPIC -c SCARLibX11.c -o SCARLib.o
dismple.o: dsimple.c
	cc -c dsimple.c -o dsimple.o
clientwin.o: clientwin.c
	cc -c clientwin.c -o clientwin.o
libSCARLib.jnilib: SCARLibOSX.o
	cc -dynamiclib -o libSCARLib.jnilib SCARLibOSX.o -framework JavaVM
SCARLibOSX.o: SCARLibOSX.c
	cc -c -I/System/Library/Frameworks/JavaVM.framework/Headers -I/System/Library/Frameworks/Carbon.framework/Headers SCARLibOSX.c -o SCARLibOSX.o
edu_js_SCARlib_SCARLib.h: edu/js/SCARlib/SCARLib.class
	javah -jni edu.js.SCARlib.SCARLib
clean:
	-rm edu_js_SCARlib_SCARLib.h
	-rm SCARLibX11.o
	-rm dsimple.o
	-rm clientwin.o