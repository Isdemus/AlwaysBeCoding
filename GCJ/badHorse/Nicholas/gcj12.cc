/*
Google Code Jam Entrance Test
(Bad Horse: https://code.google.com/codejam/contest/2933486/dashboard)

Used Algorithm Method: Logic + OOP + Depth First Search Algorithm
Re-Coded by isdemus (June 18 2016)
*/

#include "gcj12.h"
#define print_vector(vec) for(unsigned int i=0; i<vec->size(); i++)

typedef unsigned int ui;

// Assuming that no same enemy_name will be given
void player::add_enemy(std::string enemy_name) {
  if (ladder[enemy_name] == nullptr) {
    player* enemy_tmp = new player(enemy_name);
  }

  if (enemies == nullptr) {
    enemies = new std::vector<player*>();
    enemies->push_back(ladder[enemy_name]);
  } else {
    enemies->push_back(ladder[enemy_name]);
  }

  enmy_count += 1;
}

void player::print_enemies() {
  if (enmy_count > 0) {
    print_vector(enemies) 
      std:: cout << (enemies->at(i))->print_member_name() << std::endl;
  } else {
    std::cout << "No enemy" << std::endl;
  }
}

bool valid_enemies(std::string name, std::string name2) {
  std::string newColor, currentColor;

  if (ladder[name] == nullptr) {
    std::cerr << "Error in valid_enemies" << std::endl;
    exit(0);
  } else if (ladder[name]->print_color() == "default") {
    for ( auto person : *(ladder[name]->get_enemies()) ) {
      if (person->print_color() != "default") {
        newColor = person->print_color();      
      }
    }

    if (newColor == "White") {
      currentColor = "Black";
    } else if (newColor == "Black") {
      currentColor = "White";
    } else {
      currentColor = "White";
      newColor = "Black";
    }

  } else if(ladder[name]->print_color() == "White") {
    currentColor = "White";
    newColor = "Black";
  } else {
    currentColor = "Black";
    newColor = "White";
  }
  
  for ( auto person : *(ladder[name]->get_enemies()) ) {
    if (person->print_color() == currentColor)
      return false;
    else if (person->print_color() == "default")
      person->set_color(newColor);
    else 
      continue;

    if (person->print_enmy_count())
      if (!valid_enemies(person->print_member_name(), name))
        return false;
  }

  return true;
}

int main(int argc, char* argv[]) {
  ui cases;
  std::cin >> cases;

  for (ui c=1; c<=cases; c++) {
    std::string answer = "Yes";
    std::string name1, name2;
    std::vector<std::string> league_members;
    ladder.clear();

    ui numNames;
    std::cin >> numNames;

    for (ui i=0; i<numNames; i++) {
      std::cin >> name1 >> name2;
      if (ladder[name1] == nullptr && ladder[name2] == nullptr) {
        player* tmp = new player(name1);
        league_members.push_back(name1);
        league_members.push_back(name2);
      } else if (ladder[name1] == nullptr) {
        player* tmp = new player(name1);
        league_members.push_back(name1);
      } else if (ladder[name2] == nullptr) {
        player* tmp = new player(name2);
        league_members.push_back(name2);
      }

      ladder[name1]->add_enemy(name2);
      ladder[name2]->add_enemy(name1);
    }

    // Checking if the division's valid
    for (std::string name : league_members) { 
      if ( !valid_enemies(name, "") ) {
        answer = "No";
      } 
    }

/*
    for (std::string name : league_members) {
      std::cout << "Name: " << name << 
          " Color: " << ladder[name]->print_color() << std::endl;
      for ( auto play : *(ladder[name]->get_enemies()) ) {
        print(play);
      }
      std::cout << std::endl;
    }
*/

    std::printf("Case #%d: %s\n", c, answer.c_str());
  } 

  return 0;
}
