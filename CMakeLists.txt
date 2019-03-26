cmake_minimum_required (VERSION 3.6)

if( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin" )
  set(SOS_TOOLCHAIN_CMAKE_PATH /Applications/StratifyLabs-SDK/Tools/gcc/arm-none-eabi/cmake)
endif()
if( ${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows" )
	set(SOS_TOOLCHAIN_CMAKE_PATH C:/StratifyLabs-SDK/Tools/gcc/arm-none-eabi/cmake)
endif()

include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-variables.cmake)
set(CMAKE_TOOLCHAIN_FILE ${SOS_TOOLCHAIN_CMAKE_PATH}/sos-bsp-toolchain.cmake)

get_filename_component(SOS_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${SOS_NAME} CXX C)

#Add sources to the project
set(SOURCES_PREFIX ${CMAKE_SOURCE_DIR}/src)
add_subdirectory(src)
list(APPEND KERNEL_SOURCELIST ${SOURCES} ${CMAKE_SOURCE_DIR}/README.md ${CMAKE_SOURCE_DIR}/sl_settings.json)

#Change to boot sources
set(SOURCES "")
set(SOURCES_PREFIX ${CMAKE_SOURCE_DIR}/boot)
add_subdirectory(boot)
list(APPEND BOOT_SOURCELIST ${SOURCES})

set(SOS_ARCH v7em_f5dh)
set(SOS_DEVICE stm32h743zi)
set(SOS_DEVICE_FAMILY stm32h743xx)
set(SOS_HARDWARD_ID 0x00000021)
set(SOS_LIBRARIES son_kernel arm_dsp_sos_kernel)
set(SOS_INCLUDE_DIRECTORIES ${TOOLCHAIN_INC_DIR}/mcu/arch/stm32/cmsis)

set(SOS_KERNEL_START_ADDRESS 0x08100000)
set(SOS_KERNEL_SOURCELIST ${KERNEL_SOURCELIST})
set(SOS_BOOT_START_ADDRESS 0x08000000)
set(SOS_BOOT_SOURCELIST ${BOOT_SOURCELIST})
include(${SOS_TOOLCHAIN_CMAKE_PATH}/sos-bsp-std.cmake)
