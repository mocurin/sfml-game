#include "core.hpp"

void Game::run() {
    std::thread logic_thread([this](){
        Timer do_logic([this]() {
            update();
        }, 30);
        while (current_state != state::QUIT) {
            do_logic();
        }
    });
    Timer do_interaction([this]() {
        input();
        render();
        audio();
    }, 60);
    while (current_state != state::QUIT) {
        do_interaction();
    }
    logic_thread.join();
}
