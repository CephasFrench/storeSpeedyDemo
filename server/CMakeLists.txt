# Specify the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.10)

# Define the name of the project
project(storeSpeedyDEMO)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Define the source directory
set(SRC_DIR ${CMAKE_SOURCE_DIR}/driver/src)

# Define the directories
set(API_DIR ${SRC_DIR}/api)
set(API_JSON_DIR ${API_DIR}/json)
set(API_ENDPOINTS_DIR ${API_DIR}/endpoints)
set(INCLUDES_DIR ${SRC_DIR}/incudes)
set(CROW_DIR ${INCLUDES_DIR}/crow)
set(OBJECTS_DIR ${SRC_DIR}/objects)
set(STORAGE_DIR ${CMAKE_SOURCE_DIR}/storage)
set(LOCATIONS_DIR ${STORAGE_DIR}/locations)
set(USERS_DIR ${STORAGE_DIR}/users/default)

# Find the CURL package
find_package(CURL REQUIRED)
if (NOT CURL_FOUND)
    message(FATAL_ERROR "CURL library not found")
endif()

# Find the OpenCV package
find_package(OpenCV REQUIRED)
if (NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV library not found")
endif()

# Find the PkgConfig package
find_package(PkgConfig REQUIRED)
if (NOT PkgConfig_FOUND)
    message(FATAL_ERROR "PkgConfig not found")
endif()

# Find the Boost package
find_package(Boost REQUIRED)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost library not found")
endif()

# Find Poppler using PkgConfig
pkg_check_modules(POPPLER REQUIRED IMPORTED_TARGET poppler-cpp)
if (NOT POPPLER_FOUND)
    message(FATAL_ERROR "Poppler library not found")
endif()

# Manually find JSONCPP if not found by CMake
find_path(JSONCPP_INCLUDE_DIR json/json.h)
find_library(JSONCPP_LIBRARY jsoncpp)
if (NOT JSONCPP_INCLUDE_DIR OR NOT JSONCPP_LIBRARY)
    message(FATAL_ERROR "jsoncpp library not found")
endif()

# Include directories
include_directories(${SRC_DIR})
include_directories(${API_DIR})
include_directories(${API_JSON_DIR})
include_directories(${API_ENDPOINTS_DIR})
include_directories(${INCLUDES_DIR})  # This includes driver/src/incudes
include_directories(${CROW_DIR})      # This includes driver/src/incudes/crow
include_directories(${OBJECTS_DIR})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${JSONCPP_INCLUDE_DIR})
include_directories(${POPPLER_INCLUDE_DIRS})

# Define source files
set(SOURCE_FILES
    ${SRC_DIR}/main.cpp
    ${API_DIR}/api_util.cpp
    ${API_JSON_DIR}/StoreSpeedyJsonHandler.cpp
    ${API_ENDPOINTS_DIR}/compute_path.cpp
    ${API_ENDPOINTS_DIR}/update_aisle_data.cpp
    ${API_ENDPOINTS_DIR}/ping.cpp
    ${API_ENDPOINTS_DIR}/update_location.cpp
    ${API_ENDPOINTS_DIR}/grocery_list.cpp
    ${API_ENDPOINTS_DIR}/update_grocery_list.cpp
    ${API_ENDPOINTS_DIR}/check_item.cpp
    ${OBJECTS_DIR}/aisle.cpp
    ${OBJECTS_DIR}/cart.cpp
    ${OBJECTS_DIR}/item.cpp
)

# Add an executable target named 'storeSpeedyDEMO' built from multiple source files
add_executable(storeSpeedyDEMO ${SOURCE_FILES})

# Link the libraries to the 'storeSpeedyDEMO' target
target_link_libraries(storeSpeedyDEMO
    CURL::libcurl
    ${JSONCPP_LIBRARY}
    ${OpenCV_LIBS}
    PkgConfig::POPPLER
    ${Boost_LIBRARIES}
)

# Additional checks for system compatibility

# Check for UNIX-specific settings
if(UNIX)
    message(STATUS "Configuring for UNIX system")
    # Additional UNIX-specific settings can go here
endif()

# Check for Windows-specific settings
if(WIN32)
    message(STATUS "Configuring for Windows system")
    # Ensure libraries and tools are available on Windows
    if (NOT DEFINED CMAKE_PREFIX_PATH)
        set(CMAKE_PREFIX_PATH "C:/path/to/dependencies")
    endif()
    # Additional Windows-specific settings can go here
endif()
