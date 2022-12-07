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
  $<$<CONFIG:Debug>:--debug_lib --redirect ___write=___write_buffered>
  # The `SHELL:` prefix prevents option de-duplication
  "SHELL:--config_def _USTACK_SIZE=0x800"
  "SHELL:--config_def _ISTACK_SIZE=0x800"
  "SHELL:--config_def   _HEAP_SIZE=0x200"
  # Set the linker script
  --config "${TOOLKIT_DIR}/config/lnkr5f563ne.icf" )


# Component B
add_executable(componentB
  # Source files
  ../portable/componentB/componentB.c )

target_link_libraries(componentB LINK_PUBLIC library)
target_link_options(componentB PRIVATE
  $<$<CONFIG:Debug>:--debug_lib --redirect ___write=___write_buffered>
  # The `SHELL:` prefix prevents option de-duplication
  "SHELL:--config_def _USTACK_SIZE=0x800"
  "SHELL:--config_def _ISTACK_SIZE=0x800"
  "SHELL:--config_def   _HEAP_SIZE=0x100"
  # Set the linker script
  --config "${TOOLKIT_DIR}/config/lnkr5f563ne.icf" )
