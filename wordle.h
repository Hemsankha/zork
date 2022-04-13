#ifndef WORDLE_H
#define WORDLE_H
#include "Parser.h"
namespace x{

class wordle
{
private:
    string txtFile;
    friend class ZorkUL;
public:
    wordle();
  void  reader();
  int game(Command command);
   void wordArray(string j, vector<string> s);

  // ~wordle(){string txt;};
};
}
#endif // WORDLE_H
