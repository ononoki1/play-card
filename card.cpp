#include "card.h"
#include <cstring>
#include <iostream>
using namespace std;

void card::init(int option) {
  switch (option) {
  case 0:
    strcpy(name, "1级攻击");
    type = 1;
    hurt = 1;
    chance = 40;
    priority = 1;
    break;
  case 1:
    strcpy(name, "1级防御");
    type = 2;
    possibility = 30;
    chance = 30;
    break;
  case 2:
    strcpy(name, "1级回血");
    type = 3;
    hurt = 1;
    chance = 10;
    break;
  case 3:
    strcpy(name, "2级攻击");
    type = 1;
    hurt = 2;
    chance = 25;
    priority = 2;
    break;
  case 4:
    strcpy(name, "2级防御");
    type = 2;
    possibility = 70;
    chance = 15;
    break;
  case 5:
    strcpy(name, "2级回血");
    type = 3;
    hurt = 2;
    chance = 5;
    break;
  case 6:
    strcpy(name, "3级攻击");
    type = 1;
    hurt = 3;
    chance = 10;
    priority = 3;
    break;
  case 7:
    strcpy(name, "3级防御");
    type = 2;
    possibility = 100;
    chance = 5;
    break;
  case 8:
    strcpy(name, "3级回血");
    type = 3;
    hurt = 3;
    chance = 2;
    break;
  case 9:
    strcpy(name, "精神增幅");
    type = 4;
    cost = 2;
    chance = 15;
    break;
  case 10:
    strcpy(name, "火球术");
    type = 5;
    hurt = 4;
    cost = 2;
    chance = 10;
    priority = 2;
    break;
  case 11:
    strcpy(name, "雷暴");
    type = 5;
    hurt = 6;
    cost = 3;
    chance = 5;
    priority = 1;
    break;
  }
}
void card::put_name() { cout << name; }
int card::get_type() { return type; }
int card::get_hurt() { return hurt; }
int card::get_cost() { return cost; }
int card::get_possibility() { return possibility; }
int card::get_chance() { return chance; }
int card::get_priority() { return priority; }