#ifndef GAME_UTILITY_HPP
#define GAME_UTILITY_HPP

#include <chrono>
#include <cmath>
#include <functional>
#include <thread>

/* Simple class which executes stored function only on
 * interval start. Bounds number of executions from above
 * and incapsulates all chrono-based logic*/
template <typename F>
class Timer {
    using clock = std::chrono::steady_clock;
    static const size_t second = 1000000;  // US in second

private:
    F function;
    std::chrono::microseconds duration;
    std::chrono::time_point<clock> deadline;

    void update_deadline() {
        if (clock::now() > deadline)
            deadline += duration * ((clock::now() - deadline) / duration + 1);
        std::this_thread::sleep_until(deadline);
    }

public:
    explicit Timer(F func, const size_t ticks = 30)
            : function(func),
              duration(second / ticks),
              deadline(clock::now()) {}

    // TODO(mocurin): use std::invoke_result
    template <typename... Args>
    void operator()(Args&&... params) {
        update_deadline();
        std::invoke(function,
                    std::forward<Args>(params)...);
    }

    void set_ticks(const size_t ticks) {
        duration = second / ticks;
        deadline = clock::now();
    }
};

#endif //GAME_UTILITY_HPP
