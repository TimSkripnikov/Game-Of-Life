if(EXISTS "/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/tests/LifeTests[1]_tests.cmake")
  include("/home/artem/Documents/2 course/Object-Oriented Programming/ex2/build/tests/LifeTests[1]_tests.cmake")
else()
  add_test(LifeTests_NOT_BUILT LifeTests_NOT_BUILT)
endif()