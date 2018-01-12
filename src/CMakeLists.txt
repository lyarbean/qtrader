qt5_add_resources(qtrader_SRCS resources.qrc)
add_executable(qtrader main.cpp ${qtrader_SRCS})
target_link_libraries(qtrader Qt5::Qml Qt5::Gui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(ABSTRACT_SRC abstract/engineabstract.cpp abstract/engineabstract.cpp abstract/gatewayabstract.cpp abstract/strategyabstract.cpp)
set(CORE_SRC core/defaultengine.cpp core/recordstrategy.cpp)
add_library(dummy ${ABSTRACT_SRC} ${CORE_SRC})
target_link_libraries(dummy Qt5::Core)

