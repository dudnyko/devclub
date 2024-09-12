// Юніт
// Юніт має назву, колькість поінтів здоров'я та показник атаки
// Юніт може атакувати ворога
// Юніт якого атакують, завжди контратакує на половину сили
// Мертвих юнітів атакувати неможна
// Показник здоров'я юніта не може бути менший за 0 ;)

#include <iostream>

class UnitIsDeadException {
private:
    std::string message;

public:
    UnitIsDeadException(std::string unitName) {
        this->message = unitName + " is dead";
    };

    std::string getMessage() {
        return message;
    }
};

class Unit {
private:
    std::string title;
    int hp;
    int maxHP;
    int damage;

public:
    Unit(const std::string& title, int maxHP, int damage) {
        this->title = title;
        this->maxHP = maxHP;
        this->hp = maxHP;
        this->damage = damage;
    }

    std::string getTitle() const {
        return this->title;
    }

    int getHP() const {
        return this->hp;
    }

    int getMaxHP() const {
        return this->maxHP;
    }

    int getDamage() const {
        return this->damage;
    }

    // your getters/setters here :)
    // E.g:
    //
    // const std::string& getTitle() const {
    //     return this->title;
    // }
    //
    // etc...

    void attack(Unit& enemy) {
        int healthRemain = enemy.getHP() - this->getDamage();

        if (healthRemain > 0) {
            enemy.hp = healthRemain;
            counterAttack(enemy);
        }
        else {
            UnitIsDeadException obj(enemy.getTitle());
            throw obj;
        }
    }

    void counterAttack(Unit& enemy) {
        int healthRemain = this->getHP() - enemy.getDamage() / 2;

        if (healthRemain > 0) {
            this->hp = healthRemain;
        }
        else {
            UnitIsDeadException obj(this->getTitle());
            throw obj;
        }
    }
};

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getTitle() << ": hp(" << unit.getHP() << "/" << unit.getMaxHP() << "), dmg (" << unit.getDamage() << ")";
    return out;
    // Output example: <Title>:: hp(<hp>/<maxHP>), dmg(<damage>)
}

int main() {
    Unit knight("Knight", 100, 20);
    Unit barbarian("Barbarian", 80, 30);

    std::cout << knight << std::endl; // Knight:: hp(100/100), dmg(20)
    std::cout << barbarian << std::endl; // Barbarian:: hp(80/80), dmg(30)

    try {
        knight.attack(barbarian);

        std::cout << knight << std::endl; // Knight:: hp(85/100), dmg(20)
        std::cout << barbarian << std::endl; // Barbarian:: hp(60/80), dmg(30)

        knight.attack(barbarian);

        std::cout << knight << std::endl; // Knight:: hp(85/100), dmg(20)
        std::cout << barbarian << std::endl; // Barbarian:: hp(60/80), dmg(30)

        knight.attack(barbarian);

        std::cout << knight << std::endl; // Knight:: hp(85/100), dmg(20)
        std::cout << barbarian << std::endl; // Barbarian:: hp(60/80), dmg(30)

        barbarian.attack(knight);

        std::cout << knight << std::endl; // Knight:: hp(85/100), dmg(20)
        std::cout << barbarian << std::endl; // Barbarian:: hp(60/80), dmg(30)

        barbarian.attack(knight);

        std::cout << knight << std::endl; // Knight:: hp(85/100), dmg(20)
        std::cout << barbarian << std::endl; // Barbarian:: hp(60/80), dmg(30)

        barbarian.attack(knight);

        std::cout << knight << std::endl; // Knight:: hp(85/100), dmg(20)
        std::cout << barbarian << std::endl; // Barbarian:: hp(60/80), dmg(30)

    }
    catch (UnitIsDeadException obj) {
        std::cout << obj.getMessage() << std::endl;
    }
    return 0;
}