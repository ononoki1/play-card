#include "parameter.h"
#include <algorithm>
#include <ctime>
#include <iostream>

bool number_compare(int x, int y);
bool priority_compare(int x, int y);
void put_message();
void put_change();
void choose_card(bool is_me, int begin);
void me_card_put_name();
void enemy_put_card_put_name(const int *put_card, int real_number);
int me_put_card(int *put_card);
int enemy_put_card_number(int *high_defend);
int enemy_put_card(int *put_card, int number, int high_defend);
void me_card_effect(const int *put_card, int number);
void enemy_card_effect(const int *put_card, int real_number);

void init();
void me_play_card();
void enemy_play_card();
void play();

int main() {
  e.seed(time(nullptr));
  init();
  play();
  return 0;
}

void init() {
  int i;
  for (i = 0; i < all_card; i++)
    resource[i].init(i);
  for (i = 0; i < me_max_card; i++)
    me_card[i] = -1;
  for (i = 0; i < enemy_max_card; i++)
    enemy_card[i] = -1;
  cout << "来打牌吧！" << endl;
  cout << "敲键盘以开始......" << endl;
  system("read -s -n 1");
  cout << endl;
}

void me_play_card() {
  int put_card[me_card_number];
  choose_card(true, me_save);
  me_card_put_name();
  int number = me_put_card(put_card);
  me_card_effect(put_card, number);
  sort(me_card, me_card + me_max_card, number_compare);
  if (me_blood > me_max_blood)
    me_blood = me_max_blood;
  if (me_more_card) {
    me_save = me_max_card - number;
    me_more_card = false;
  } else
    me_save += due_me_card_number - number;
  me_card_number = me_save + due_me_card_number;
  if (me_card_number > me_max_card) {
    me_card_number = me_max_card;
    me_more_card = true;
  }
}
void enemy_play_card() {
  int high_defend;
  choose_card(false, enemy_card_number - due_enemy_card_number);
  int number = enemy_put_card_number(&high_defend), put_card[number];
  int real_number = enemy_put_card(put_card, number, high_defend);
  enemy_put_card_put_name(put_card, real_number);
  enemy_card_effect(put_card, real_number);
  sort(enemy_card, enemy_card + enemy_max_card, number_compare);
  enemy_card_number -= real_number;
  cout << "敌方剩余手牌" << enemy_card_number << "张。" << endl;
  enemy_card_number += due_enemy_card_number;
}

void play() {
  while (true) {
    put_message();
    before_me_blood = me_blood;
    before_enemy_blood = enemy_blood;
    before_me_magic = me_magic;
    before_enemy_magic = enemy_magic;
    me_play_card();
    cout << endl;
    if (enemy_blood <= 0) {
      cout << "你赢了！" << endl << endl;
      break;
    }
    enemy_play_card();
    cout << endl;
    if (me_blood <= 0) {
      cout << "你输了！" << endl << endl;
      break;
    }
    turn++;
    put_change();
    cout << "敲键盘以继续......" << endl;
    system("read -s -n 1");
    cout << endl;
  }
  cout << "敲键盘以退出......" << endl;
  system("read -s -n 1");
}