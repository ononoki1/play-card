#include "parameter.h"
#include <algorithm>
#include <iostream>

bool number_compare(int x, int y) { return x > y; }
bool priority_compare(int x, int y) {
  return resource[enemy_card[x]].get_priority() <
         resource[enemy_card[y]].get_priority();
}

void put_message() {
  cout << "第" << turn << "回合：" << endl;
  cout << "你的血量是" << me_blood << "，"
       << "法力是" << me_magic << "；" << endl;
  cout << "敌方血量是" << enemy_blood << "，"
       << "法力是" << enemy_magic << "。" << endl;
  cout << endl;
}
void put_change() {
  if (me_blood < before_me_blood)
    cout << "本回合你的血量减少" << before_me_blood - me_blood << "，";
  else if (me_blood > before_me_blood)
    cout << "本回合你的血量增加" << me_blood - before_me_blood << "，";
  else
    cout << "本回合你的血量不变，";
  if (me_magic < before_me_magic)
    cout << "法力减少" << before_me_magic - me_magic << "；" << endl;
  else if (me_magic > before_me_magic)
    cout << "法力增加" << me_magic - before_me_magic << "；" << endl;
  else
    cout << "法力不变；" << endl;
  if (enemy_blood < before_enemy_blood)
    cout << "敌方血量减少" << before_enemy_blood - enemy_blood << "，";
  else if (enemy_blood > before_enemy_blood)
    cout << "敌方血量增加" << enemy_blood - before_enemy_blood << "，";
  else
    cout << "敌方血量不变，";
  if (enemy_magic < before_enemy_magic)
    cout << "法力减少" << before_enemy_magic - enemy_magic << "。" << endl;
  else if (enemy_magic > before_enemy_magic)
    cout << "法力增加" << enemy_magic - before_enemy_magic << "。" << endl;
  else
    cout << "法力不变。" << endl;
  cout << endl;
}

void choose_card(bool is_me, int begin) {
  int i = a(e), k = 0;
  if (is_me) {
    while (k < due_me_card_number && k + begin < me_max_card) {
      if (b(e) < resource[i].get_chance()) {
        me_card[k + begin] = i;
        k++;
      }
      i = a(e);
    }
  } else {
    while (k < due_enemy_card_number && k + begin < enemy_max_card) {
      if (b(e) < resource[i].get_chance()) {
        enemy_card[k + begin] = i;
        k++;
      }
      i = a(e);
    }
  }
}

void me_card_put_name() {
  int i = 0;
  cout << "你的牌是：";
  while (i != me_card_number) {
    cout << "(" << i + 1 << ")";
    resource[me_card[i]].put_name();
    i++;
    if (i != me_card_number)
      cout << "，";
    else
      cout << "。" << endl;
  }
}
void enemy_put_card_put_name(const int *put_card, int real_number) {
  int i = 0;
  cout << "敌方出牌是：";
  while (i != real_number) {
    resource[enemy_card[put_card[i]]].put_name();
    i++;
    if (i != real_number)
      cout << "，";
    else
      cout << "。" << endl;
  }
}

