#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <ctime>
#include <string>


class Warrior {
private: 
	int attackMax;
	int blockMax;

public:
	std::string name;
	int health;
	Warrior(std::string name, int health, int attackMax, int blockMax) {
		this->name = name;
		this->health = health;
		this->attackMax = attackMax;
		this->blockMax = blockMax;
	}

	int Attack() {
		return std::rand() % this->attackMax;
	}

	int Block() {
		return std::rand() % this->blockMax;
	}
};

class Battle {
public:
	static void StartFight(Warrior &warrior1, Warrior &warrior2) {
		bool check = true;
		while (check) {
			if (Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0) {
				std::cout << "Game Over!\n";
				check = false;
				break;
			}
			if (Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0) {
				std::cout << "Game Over!\n";
				check = false;
				break;
			}
		}
	}

	static std::string GetAttackResult(Warrior &warriorA, Warrior &warriorB) {
		int warriorAAttackAmmount = warriorA.Attack();
		int warriorBBlockAmmount = warriorB.Block();
		int damageToWarriorB = ceil(warriorAAttackAmmount - warriorBBlockAmmount);

		damageToWarriorB = (damageToWarriorB <= 0) ? 0 : damageToWarriorB;
		warriorB.health = warriorB.health - damageToWarriorB;

		printf("%s attacks $s and deals $d damage\n", warriorA.name.c_str(),
			warriorB.name.c_str(), damageToWarriorB);
		printf("%s is down to $d health\n", warriorB.name.c_str(),
			warriorB.health);

		if (warriorB.health <= 0) {
			printf("%s has Died and %s is Victorius!\n", warriorB.name.c_str(),
				warriorA.name.c_str());
			return "Game Over!";
		}
		else {
			return "Fight Again!";
		}
	}
};

int main() {

	srand(time(NULL));
	Warrior war1("Nier", 110, 30, 15);
	Warrior war2("Mello", 135, 25, 10);
	Battle::StartFight(war1, war2);

	return 0;
}
