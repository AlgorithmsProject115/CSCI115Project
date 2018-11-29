#ifndef PROFILE_H
#define PROFILE_H

#include <chrono>
#include <algorithm>

/**
 * Profiles the runtime a function.
 * 
 * @param func function of any return type accepting args as arguments.
 * @param args variable number of arguments to be passed into func.
 * @returns the runtime of func when called with arguments args in microseconds.
 */ 
template <typename F, typename ... Args>
std::chrono::microseconds profile(F&& func, Args&&... args)
{
    const auto start = std::chrono::high_resolution_clock::now();
    std::forward<F>(func)(std::forward<Args>(args)...);
    const auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}

#endif