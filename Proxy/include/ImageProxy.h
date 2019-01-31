#ifndef IMAGEPROXY_H
#define IMAGEPROXY_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/proxy/cpp/1

#include <iostream>
/***************************************************************************************
 * Proxy Design Pattern Properties:
 *    1. Design an "extra level of indirection" wrapper class
 *    2. The wrapper class holds a pointer to the real class
 *    3. The pointer is initialized to null
 *    4. When a request comes in, the real object is created "on first use"
 *       (aka Lazy Initialization).
 *    5. The request is always delegated.
 *
 **************************************************************************************/

class RealImage {
public:
  RealImage(int32_t id);
  ~RealImage();

  void Draw();

private:
  int32_t image_id_;
};

// 1. Design an "extra level of indirection" (proxy)
class Image {
public:
  Image();
  ~Image();

  void Draw();

private:
  // 2. The wrapper class holds a pointer to the real class
  RealImage* image_;
  int32_t image_id_;
  static int32_t s_next_;
};

#endif //IMAGEPROXY_H
