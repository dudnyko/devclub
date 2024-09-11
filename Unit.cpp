// Юніт
// Юніт має назву, колькість поінтів здоров'я та показник атаки
// Юніт може атакувати ворога
// Юніт якого атакують, завжди контратакує на половину сили
// Мертвих юнітів атакувати неможна
// Показник здоров'я юніта не може бути менший за 0 ;)

#include <iostream>

class UnitIsDeadException {};

class Unit {
private:
    std::string title;
    int hp;
    int maxHP;
    int damage;

public:
    Unit(const std::string& title, int maxHP, int damage) {
        // your code here :)
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
        // your code here :)
    }

    void counterAttack(Unit& enemy) {
        // your code here :)
    }
};

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    // your code here :)
    // Output example: <Title>:: hp(<hp>/<maxHP>), dmg(<damage>)
}

int main() {
    Unit knight("Knight", 100, 20);
    Unit barbarian("Barbarian", 80, 30);

    std::cout << knight << std::endl; // Knight:: hp(100/100), dmg(20)
    std::cout << barbarian << std::endl; // Barbarian:: hp(80/80), dmg(30)

    knight.attack(barbarian);

    std::cout << knight << std::endl; // Knight:: hp(85/100), dmg(20)
    std::cout << barbarian << std::endl; // Barbarian:: hp(60/80), dmg(30)

    return 0;
}