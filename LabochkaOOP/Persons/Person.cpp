
//
// Created by corvussharp on 21.09.22.
//

#include "Person.h"

Person::Person(int hp, int damage, int xp, int lvl) : health(hp), damage(damage), xp(xp), lvl(lvl) {

}

int Person::get_hp() const {
    return health;
}

int Person::get_xp() const {
    return xp;
}

int Person::get_dmg() const {
    return damage;
}

int Person::get_lvl() const {
    return lvl;
}

void Person::set_hp(int hp) {
    this->health = hp;
    Message message(GAME, "Установленно новое значение хп");
    LOG.print(message);

}

void Person::set_dmg(int dmg) {
    this->damage = dmg;
    Message message(GAME, "Установленно новое значение дэмга");
    LOG.print(message);
}

void Person::set_xp(int xpe) {
    this->xp = xpe;
    Message message(GAME, "Установленно новое значение опыта");
    LOG.print(message);
}

void Person::set_lvl(int lvl) {
    this->lvl = lvl;
    Message message(GAME, "Установленно новое значение уровня");
    LOG.print(message);
}