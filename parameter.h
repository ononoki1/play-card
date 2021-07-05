#include "card.h"
#include <random>
using namespace std;

extern const int all_card, me_max_card, enemy_max_card;
extern card resource[];
extern int me_card[], enemy_card[];
extern const int me_max_blood, enemy_max_blood;
extern int me_blood, enemy_blood;
extern int before_me_blood, before_enemy_blood;
extern int me_magic, enemy_magic;
extern int before_me_magic, before_enemy_magic;
extern int turn, me_save;
extern const int due_me_card_number, due_enemy_card_number;
extern int me_card_number, enemy_card_number;
extern bool me_defend, enemy_defend;
extern bool me_more_card;

extern random_device s;
extern default_random_engine e;
extern uniform_int_distribution<int> a, b;