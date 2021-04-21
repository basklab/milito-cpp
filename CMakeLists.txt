cmake_minimum_required(VERSION 3.17)
project(milito_cpp)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json 3.9.1 REQUIRED)
find_package(yaml-cpp REQUIRED)

include_directories(${YAML_INCLUDE_DIRS})

#add_library(foo ...)

add_executable(milito_cpp main.cpp entity/Card.h entity/LeaderCard.h entity/UnitCard.h config/decks/AlexandrianMacedonian.h config/decks/AncientBritish.h config/decks/commonDecks.h entity/Deck.h)
target_link_libraries(milito_cpp PRIVATE nlohmann_json::nlohmann_json ${YAML_CPP_LIBRARIES})
