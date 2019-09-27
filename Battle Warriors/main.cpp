#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <numeric>

#include <math.h>

using namespace std;

class Warrior{
private:
    int attackMAX;
    int blockMAX;
public:
    string name;
    int health;

    Warrior(string name, int health, int attackMAX, int blockMAX)
    {
        this->name = name;
        this->health = health;
        this->attackMAX = attackMAX;
        this->blockMAX = blockMAX;
    }

    int attack(){
        return rand() % this->attackMAX;
    }
    int block(){
        return rand() % this->blockMAX;
    }
};

class Battle{
public:
    static void StartFight(Warrior& warrior1, Warrior& warrior2){
        while(true){
            if(Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0){
                 cout<<"Game Over\n";
                 break;
            }
            if(Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0){
                 cout<<"Game Over\n";
                 break;
            }
        }
    }

    static string GetAttackResult(Warrior& warrior1, Warrior& warrior2){
            int warriorAAttackAmount = warrior1.attack();
            int warriorBBlockAmount = warrior2.block();

            int damage2WarriorB = ceil(warriorAAttackAmount-warriorBBlockAmount);
            damage2WarriorB = (damage2WarriorB <= 0) ? 0 : damage2WarriorB;

            warrior2.health =  warrior2.health - damage2WarriorB;

            printf("%s attacks %s and deals %d damage \n",
                   warrior1.name.c_str(), warrior2.name.c_str(),
                   damage2WarriorB);

            printf("%s is down to %d health\n", warrior2.name.c_str(),
                   warrior2.health);

            if(warrior2.health <= 0){
                printf("%s had died and %s is victorios\n",
                       warrior2.name.c_str(), warrior1.name.c_str());
                return "Game Over";
            }else{
                return "Fight Again!";
            }

    }

};

int main()
{
    srand(time(NULL));
    Warrior thor("Thor", 100, 10, 15);
    Warrior hulk("Hulk", 70, 25, 10);

    Battle::StartFight(thor,hulk);


    return 0;
}
