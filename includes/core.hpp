#ifndef GAME_CORE_HPP
#define GAME_CORE_HPP

#include <thread>

#include "utility.hpp"

class Game {
    enum class state {
        QUIT, PLAY, PAUSE
    } current_state;

public:
    // Execution scenario
    void run();

    // Updates all game logic
    void update() {
    }

    // Plays scheduled sounds
    void audio() {
    }

    // Renders everything
    void render() {
    }

    // Exhausts input queue
    void input() {
    }
};

#endif //GAME_CORE_HPP
