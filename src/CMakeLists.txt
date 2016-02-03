CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

SET(ProjectName "ProjectName")
SET(ExecName    "Executable_Name")

PROJECT(${ProjectName})

FILE(GLOB sourcefiles "*.cpp" "*.hpp")
ADD_EXECUTABLE(${ExecName} ${sourcefiles})

SET(bindir ${CMAKE_HOME_DIRECTORY}/../bin)
SET(docdir ${CMAKE_HOME_DIRECTORY}/../../doc)

FILE(GLOB test_scripts "test_scripts/*py")
FILE(GLOB test_inputs  "test_inputs/*")
FILE(COPY ${test_scripts} DESTINATION ${CMAKE_BINARY_DIR})
FILE(COPY ${test_inputs}  DESTINATION ${CMAKE_BINARY_DIR})

# Default to a Release build.
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE "Release")
ENDIF()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -Wall")
 
INCLUDE(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
IF(COMPILER_SUPPORTS_CXX11)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ELSEIF(COMPILER_SUPPORTS_CXX0X)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
ELSE()
    MESSAGE(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
ENDIF()

# Enable code coverage and profiling on debug builds.
#SET(GCC_COVERAGE_COMPILE_FLAGS   "-fprofile-arcs -ftest-coverage")
#SET(GCC_COVERAGE_LINK_FLAGS      "-lgcov")
#SET(CMAKE_CXX_FLAGS_DEBUG        "${CMAKE_CXX_FLAGS}        ${GCC_COVERAGE_COMPILE_FLAGS}" )
#SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

#install(TARGETS Project_Name DESTINATION ${bindir})

#enable_testing()
#
#################################################################################
## Test Cases
#################################################################################
#
#add_test(       NAME T0001      COMMAND ${ExecName} T0001.inp)
#add_test(       NAME T0002      COMMAND ${ExecName} T0002.inp)
#add_test(       NAME T0003      COMMAND ${ExecName} T0003.inp)
#add_test(       NAME T0004      COMMAND ${ExecName} T0004.inp)
#add_test(       NAME T0005      COMMAND ${ExecName} T0005.inp)
#
#set_tests_properties(T0001      PROPERTIES TIMEOUT 15 LABELS "Test_Collection_1")
#set_tests_properties(T0002      PROPERTIES TIMEOUT 15 LABELS "Test_Collection_1")
#set_tests_properties(T0003      PROPERTIES TIMEOUT 15 LABELS "Test_Collection_1")
#set_tests_properties(T0004      PROPERTIES TIMEOUT 15 LABELS "Test_Collection_1")
#set_tests_properties(T0005      PROPERTIES TIMEOUT 15 LABELS "Test_Collection_1")
#
#add_test(NAME Test_Collection_1_Plot COMMAND 
#plot_script.py
#Plot_Output_Prefix
#T0001.dat
#T0002.dat
#T0003.dat
#T0004.dat
#T0005.dat
#)
#
#set_tests_properties(Test_Collection_1_Plot PROPERTIES TIMEOUT 30 DEPENDS 
#"T0001
#;T0002
#;T0003
#;T0004
#;T0005"
#)
#  
#################################################################################
## Copy out Plots
#################################################################################
#
#add_test(NAME Copy_Out_Plots COMMAND cp 
#ners_574_hw_03_kulesza_problem_4_forward_diff_plot.png 
#ners_574_hw_03_kulesza_problem_4_lax_cdtdx_08_plot.png 
#ners_574_hw_03_kulesza_problem_4_lax_cdtdx_099_plot.png 
#ners_574_hw_03_kulesza_problem_4_lax_cdtdx_101_plot.png 
#ners_574_hw_03_kulesza_problem_4_diffusion_plot.png 
#${docdir})
#
#set_tests_properties(Copy_Out_Plots PROPERTIES TIMEOUT 15 DEPENDS 
#"Test_Collection_1_Plot")
#
