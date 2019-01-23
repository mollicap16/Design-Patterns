#ifndef PROTOTYPE_H
#define PROTOTYPE_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/prototype/cpp/3

#include <iostream>

enum ImageType{
  LSAT,
  SPOT
};

// Abstract base class (Prototype)
class Image {
public:
  virtual void Draw()=0;
  static Image* FindAndClone(ImageType);
  virtual ~Image(){}

protected:
  virtual ImageType ReturnType()=0;
  virtual Image* Clone()=0;

  // As each subclass of Image is declared, it register its prototype
  static void AddPrototype(Image* image);
private:
  // AddPrototype() saves each registered prototype here
  static Image* prototypes_[10];  // limiting the number of clones to 10
  static int32_t next_slot_;
};

// Concrete class
class LandSatImage: public Image {
public:
  ImageType ReturnType() {return LSAT;}
  void Draw();
  Image* Clone();

protected:
  // This is only called from clone
  LandSatImage(int32_t);

private:
  // This is only called when the private static data member is initiated
  LandSatImage();


  // Mechanism for initializing an Image subclass - this causes the
  // default contstructor to be called, which registers the subclass's prototype
  static LandSatImage land_sat_image_;

  int32_t id_;
  static int32_t count_;
};

// Concrete class
class SpotImage: Image {
public:
  ImageType ReturnType() {return SPOT;}
  void Draw();
  Image* Clone();

protected:
  SpotImage(int32_t);

private:
  SpotImage();

  static SpotImage spot_image_;
  int32_t id_;
  static int32_t count_;
};

#endif //PROTOTYPE_H
