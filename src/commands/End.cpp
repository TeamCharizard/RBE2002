#include "End.h"
#include "../main.hpp"

End::End() : Command("END!!!"){}

void End::initialize(){
}

void End::execute(){}

bool End::isFinished(){
  return true;
}

void End::end(){
  debugPrint(1,"COMPLETE.");
}
