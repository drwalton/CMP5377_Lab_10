cmake_minimum_required(VERSION 4.2)

project(Lab10)

include_directories(
    ${CMAKE_SOURCE_DIR}/3rdParty/SDL3-3.4.2/include
    ${CMAKE_SOURCE_DIR}/3rdParty/SDL3_ttf-3.2.2/include
    ${CMAKE_SOURCE_DIR}/3rdParty/SDL3_net-3.2.0/include
    ${CMAKE_SOURCE_DIR}/3rdParty/SDL3_image-3.4.4/include
    spritelib
)

set(SDL_LIBS
    ${CMAKE_SOURCE_DIR}/3rdParty/SDL3-3.4.2/lib/x64/SDL3.lib
    ${CMAKE_SOURCE_DIR}/3rdParty/SDL3_ttf-3.2.2/lib/x64/SDL3_ttf.lib
    ${CMAKE_SOURCE_DIR}/3rdParty/SDL3_net-3.2.0/lib/x64/SDL3_net.lib
    ${CMAKE_SOURCE_DIR}/3rdParty/SDL3_image-3.4.4/lib/x64/SDL3_image.lib
)

add_library(spritelib
    spritelib/GameObject.hpp
    spritelib/GameObject.cpp
    spritelib/Sprite.hpp
    spritelib/Sprite.cpp
)

add_executable(ball_bounce_game
    ball_bounce_game/Main.cpp

    ball_bounce_game/App.cpp
    ball_bounce_game/App.hpp
    ball_bounce_game/Ball.cpp
    ball_bounce_game/Ball.hpp
    ball_bounce_game/NetHighScoreManager.cpp
    ball_bounce_game/NetHighScoreManager.hpp
    ball_bounce_game/Paddle.cpp
    ball_bounce_game/Paddle.hpp
    )

target_link_libraries(
    ball_bounce_game
    ${SDL_LIBS}
    spritelib
)

set_target_properties(ball_bounce_game PROPERTIES
    VS_DEBUGGER_ENVIRONMENT
    "PATH=${CMAKE_SOURCE_DIR}/3rdParty/SDL3-3.4.2/lib/x64/;${CMAKE_SOURCE_DIR}/3rdParty/SDL3_ttf-3.2.2/lib/x64/;${CMAKE_SOURCE_DIR}/3rdParty/SDL3_net-3.2.0/lib/x64/;${CMAKE_SOURCE_DIR}/3rdParty/SDL3_image-3.4.4/lib/x64/;%PATH%"
)

add_executable(pong_client
    pong_client/Main.cpp

    pong_client/App.cpp
    pong_client/App.hpp
    pong_client/Ball.cpp
    pong_client/Ball.hpp
    pong_client/NetworkManager.cpp
    pong_client/NetworkManager.hpp
    pong_client/Paddle.cpp
    pong_client/Paddle.hpp
    )

target_link_libraries(
    pong_client
    ${SDL_LIBS}
    spritelib
)

set_target_properties(pong_client PROPERTIES
    VS_DEBUGGER_ENVIRONMENT
    "PATH=${CMAKE_SOURCE_DIR}/3rdParty/SDL3-3.4.2/lib/x64/;${CMAKE_SOURCE_DIR}/3rdParty/SDL3_ttf-3.2.2/lib/x64/;${CMAKE_SOURCE_DIR}/3rdParty/SDL3_net-3.2.0/lib/x64/;${CMAKE_SOURCE_DIR}/3rdParty/SDL3_image-3.4.4/lib/x64/;%PATH%"
)

add_executable(pong_server
    pong_server/Main.cpp

    pong_server/App.cpp
    pong_server/App.hpp
    pong_server/Ball.cpp
    pong_server/Ball.hpp
    pong_server/NetworkManager.cpp
    pong_server/NetworkManager.hpp
    pong_server/Paddle.cpp
    pong_server/Paddle.hpp
    pong_server/PlayerPaddle.cpp
    pong_server/PlayerPaddle.hpp
    pong_server/RemotePaddle.cpp
    pong_server/RemotePaddle.hpp
    )

target_link_libraries(
    pong_server
    ${SDL_LIBS}
    spritelib
)

set_target_properties(pong_server PROPERTIES
    VS_DEBUGGER_ENVIRONMENT
    "PATH=${CMAKE_SOURCE_DIR}/3rdParty/SDL3-3.4.2/lib/x64/;${CMAKE_SOURCE_DIR}/3rdParty/SDL3_ttf-3.2.2/lib/x64/;${CMAKE_SOURCE_DIR}/3rdParty/SDL3_net-3.2.0/lib/x64/;${CMAKE_SOURCE_DIR}/3rdParty/SDL3_image-3.4.4/lib/x64/;%PATH%"
)