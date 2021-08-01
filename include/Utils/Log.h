#ifndef _UTILS_LOG_H
#define _UTILS_LOG_H

#include <iostream>

namespace toy {
template <class... Args> void Debugf(Args... args) {
  std::cout << "debug: ";
  (std::cout << ... << args) << "\n";
}

template <class... Args> void Infof(Args... args) {
  std::cout << "info: ";
  (std::cout << ... << args) << "\n";
}

template <class... Args> void Warnf(Args... args) {
  std::cout << "warn: ";
  (std::cout << ... << args) << "\n";
}

template <class... Args> void Errorf(Args... args) {
  std::cout << "error: ";
  (std::cout << ... << args) << "\n";
}
} // namespace toy

#endif
