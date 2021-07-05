class card {
private:
  char name[10]; //卡牌名称
  int type; //卡牌种类，攻击=1，防御=2，回血=3，法力=4，咒术=5
  int hurt = 0;        //造成伤害或回血数
  int cost = 0;        //消耗法力或增加法力数
  int possibility = 0; //防御下一次伤害的概率，以1%为单位
  int chance;          //抽中此牌的概率，以1%为单位
  int priority = 0;    //敌方出此牌的优先级

public:
  void init(int option);
  void put_name();
  int get_type();
  int get_hurt();
  int get_cost();
  int get_possibility();
  int get_chance();
  int get_priority();
};