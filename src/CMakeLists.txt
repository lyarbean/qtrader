qt5_add_resources(qtrader_SRCS resources.qrc)
add_executable(qtrader main.cpp ${qtrader_SRCS})
target_link_libraries(qtrader Qt5::Qml Qt5::Gui)