int me_put_card(int *put_card) {
  int i, number, magic = me_magic;
  cout << "你出牌的张数是：";
  cin >> number;
  while (number > me_card_number || number < 0) {
    cout << "输入错误！" << endl;
    cout << "你出牌的张数是：";
    fflush(stdin);
    cin >> number;
  }
  if (number) {
    int rein = 0, j;
    cout << "你的出牌是：";
    fflush(stdin);
    for (i = 0; i < number; i++) {
      cin >> put_card[i];
      put_card[i]--;
      if (put_card[i] < 0 || put_card[i] >= me_card_number) {
        rein = 1;
        break;
      }
      for (j = 0; j < i; j++) {
        if (put_card[j] == put_card[i]) {
          rein = 1;
          break;
        }
      }
      if (rein)
        break;
      if (resource[me_card[put_card[i]]].get_type() == 4)
        magic += resource[me_card[put_card[i]]].get_cost();
      if (resource[me_card[put_card[i]]].get_type() == 5) {
        magic -= resource[me_card[put_card[i]]].get_cost();
        if (magic < 0) {
          rein = 2;
          break;
        }
      }
    }
    while (rein) {
      if (rein == 1)
        cout << "输入错误！" << endl;
      else
        cout << "法力不足！" << endl;
      rein = 0;
      magic = me_magic;
      cout << "你出牌的张数是：";
      fflush(stdin);
      cin >> number;
      while (number > me_card_number || number < 0) {
        cout << "输入错误！" << endl;
        cout << "你出牌的张数是：";
        fflush(stdin);
        cin >> number;
      }
      if (number) {
        cout << "你的出牌是：";
        fflush(stdin);
        for (i = 0; i < number; i++) {
          cin >> put_card[i];
          put_card[i]--;
          if (put_card[i] < 0 || put_card[i] >= me_card_number) {
            rein = 1;
            break;
          }
          for (j = 0; j < i; j++) {
            if (put_card[j] == put_card[i]) {
              rein = 1;
              break;
            }
          }
          if (rein)
            break;
          if (resource[me_card[put_card[i]]].get_type() == 4)
            magic += resource[me_card[put_card[i]]].get_cost();
          if (resource[me_card[put_card[i]]].get_type() == 5) {
            magic -= resource[me_card[put_card[i]]].get_cost();
            if (magic < 0) {
              rein = 2;
              break;
            }
          }
        }
      }
    }
  }
  return number;
}
int enemy_put_card_number(int *high_defend) {
  int i, number = enemy_card_number, defend_level = 0;
  *high_defend = -1;
  cout << "敌方手牌共" << enemy_card_number << "张。" << endl;
  for (i = 0; i < enemy_card_number; i++) {
    if (resource[enemy_card[i]].get_type() == 2) {
      number--;
      if (resource[enemy_card[i]].get_possibility() > defend_level) {
        *high_defend = i;
        defend_level = resource[enemy_card[i]].get_possibility();
      }
    }
  }
  if (number != enemy_card_number)
    number++;
  return number;
}
int enemy_put_card(int *put_card, int number, int high_defend) {
  int i, real_number = 0, magic = enemy_magic;
  for (i = 0; i < enemy_card_number; i++) {
    if (resource[enemy_card[i]].get_type() != 2 || i == high_defend) {
      put_card[real_number] = i;
      real_number++;
    }
  }
  sort(put_card, put_card + number, priority_compare);
  i = 0, real_number = number;
  while (i != number) {
    switch (resource[enemy_card[put_card[i]]].get_type()) {
    case 4:
      magic += resource[enemy_card[put_card[i]]].get_cost();
      break;
    case 5:
      magic -= resource[enemy_card[put_card[i]]].get_cost();
      if (magic < 0) {
        put_card[i] = -1;
        magic += resource[enemy_card[put_card[i]]].get_cost();
        real_number--;
      }
      break;
    }
    i++;
  }
  sort(put_card, put_card + number, number_compare);
  sort(put_card, put_card + real_number, priority_compare);
  return real_number;
}

void me_card_effect(const int *put_card, int number) {
  int i = 0;
  while (i != number) {
    switch (resource[me_card[put_card[i]]].get_type()) {
    case 1:
      if (!enemy_defend)
        enemy_blood -= resource[me_card[put_card[i]]].get_hurt();
      else {
        enemy_defend = false;
        cout << endl << "敌方成功抵挡了一次伤害。" << endl;
      }
      break;
    case 2:
      if (b(e) < resource[me_card[put_card[i]]].get_possibility())
        me_defend = true;
      break;
    case 3:
      me_blood += resource[me_card[put_card[i]]].get_hurt();
      break;
    case 4:
      me_magic += resource[me_card[put_card[i]]].get_cost();
      break;
    case 5:
      me_magic -= resource[me_card[put_card[i]]].get_cost();
      enemy_blood -= resource[me_card[put_card[i]]].get_hurt();
      break;
    }
    me_card[put_card[i]] = -1;
    i++;
  }
}
void enemy_card_effect(const int *put_card, int real_number) {
  int i = 0;
  while (i != real_number) {
    switch (resource[enemy_card[put_card[i]]].get_type()) {
    case 1:
      if (!me_defend)
        me_blood -= resource[enemy_card[put_card[i]]].get_hurt();
      else {
        me_defend = false;
        cout << endl << "你成功抵挡了一次伤害。" << endl;
      }
      break;
    case 2:
      if (b(e) < resource[enemy_card[put_card[i]]].get_possibility())
        enemy_defend = true;
      break;
    case 3:
      enemy_blood += resource[enemy_card[put_card[i]]].get_hurt();
      break;
    case 4:
      enemy_magic += resource[enemy_card[put_card[i]]].get_cost();
      break;
    case 5:
      enemy_magic -= resource[enemy_card[put_card[i]]].get_cost();
      me_blood -= resource[enemy_card[put_card[i]]].get_hurt();
      break;
    }
    enemy_card[put_card[i]] = -1;
    i++;
  }
}