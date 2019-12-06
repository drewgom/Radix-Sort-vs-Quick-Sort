// Name: Andrew Gomez
// Class: CECS328
// Project: Project 4

#include "Timer.hpp"

Timer::Timer()  {
    // There is no such thing as a "0" chrono time_point. However,
    // There is a minimum value that essentially will act as zero.
    // This also will work becuase whenever start_time and end_time
    // are set to the minimum value, then the time in between those
    // trials will be zero, becuase they are the same thing.
    start_time = std::chrono::high_resolution_clock::time_point::min();
    end_time = std::chrono::high_resolution_clock::time_point::min();
    elapsed_time_between_trials = 0;
}

// Allows us to start keeping track of the time
void Timer::start_timer()    {
    start_time = std::chrono::high_resolution_clock::now();
}


// Allows us to stop keeping track of the time
void Timer::stop_timer()     {
    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time_between_trials = elapsed_time_between_trials + std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count();
    
}

// Allows us to reset our timer to zero
void Timer::reset_timer()    {
    // This works just like the constructor - it sets everything to zero.
    start_time = std::chrono::high_resolution_clock::time_point::min();
    end_time = std::chrono::high_resolution_clock::time_point::min();
    elapsed_time_between_trials = 0;
}

// Allows us to see the amount of time that has elapsed
double Timer::get_time()        { return elapsed_time_between_trials; }
