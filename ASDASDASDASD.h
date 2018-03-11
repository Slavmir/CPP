std::cout.unsetf(std::ios::floatfield);
std::cout.precision(9);
std::cout.setf(std::ios::fixed, std::ios::floatfield);


s = std::chrono::high_resolution_clock::now().time_since_epoch().count();