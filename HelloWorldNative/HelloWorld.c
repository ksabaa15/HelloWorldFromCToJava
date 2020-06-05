// Native methods implementation of
// /home/karim/NetBeansProjects/HelloWorld/src/helloworld/HelloWorld.java

#include "HelloWorld.h"
#include "stdio.h"
#include <stdlib.h>




#define CALL_JAVA(class_name,function_name,function_signature, ...)({\
    jclass cls;\
    jmethodID mid;\
    jstring  jstr;\
    jobjectArray main_args;\
    cls = (*env)->FindClass(env, class_name);\
    if(cls == NULL) { \
        fprintf(stderr,"Failed to find class %s\n",class_name);fflush(stderr);\
        exit(1);\
    }\
    mid = (*env)->GetStaticMethodID(env, cls, function_name, function_signature);\
    if (mid == NULL) {\
        fprintf(stderr,"Failed to find function %s %s\n",function_name, function_signature);fflush(stderr);\
        exit(1);\
    }\
    (*env)->CallStaticVoidMethod(env, cls, mid, ##__VA_ARGS__ );})


void JNICALL Java_helloworld_HelloWorld_helloWorld_1c
  (JNIEnv * env, jclass object) {
    
    printf("Hello World, from C\n"); fflush(stdout);
    
    CALL_JAVA("helloworld/HelloWorld","helloWorld","()V");
	
}

