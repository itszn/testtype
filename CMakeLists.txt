project(typetest)
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "")
    message("Found vcpkg root '$ENV{VCPKG_ROOT}'")
elseif(WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    message(FATAL_ERROR "Could not find vcpkg root")
endif()

find_package(Freetype REQUIRED)

set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src/)
file(GLOB SRC "${SRCROOT}/*.c" "${SRCROOT}/*.h")
source_group("Source" FILES ${SRC})



set(MAIN_SRC ${SRC})
add_executable(typetest ${MAIN_SRC})

target_link_libraries(typetest ${FREETYPE_LIBRARIES})
target_include_directories(typetest PRIVATE ${FREETYPE_INCLUDE_DIRS})
target_compile_definitions(typetest PRIVATE -DFONS_USE_FREETYPE)
