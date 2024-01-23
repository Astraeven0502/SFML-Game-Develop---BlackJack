cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME SFML_Game_Project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Fonts.cpp Fonts.h States.cpp States.h Button.cpp Button.h Cards.cpp Cards.h CardAssets.h Ranks.cpp Ranks.h Suits.cpp Suits.h Deck.cpp Deck.h images.cpp images.h Game.cpp Game.h LinkedList.cpp LinkedList.h Node.h Stack.cpp Stack.h StackOfCard.cpp StackOfCard.h Scorer.cpp Scorer.h MoneyBox.cpp MoneyBox.h Ante.cpp Ante.h MouseEvents.cpp MouseEvents.h Dealer.cpp Dealer.h Player.cpp Player.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT D:/SFML/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()