#include "Battle.h"
#include <iostream>

void Battle::startBattle(Trainer& trainer1, Trainer& trainer2) {
    std::cout << "Battle Start!\n";

    // Select Pokémon for Trainer 1
    std::cout << trainer1.getName() << ", choose your Pokemon!\n";
    trainer1.showTeam();
    int choice1;
    std::cin >> choice1;
    Pokemon* p1 = trainer1.selectPokemon(choice1);

    // Select Pokémon for Trainer 2
    std::cout << trainer2.getName() << ", choose your Pokemon!\n";
    trainer2.showTeam();
    int choice2;
    std::cin >> choice2;
    Pokemon* p2 = trainer2.selectPokemon(choice2);

    while (p1->isAlive() && p2->isAlive()) {
        // Trainer 1 choose attack
        std::cout << trainer1.getName() << ", select your attack for " << p1->getName() << ":\n";
        p1->showAttacks();
        int attackChoice1;
        std::cin >> attackChoice1;

        int damage1 = p1->chooseAttack(attackChoice1);
        std::cout << p1->getName() << " attacks " << p2->getName() << " with " << damage1 << " damage!\n";
        p2->reduceHP(damage1);
        std::cout << p2->getName() << " has " << p2->getHP() << " HP remaining.\n";

        if (!p2->isAlive()) break;

        // Trainer 2 choose attack
        std::cout << trainer2.getName() << ", select your attack for " << p2->getName() << ":\n";
        p2->showAttacks();
        int attackChoice2;
        std::cin >> attackChoice2;

        int damage2 = p2->chooseAttack(attackChoice2);
        std::cout << p2->getName() << " attacks " << p1->getName() << " with " << damage2 << " damage!\n";
        p1->reduceHP(damage2);
        std::cout << p1->getName() << " has " << p1->getHP() << " HP remaining.\n";

        if (!p1->isAlive()) break;
    }

    // Declare winner
    if (p1->isAlive()) {
        std::cout << trainer1.getName() << " wins!\n";
    } else {
        std::cout << trainer2.getName() << " wins!\n";
    }
}
