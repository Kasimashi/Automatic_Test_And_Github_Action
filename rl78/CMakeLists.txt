cmake_minimum_required(VERSION 3.22)

project(A-and-B
  DESCRIPTION "Building components A, B and the library"
  VERSION 1.0.0
  LANGUAGES C )


# Library
add_library(library
  ../portable/library/crc32.c
  ../portable/library/debug_log.c
  ../portable/library/divisionByZero.c
  ../portable/library/math_log.c
  ../portable/library/math_mul.c
  ../portable/library/math_sum.c
  ../portable/library/nullAssign.c
  ../portable/library/unreachableCode.c )

target_include_directories(library
  PUBLIC ../portable/library )

# Component A
add_executable(componentA
  # Source files
  ../portable/componentA/componentA.c )

target_link_libraries(componentA LINK_PUBLIC library)
target_link_options(componentA PRIVATE
  $<$<CONFIG:Debug>:--debug_lib --redirect ___write=___write_buffered --config_def __RESERVE_OCD_ROM=1>
  # The `SHELL:` prefix prevents option de-duplication
  "SHELL:--config_def _STACK_SIZE=128"
  "SHELL:--config_def _NEAR_HEAP_SIZE=512"
  "SHELL:--config_def _FAR_HEAP_SIZE=2048"
  "SHELL:--config_def _HUGE_HEAP_SIZE=0"
  "SHELL:--define_symbol _NEAR_CONST_LOCATION=0"
  "SHELL:--config_def _NEAR_CONST_LOCATION_START=0x2000"
  "SHELL:--config_def _NEAR_CONST_LOCATION_SIZE=0x6F00"
  # Set the linker script
  --config "${TOOLKIT_DIR}/config/lnkrl78_s2.icf" )


# Component B
add_executable(componentB
  # Source files
  ../portable/componentB/componentB.c )

target_link_libraries(componentB LINK_PUBLIC library)
target_link_options(componentB PRIVATE
  $<$<CONFIG:Debug>:--debug_lib --redirect ___write=___write_buffered --config_def __RESERVE_OCD_ROM=1>
  # The `SHELL:` prefix prevents option de-duplication
  "SHELL:--config_def _STACK_SIZE=256"
  "SHELL:--config_def _NEAR_HEAP_SIZE=1024"
  "SHELL:--config_def _FAR_HEAP_SIZE=4096"
  "SHELL:--config_def _HUGE_HEAP_SIZE=0"
  "SHELL:--define_symbol _NEAR_CONST_LOCATION=0"
  "SHELL:--config_def _NEAR_CONST_LOCATION_START=0x3000"
  "SHELL:--config_def _NEAR_CONST_LOCATION_SIZE=0x6F00"
  # Set the linker script
  --config "${TOOLKIT_DIR}/config/lnkrl78_s3.icf" )
