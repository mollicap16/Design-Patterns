#include <ImageProxy.h>

int32_t Image::s_next_= 1;

RealImage::RealImage(int32_t id) : image_id_(id) {
  std::cout << " $$ ctor: " << image_id_ << std::endl;
}

RealImage::~RealImage(){
  std::cout << "  dtor: " << image_id_ << std::endl;
}


void RealImage::Draw(){
  std::cout << " Drawing Image " << image_id_ << std::endl;
}

// 3. Initialize real class to null
Image::Image() : image_(nullptr) {
  image_id_ = s_next_++;
}

Image::~Image(){
  delete image_;
}

void Image::Draw(){
  // 4. When a request comes in the real object is created "on first use"
  if (!image_)
    image_ = new RealImage(image_id_);

  image_->Draw();
}
