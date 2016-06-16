#include <iostream>
using namespace std;

typedef class player {
  public:
    player()
      : name("def"), enemies(nullptr) {};
    player(string name1, player &name2)
      : name(name1), enemies(&name2) {};
    string getName();
    void addEnemy(string name);
    void printEnemies();

  private:
    string name;
    player* enemies;
} Player;
