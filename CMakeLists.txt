cmake_minimum_required(VERSION 3.18)
project(TODO_CHANGEME VERSION 1.0)

include(CMakeLists.config)

set(CPP_SRCS  # TODO: add all non-main source files
${PROJECT_NAME}.cpp
)

# add_executable(${PROJECT_NAME} main.cpp ${CPP_SRCS})

foreach(sourcefile ${CPP_SRCS})
  string(REPLACE ".cpp" "_test.cpp" testfile ${sourcefile})
  string(REPLACE ".cpp" "" testexecutable ${testfile})
  message(STATUS "${sourcefile} + ${testfile} => ${testexecutable}")
  add_executable(${testexecutable} ${sourcefile} ${testfile})
  target_link_libraries(${testexecutable} catch2)
  add_test(NAME ${testexecutable}
           COMMAND ${testexecutable})
endforeach()
