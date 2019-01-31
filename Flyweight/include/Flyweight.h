#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

// NOTE: This example is from https://sourcemaking.com/design_patterns/flyweight/cpp/2

#include <iostream>

class Icon {
public:
  Icon(const char * file_name);

  const char* GetName() {return name_;}
  void Draw(int32_t x, int32_t y);

private:
  char name_[20];
  int32_t width_;
  int32_t height_;
};

class FlyweightFactory {
public:
  static Icon* GetIcon(const char* name);
  static void ReportTheIcons();

private:
  enum {kMaxIcons = 5};

  static int32_t num_icons_;
  static Icon* icons_[kMaxIcons];
};

class DialogBox {
public:
  DialogBox(int32_t x, int32_t y, int32_t increment)
    : icons_origin_x_(x), icons_origin_y_(y), icons_origin_increment_(increment) {}
  virtual void Draw()=0;

protected:
  Icon* icons_[3];
  int32_t icons_origin_x_;
  int32_t icons_origin_y_;
  int32_t icons_origin_increment_;
};

class FileSelection: public DialogBox {
public:
  FileSelection(Icon* first, Icon* second, Icon* third);
  void Draw();
};

class CommitTransation: public DialogBox {
public:
  CommitTransation(Icon* first, Icon* second, Icon* third);
  void Draw();
};

#endif //FLYWEIGHT_H
