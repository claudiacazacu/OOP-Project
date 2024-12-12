#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

class Pokemon {
public:
    Pokemon(std::string name, int hp, int attack);

    std::string getName() const;
    int getHP() const;
    int getAttack() const;
    void reduceHP(int damage);
    bool isAlive() const;

    void addAttack(const std::string& attackName, int power);
    void showAttacks() const;
    int chooseAttack(int choice) const;

private:
    struct Attack {
        std::string name;
        int power;
    };

    std::string name;
    int hp;
    int attack;
    std::vector<Attack> attacks;
};

#endif
