cmake_minimum_required(VERSION 3.27)
project(TP1_GR1_24_Allegro C)

set(CMAKE_C_STANDARD 11)

add_executable(TP1_GR1_24_Allegro main.c)

IF(WIN32)
    target_link_libraries(TP1_GR1_24_Allegro -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.9.1/include)
    LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.9.1/lib)
    file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.9.1/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(TP1_GR1_24_Allegro  ${LIBRARIES})
ENDIF(WIN32)