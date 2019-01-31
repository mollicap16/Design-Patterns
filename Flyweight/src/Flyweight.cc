#include <Flyweight.h>
#include <string.h>

Icon::Icon(const char *file_name){
  strcpy(name_, file_name);
  if (!strcmp(file_name, "go")){
    width_ = 20;
    height_ = 20;
  }
  if (!strcmp(file_name, "stop")){
    width_ = 40;
    height_ = 40;
  }
  if (!strcmp(file_name, "select")){
    width_ = 60;
    height_ = 60;
  }
  if (!strcmp(file_name, "undo")){
    width_ = 30;
    height_ = 30;
  }
}


void Icon::Draw(int32_t x, int32_t y){
  std::cout << "  drawing " << name_ << ": upper left (" << x << "," << y <<
               ") - lower right (" << x + width_ << "," << y + height_ << ")" << std::endl;
}

Icon* FlyweightFactory::GetIcon(const char *name){
  for (int32_t i = 0; i < num_icons_; ++i)
    if (!strcmp(name, icons_[i]->GetName()))
      return icons_[i];

  icons_[num_icons_] = new Icon(name);
  return icons_[num_icons_++];
}

void FlyweightFactory::ReportTheIcons(){
  std::cout << "Active Flyweights: ";
  for (int32_t i = 0; i < num_icons_; ++i)
    std::cout << icons_[i]->GetName() << " ";

  std::cout << std::endl;
}

FileSelection::FileSelection(Icon *first, Icon *second, Icon *third) : DialogBox(100, 100, 100) {
  icons_[0] = first;
  icons_[1] = second;
  icons_[2] = third;
}

void FileSelection::Draw() {
  std::cout << "Drawing FileSelection: " << std::endl;
  for (int32_t i = 0; i < 3; ++i)
    icons_[i]->Draw(icons_origin_x_ + (i* icons_origin_increment_), icons_origin_y_ );
}

CommitTransation::CommitTransation(Icon *first, Icon *second, Icon *third) : DialogBox(150, 150, 150) {
  icons_[0] = first;
  icons_[1] = second;
  icons_[2] = third;
}

void CommitTransation::Draw() {
  std::cout << "Drawing CommitTransaction: " << std::endl;
  for (int32_t i = 0; i < 3; ++i)
    icons_[i]->Draw(icons_origin_x_ + (i*icons_origin_increment_), icons_origin_y_);
}
