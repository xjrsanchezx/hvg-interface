cmake_minimum_required ( VERSION 2.8.11 )

PROJECT( hvg_interface )

SET ( HVG_PATH ${CMAKE_SOURCE_DIR}//data/ CACHE PATH "The directory with the games")

# config file
configure_file ("${PROJECT_SOURCE_DIR}/include/config.h.in"
                "${PROJECT_SOURCE_DIR}/include/config.h" )

# Instruct CMake to run moc automatically when needed.
SET(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
 
FIND_PACKAGE(Qt5Widgets)

SET( QT_USE_QTWEBKIT TRUE )

SET( HVG_INTERFACE_SRC
	src/main.cpp	
	src/mainDlg.cpp
	src/mainController.cpp
	src/infoController.cpp	
	src/gameListController.cpp	
	src/mainModel.cpp
	src/gameListModel.cpp
	src/infoModel.cpp	
)

SET( HVG_INTERFACE_H
	include/config.h
	include/factory.h
	include/mainDlg.h
	include/controller.h
	include/model.h
	include/mainController.h
	include/infoController.h
	include/gameListController.h
	include/mainModel.h
	include/gameListModel.h
	include/infoModel.h
)

SET( HVG_INTERFACE_FORMS
	ui/hvg_main.ui
)

SET( HVG_INTERFACE_RESOURCES
	resources/hvg.qrc
)

QT5_WRAP_UI(UIS_HDRS ${HVG_INTERFACE_FORMS})
QT5_ADD_RESOURCES( HVG_RES ${HVG_INTERFACE_RESOURCES} ) 

INCLUDE_DIRECTORIES( include )
SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin )

ADD_EXECUTABLE (hvg_interface ${HVG_INTERFACE_SRC} ${HVG_INTERFACE_H} ${UIS_HDRS} ${HVG_RES}) 

qt5_use_modules(hvg_interface Widgets WebKitWidgets Sql)
