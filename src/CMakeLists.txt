qt5_add_resources(qtrader_SRCS resources.qrc)
add_executable(qtrader main.cpp ${qtrader_SRCS})
target_link_libraries(qtrader Qt5::Qml Qt5::Gui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(ABSTRACT_SRC abstract/engineabstract.cpp abstract/engineabstract.cpp abstract/gatewayabstract.cpp abstract/strategyabstract.cpp)
set(CORE_SRC core/defaultengine.cpp core/recordstrategy.cpp core/riskmanager.cpp)
set(EXTENSION_SRC extension/sinagateway.cpp extension/sinadatatypes.cpp)
add_library(oz ${ABSTRACT_SRC} ${CORE_SRC} ${EXTENSION_SRC})
target_link_libraries(oz Qt5::Core)


add_subdirectory(apps)
