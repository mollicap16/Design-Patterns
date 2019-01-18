#include <Builder.h>

/******************************************************************************
 * DistributionWorkPackage functions
 *****************************************************************************/
DistributionWorkPackage::DistributionWorkPackage(char const* type){
  sprintf(desc_, "Distributed Work Package for: %s", type);
}

void DistributionWorkPackage::SetFile(char const* file, char const* v){
  sprintf(temp_, "\n  File(%s): %s", file, v);
  strcat(desc_, temp_);
}

void DistributionWorkPackage::SetQueue(char const* queue, char const* v){
  sprintf(temp_, "\n  Queue(%s): %s", queue, v);
  strcat(desc_, temp_);
}

void DistributionWorkPackage::SetPathway(char const* pathway, char const* v){
  sprintf(temp_, "\n  Pathway(%s): %s", pathway, v);
  strcat(desc_, temp_);
}


/******************************************************************************
 * Builders
 *****************************************************************************/
UnixBuilder::UnixBuilder() {
  result_ = new DistributionWorkPackage("Unix");
}

void UnixBuilder::ConfigureFile(char *name){
  result_->SetFile("FlatFile", name);
}

void UnixBuilder::ConfigureQueue(char *queue){
  result_->SetQueue("FIFO", queue);
}

void UnixBuilder::ConfigurePathway(char *type){
  result_->SetPathway("thread", type);
}

VmsBuilder::VmsBuilder(){
  result_ = new DistributionWorkPackage("Vms");
}

void VmsBuilder::ConfigureFile(char *name){
  result_->SetFile("ISAM", name);
}

void VmsBuilder::ConfigureQueue(char *queue){
  result_->SetQueue("priority", queue);
}

void VmsBuilder::ConfigurePathway(char *type){
  result_->SetPathway("LWP", type);
}

/******************************************************************************
 * Reader
 *****************************************************************************/
void Reader::SetBuilder(Builder *build){
  builder_ = build;
}

void Reader::Construct(PersistenceAttribute list[], int32_t number){
  for (int32_t i=0; i < number; ++i){
    if(list[i].type == PersistenceType::File){
      builder_->ConfigureFile(list[i].value);
    }
    else if (list[i].type == PersistenceType::Queue){
      builder_->ConfigureQueue(list[i].value);
    }
    else if (list[i].type == PersistenceType::Pathway){
      builder_->ConfigurePathway(list[i].value);
    }
  }
}
