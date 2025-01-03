cmake_minimum_required(VERSION 3.26)

project(maomor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Options.cmake)

###############################################################################

# Setează calea către SFML
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

###############################################################################

# Adaugă sursele proiectului
set(SOURCES
        main.cpp
        generated/src/Helper.cpp
        Pokemon.cpp
        SpecificMoves.cpp
        SpecificPokemon.cpp
        SpecificStatusEffects.cpp
        StatusEffect.cpp
        Types.cpp
        BattleSystem.cpp
)

set(HEADERS
        Pokemon.h
        SpecificMoves.h
        SpecificPokemon.h
        SpecificStatusEffects.h
        StatusEffect.h
        Types.h
        BattleSystem.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

include(cmake/CompilerFlags.cmake)

###############################################################################

# Includeri necesare pentru SFML
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE lib/SFML/include)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE generated/include)

# Link SFML la proiect
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

###############################################################################

# Setează directorul de instalare
set(INSTALL_DIR ${CMAKE_BINARY_DIR}/bin)

# Instalează binarele în folderul "bin"
install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})

# Copiază fișierele necesare în directorul de instalare
install(FILES tastatura.txt DESTINATION ${INSTALL_DIR})
install(DIRECTORY images sounds DESTINATION ${INSTALL_DIR})

# Copiază fișierul launcher.command doar pe sistemele Apple
if(APPLE)
    install(FILES launcher.command DESTINATION ${INSTALL_DIR})
endif()