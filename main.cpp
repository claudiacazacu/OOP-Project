#include "Trainer.h"
#include "Battle.h"
#include <iostream>
#include <memory>

int main() {
    // Nume antrenori
    std::string trainer1Name, trainer2Name;
    std::cout << "Enter name for Trainer 1: ";
    std::getline(std::cin, trainer1Name);
    std::cout << "Enter name for Trainer 2: ";
    std::getline(std::cin, trainer2Name);

    // Creează antrenorii
    Trainer trainer1(trainer1Name);
    Trainer trainer2(trainer2Name);

    // Creează Pokémoni pentru fiecare antrenor
    trainer1.addPokemon(std::make_unique<Pokemon>("Pikachu", 100, 20));
    trainer1.addPokemon(std::make_unique<Pokemon>("Bulbasaur", 120, 18));
    trainer1.addPokemon(std::make_unique<Pokemon>("Charmander", 110, 25));
    trainer1.addPokemon(std::make_unique<Pokemon>("Squirtle", 130, 15));

    trainer2.addPokemon(std::make_unique<Pokemon>("Starmie", 120, 25));
    trainer2.addPokemon(std::make_unique<Pokemon>("Magikarp", 50, 10));
    trainer2.addPokemon(std::make_unique<Pokemon>("Gyarados", 160, 30));
    trainer2.addPokemon(std::make_unique<Pokemon>("Eevee", 90, 22));

    // Adaugă atacuri Pokémonilor
    trainer1.selectPokemon(1)->addAttack("Thunderbolt", 40);
    trainer1.selectPokemon(1)->addAttack("Quick Attack", 20);
    trainer1.selectPokemon(1)->addAttack("Electro Ball", 50);

    trainer1.selectPokemon(2)->addAttack("Vine Whip", 30);
    trainer1.selectPokemon(2)->addAttack("Solar Beam", 60);
    trainer1.selectPokemon(2)->addAttack("Tackle", 10);

    trainer1.selectPokemon(3)->addAttack("Flamethrower", 50);
    trainer1.selectPokemon(3)->addAttack("Ember", 30);
    trainer1.selectPokemon(3)->addAttack("Fire Spin", 40);

    trainer1.selectPokemon(4)->addAttack("Water Gun", 20);
    trainer1.selectPokemon(4)->addAttack("Hydro Pump", 70);
    trainer1.selectPokemon(4)->addAttack("Bubble Beam", 40);

    trainer2.selectPokemon(1)->addAttack("Water Pulse", 35);
    trainer2.selectPokemon(1)->addAttack("Hydro Pump", 60);
    trainer2.selectPokemon(1)->addAttack("Bubble", 15);

    trainer2.selectPokemon(2)->addAttack("Splash", 5);
    trainer2.selectPokemon(2)->addAttack("Flail", 20);

    trainer2.selectPokemon(3)->addAttack("Dragon Rage", 40);
    trainer2.selectPokemon(3)->addAttack("Bite", 30);
    trainer2.selectPokemon(3)->addAttack("Ice Fang", 35);

    trainer2.selectPokemon(4)->addAttack("Quick Attack", 20);
    trainer2.selectPokemon(4)->addAttack("Tackle", 10);
    trainer2.selectPokemon(4)->addAttack("Hyper Beam", 100);

    // Începe bătălia
    Battle battle;
    battle.startBattle(trainer1, trainer2);

    return 0;
}
