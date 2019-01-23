#include <iostream>
#include <gtest/gtest.h>
#include <Prototype.h>

// Register the prototypes
Image* Image::prototypes_[];
int32_t Image::next_slot_;

// Register the Land Sat Image concrete class's prototype and count
LandSatImage LandSatImage::land_sat_image_;
int32_t LandSatImage::count_ = 1;

// Register the Spot Image concrete class's prototype and count
SpotImage SpotImage::spot_image_;
int32_t SpotImage::count_ = 1;

const int32_t kNumImages=8;
ImageType input[kNumImages] = {LSAT, LSAT, LSAT, SPOT, LSAT, SPOT, SPOT, LSAT};

TEST(PrototypeTest, PrototypeTest1){
  Image* images[kNumImages];

  // Given an image type, find the right prototype and return a clone.
  for (int32_t i = 0; i < kNumImages; ++i)
    images[i] = Image::FindAndClone(input[i]);

  // Demonstrate that the correct image objects have been cloned
  for (int32_t i = 0; i < kNumImages; ++i)
    images[i]->Draw();

  // Free the dynamic memory
  for (int32_t i = 0; i < kNumImages; ++i)
    delete images[i];
}

TEST(PrototypeTest, PrototypeBeforeAfterTest1){
// NOTE: We might want to delete this test
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
