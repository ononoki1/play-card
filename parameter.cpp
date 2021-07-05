#include "parameter.h"

const int all_card = 12, me_max_card = 10, enemy_max_card = 100;
card resource[all_card];
int me_card[me_max_card], enemy_card[enemy_max_card];
const int me_max_blood = 30, enemy_max_blood = 30;
int me_blood = me_max_blood, enemy_blood = enemy_max_blood;
int before_me_blood = me_blood, before_enemy_blood = enemy_blood;
int me_magic = 0, enemy_magic = 0;
int before_me_magic = me_magic, before_enemy_magic = enemy_magic;
int turn = 1, me_save = 0;
const int due_me_card_number = 4, due_enemy_card_number = 4;
int me_card_number = due_me_card_number,
    enemy_card_number = due_enemy_card_number;
bool me_defend = false, enemy_defend = false;
bool me_more_card = false;

random_device s;
default_random_engine e(s());
uniform_int_distribution<int> a(0, all_card - 1), b(0, 99);