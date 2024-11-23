#include <iostream>
#include <vector>
#include <string>

class Attack {
private:
    std::string name;
    int power;

public:
    Attack(const std::string& name, int power) : name(name), power(power) {}

    ~Attack() {
       //  std::cout << "Destructorul Attack a fost apelat\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Attack& attack) {
        os << attack.name << " (Power: " << attack.power << ")";
        return os;
    }

    int getPower() const { return power; }
};

class Pokemon {
private:
    std::string name;
    int hp;
    std::vector<Attack> attacks;

public:
    Pokemon(const std::string& name, int hp, const std::vector<Attack>& attacks)
        : name(name), hp(hp), attacks(attacks) {}

    ~Pokemon() {
        // std::cout << "Destructorul Pokemon a fost apelat\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Pokemon& pokemon) {
        os << pokemon.name << " (HP: " << pokemon.hp << ")";
        return os;
    }

    void showAttacks() const {
        for (const auto& attack : attacks) {
            std::cout << attack << "\n";
        }
    }

    void receiveDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
    }

    int getHp() const { return hp; }
    std::string getName() const { return name; }

    const Attack& chooseAttack(int index) const {
        if (index >= 0 && index < attacks.size()) {
            return attacks[index];
        }
        return attacks[0];
    }
};

class Trainer {
private:
    std::string name;
    Pokemon pokemon;

public:
    Trainer(const std::string& name, const Pokemon& pokemon) : name(name), pokemon(pokemon) {}

    ~Trainer() {
       // std::cout << "Destructorul Trainer a fost apelat\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Trainer& trainer) {
        os << "Trainer: " << trainer.name << " with " << trainer.pokemon;
        return os;
    }

    void instructAttack(Trainer& opponent) {
        int damage = pokemon.chooseAttack(0).getPower();
        opponent.pokemon.receiveDamage(damage);
    }
};

class Battle {
private:
    Trainer& trainer1;
    Trainer& trainer2;

public:
    Battle(Trainer& trainer1, Trainer& trainer2) : trainer1(trainer1), trainer2(trainer2) {}

    void start() {
        std::cout << "Battle Start: " << trainer1 << " VS " << trainer2 << "\n";
        trainer1.instructAttack(trainer2);
        trainer2.instructAttack(trainer1);
        std::cout << trainer1 << "\n" << trainer2 << "\n";
    }
};

Pokemon choosePokemon() {
    std::vector<Pokemon> availablePokemon = {
        Pokemon("Pikachu", 100, { Attack("Thunderbolt", 50), Attack("Quick Attack", 20), Attack("Iron Tail", 40) }),
        Pokemon("Charmander", 100, { Attack("Flamethrower", 55), Attack("Scratch", 15), Attack("Ember", 30) }),
        Pokemon("Bulbasaur", 100, { Attack("Vine Whip", 45), Attack("Tackle", 15), Attack("Razor Leaf", 35) })
    };

    std::cout << "Cu ce Pokemon vrei sa joci?\n";
    for (size_t i = 0; i < availablePokemon.size(); ++i) {
        std::cout << i + 1 << ". " << availablePokemon[i].getName() << " cu atacurile:\n";
        availablePokemon[i].showAttacks();
    }

    int choice;
    std::cout << "Alege numarul Pokemonului: ";
    std::cin >> choice;

    while (choice < 1 || choice > availablePokemon.size()) {
        std::cout << "Alegere invalida. Alege iar: ";
        std::cin >> choice;
    }

    return availablePokemon[choice - 1];
}

int main() {
    std::string trainer1Name, trainer2Name;
    std::cout << "Nume trainer 1: ";
    std::cin.ignore();
    std::getline(std::cin, trainer1Name);

    std::cout << "Nume trainer 2: ";
    std::getline(std::cin, trainer2Name);

    std::cout << trainer1Name << ", Nr pokemonului pe care l vrei:\n";
    Pokemon pokemon1 = choosePokemon();
    Trainer trainer1(trainer1Name, pokemon1);

    std::cout << trainer2Name << ", Nr pokemonului pe care l vrei:\n";
    Pokemon pokemon2 = choosePokemon();
    Trainer trainer2(trainer2Name, pokemon2);

    Battle battle(trainer1, trainer2);
    battle.start();

    return 0;
}
