#include <Prototype.h>

Image* Image::FindAndClone(ImageType type){
  for (int32_t i=0; i < next_slot_; ++i){
    if (prototypes_[i]->ReturnType() == type)
      return prototypes_[i]->Clone();
  }

  return nullptr;
}

void Image::AddPrototype(Image *image){
  prototypes_[next_slot_++] = image;
}

// Set the id for the new image and increment the count, when clone is called
LandSatImage::LandSatImage(int32_t){
  id_ = count_++;
}

LandSatImage::LandSatImage(){
  AddPrototype(this);
}

void LandSatImage::Draw(){
  std::cout << "LandSatImage::Draw() " << id_ << std::endl;
}

Image* LandSatImage::Clone(){
  return new LandSatImage(1);
}


SpotImage::SpotImage(int32_t){
  id_ = count_++;
}

SpotImage::SpotImage(){
  AddPrototype(this);
}

void SpotImage::Draw(){
  std::cout << "SpotImage::Draw() " << id_ << std::endl;
}

Image* SpotImage::Clone(){
  return new SpotImage(1);
}
