all: libSCARLib.so
libSCARLib.so: SCARLib.o dsimple.o clientwin.o
	cc -lX11 -shared -Wl,-soname,libSCARLib.so -o libSCARLib.so SCARLib.o dsimple.o clientwin.o
SCARLib.o: SCARLib.c edu/js/SCARlib/SCARLib.h 
	cc -I"/usr/lib/jvm/java-6-openjdk/include" -I"/usr/lib/jvm/java-6-openjdk/include/linux" -fPIC -c SCARLib.c -o SCARLib.o
dismple.o: dsimple.c
	cc -c dsimple.c -o dsimple.o
clientwin.o: clientwin.c
	cc -c clientwin.c -o clientwin.o
edu/js/SCARlib/SCARLib.h: edu/js/SCARlib/SCARLib.class
	javah -jni edu.js.SCARlib.SCARLib
clean:
	-rm edu/js/SCARlib/SCARLib.h
	-rm SCARLib.o
	-rm dsimple.o
	-rm clientwin.o