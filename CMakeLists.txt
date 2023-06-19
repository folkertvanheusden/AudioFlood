project(AudioFlood)
cmake_minimum_required(VERSION 3.2)

add_executable(
  AudioFlood
  main.cpp
  pipewire.cpp
  pipewire-audio.cpp
)

#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads)
target_link_libraries(AudioFlood Threads::Threads)

include(FindPkgConfig)

pkg_check_modules(SNDFILE REQUIRED sndfile)
target_link_libraries(AudioFlood ${SNDFILE_LIBRARIES})
target_include_directories(AudioFlood PUBLIC ${SNDFILE_INCLUDE_DIRS})
target_compile_options(AudioFlood PUBLIC ${SNDFILE_CFLAGS_OTHER})

# pipewire
find_package(PipeWire)
pkg_check_modules(PIPEWIRE libpipewire-0.3)
target_link_libraries(AudioFlood ${PIPEWIRE_LIBRARIES})
target_include_directories(AudioFlood PUBLIC ${PIPEWIRE_INCLUDE_DIRS})
target_compile_options(AudioFlood PUBLIC ${PIPEWIRE_CFLAGS_OTHER})
