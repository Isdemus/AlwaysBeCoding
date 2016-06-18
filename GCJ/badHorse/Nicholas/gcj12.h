#include <iostream>
#include <map>
#include <vector>

class player;
static std::map<std::string, player*> ladder;

class player {
  public:
    player()
      : enmy_count(0), member_name("default"), enemies(nullptr), color("default") {};

    player(std::string name)
      : enmy_count(0), member_name(name), enemies(nullptr), color("default") {
      ladder[name] = this;
    };

    void set_color(std::string givenColor) {
      color = givenColor;
    }
    void add_enemy(std::string enemy_name);
    void print_enemies();
    std::string print_color() {
      return color;
    }
    unsigned int print_enmy_count() {
      return enmy_count;
    }
    std::string print_member_name() {
      return member_name;
    }
    std::vector<player*>* get_enemies() {
      return enemies;
    }

  private:
    unsigned int enmy_count;
    std::string member_name;
    std::vector<player*>* enemies;
    std::string color;
};

void print(player* enemy) {
  std::cout << "\t" + enemy->print_member_name() + " : " + enemy->print_color() + "\n";
}
