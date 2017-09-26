
#include <iostream>

#define X_STATE_LIST \
  X(Connected)\
  X(Disconnected)\
  X(Error)


#define X(name) name,
enum State {
  X_STATE_LIST
};
#undef X


const char* str(State s) {
  #define X(name) case(name): return #name;
  switch(s) {
    X_STATE_LIST
    default: return "Unknown";
  }
  #undef X
}

int main() {
  State s = Error;
  std::cout << str(s) << "\n";
}
