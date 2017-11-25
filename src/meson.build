project('blockysynth', 'c', 'cpp', 'java')
gtk = dependency('gtk+-3.0')
gtkmm = dependency('gtkmm-3.0')
ccpp = meson.get_compiler('cpp')

# Get the JVM. These dirs are for Archlinux X86_64, add your dirs to the list and merge
jvm = ccpp.find_library('jvm', dirs : [
    '/usr/lib/jvm/default/jre/lib/amd64/server/', # Archlinx x86_64
    
    # Your advertisment here!
    
    ])
 
jvmdir = include_directories('/usr/lib/jvm/default/include', '/usr/lib/jvm/default/include/linux')


jar('hello', 'UI/java/com/example/Hello.java',
            main_class : 'com.example.Hello')

executable('tutorial', 'tutorial.c', dependencies : gtk)
executable('main', 'main.cpp', dependencies : gtkmm)
executable('nuktest', 'UI/embedded_nuklear_test.cpp', dependencies : gtkmm)
executable('jnitest', 'UI/jni_ui_test.cpp', dependencies : jvm, include_directories : jvmdir)
