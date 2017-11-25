#include <iostream>
#include <jni.h>

int main() {
    puts("Hello world from CPP");
    // Magic to initialise the JVM
    JavaVM *jvm;
    JNIEnv *env;
    JavaVMInitArgs vm_args;
    JavaVMOption options;
    // String to provide jar location
    options.optionString = "-Djava.class.path=hello.jar";
    // JNI version = 1_<Java version> (I think)
    vm_args.version = JNI_VERSION_1_8;
    // Number of options above, seiously Java you can't work that out?
    vm_args.nOptions = 1;
    // more magic now
    vm_args.options = &options;
    vm_args.ignoreUnrecognized = 0;
    
    // Make the JVM
    int ret = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
    
    // if successful do stuff with it.   
    if (ret == 0) {
        jclass cls = env->FindClass("Hello");
        if (cls != 0) {
            jmethodID meth = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
            if (meth != 0) { 
                jarray args = env->NewObjectArray(0, env->FindClass("java/lang/String"), 0);
                env->CallStaticVoidMethod(cls, meth, args);
            }
            else {
                puts("Did not find method");
            }
        }
        else {
            puts("Did not find class");
        }
    } 
    return ret;
}
