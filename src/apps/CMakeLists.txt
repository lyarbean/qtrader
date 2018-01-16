include_directories(..)
set(SINARECORDER_SRC sinarecorder.cpp )
add_executable(sinarecorder ${SINARECORDER_SRC})
target_link_libraries(sinarecorder Qt5::Core oz -lcurl)
