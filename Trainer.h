#ifndef TRAINER_H
#define TRAINER_H

#include "Pokemon.h"
#include <vector>
#include <memory>

class Trainer {
public:
    Trainer(std::string name);

    std::string getName() const;
    void addPokemon(std::unique_ptr<Pokemon> pokemon);
    void showTeam() const;
    Pokemon* selectPokemon(int index);

private:
    std::string name;
    std::vector<std::unique_ptr<Pokemon>> team;
};

#endif
