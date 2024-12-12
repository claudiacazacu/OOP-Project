#include "Trainer.h"
#include <iostream>

Trainer::Trainer(std::string name) : name(name) {}

std::string Trainer::getName() const {
    return name;
}

void Trainer::addPokemon(std::unique_ptr<Pokemon> pokemon) {
    team.push_back(std::move(pokemon));
}

void Trainer::showTeam() const {
    for (size_t i = 0; i < team.size(); ++i) {
        std::cout << (i + 1) << ". " << team[i]->getName() << " (HP: " << team[i]->getHP() << ")\n";
    }
}

Pokemon* Trainer::selectPokemon(int index) {
    if (index > 0 && index <= team.size()) {
        return team[index - 1].get();
    }
    return nullptr;
}
