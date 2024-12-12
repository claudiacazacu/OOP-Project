#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon(std::string name, int hp, int attack)
    : name(name), hp(hp), attack(attack) {}

std::string Pokemon::getName() const {
    return name;
}

int Pokemon::getHP() const {
    return hp;
}

int Pokemon::getAttack() const {
    return attack;
}

void Pokemon::reduceHP(int damage) {
    hp -= damage;
}

bool Pokemon::isAlive() const {
    return hp > 0;
}

void Pokemon::addAttack(const std::string& attackName, int power) {
    attacks.push_back({ attackName, power });
}

void Pokemon::showAttacks() const {
    for (size_t i = 0; i < attacks.size(); ++i) {
        std::cout << (i + 1) << ". " << attacks[i].name << " (Power: " << attacks[i].power << ")\n";
    }
}

int Pokemon::chooseAttack(int choice) const {
    if (choice > 0 && choice <= attacks.size()) {
        return attacks[choice - 1].power;
    }
    return 0;
}
