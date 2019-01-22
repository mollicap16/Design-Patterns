#include <FactoryMethodApplication.h>

void MyDocument::Open() {
  std::cout << " MyDocument: Open()" << std::endl;
}

void MyDocument::Close() {
  std::cout << " MyDocument: Close()" << std::endl;
}


Application::Application() : index_(0) {
  std::cout << "Application: ctor" << std::endl;
}

void Application::NewDocument(char const * name) {
  std::cout << "Application: NewDocument()" << std::endl;

  // Framework calls the "hole" reserved for client customization
  docs_[index_] = CreateDocument(name);
  docs_[index_++]->Open();
}

void Application::ReportDocs() {
  std::cout << "Application: ReportDocs()" << std::endl;
  for (int32_t i=0; i < index_; ++i){
    std::cout << " " << docs_[i]->GetName() << std::endl;
  }
}

MyApplication::MyApplication() {
  std::cout << "MyApplication: ctor:" << std::endl;
}

// Factory Method
Document* MyApplication::CreateDocument(char const * fn) {
  std::cout << " MyApplication: CreateDocument()" << std::endl;
  return new MyDocument(fn);
}
