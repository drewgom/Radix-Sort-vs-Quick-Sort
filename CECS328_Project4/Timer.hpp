// Name: Andrew Gomez
// Class: CECS328
// Project: Project 4

#ifndef Timer_hpp
#define Timer_hpp

#include <chrono>

using namespace std;
// This class will allow us to see the amount of time that
// has passed from start time to stop time.
// This will be helpful when we want to see how the input
// size effects the runtime of the program.

// I chose to use the chrono sub-namespace becuase it would allow
// me to record time in milliseconds. The syntax for chrono is very ugly,
// So that is why I chose to put all of its fucntionality in to a class.

class Timer     {
private:
    // Saves the elapsed time in nanoseconds. C++ will
    // let us get the current time - so if we get the current
    // start time and the current end time, then we know the
    // elapsed time is the difference between the two. If we
    // stop a clock and then start it again, then we also need
    // to be able to store the time from that previous session.
    double elapsed_time_between_trials;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
public:
    Timer();
    void start_timer();
    void stop_timer();
    void reset_timer();
    double get_time();
};

#endif
