project('blockysynth', 'c', 'cpp')
gtk = dependency('gtk+-3.0')
gtkmm = dependency('gtkmm-3.0')

executable('tutorial', 'tutorial.c', dependencies : gtk)
executable('main', 'main.cpp', dependencies : gtkmm)
executable('nuktest', 'UI/embedded_nuklear_test.cpp', dependencies : gtkmm)
