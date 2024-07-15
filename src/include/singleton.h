#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>

template <typename T>
class Singleton {
 public:
  static T& get_instance() noexcept(std::is_nothrow_constructible<T>::value) {
    static T get_instance{token()};
    return get_instance;
  }
  virtual ~Singleton() = default;
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

 protected:
  struct token {};  // helper class
  Singleton() noexcept = default;
};

#endif  //__SINGLETON_H__
