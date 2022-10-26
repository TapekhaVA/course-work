#include "Player.h"

Player::Player(int health, int armour, int damage) {
    this->health = health;
    this->max_health = health;
    this->armour = armour;
    this->damage = damage;
    this->coins = 0;
}

int Player::get_health() const {
    return this->health;
}

int Player::get_armour() const {
    return this->armour;
}

int Player::get_coins() const {
    return this->coins;
}

int Player::get_damage() const {
    return this->damage;
}

void Player::set_health(int arg) {
    if(arg<0){
        this->health = 0;
    }
    else
        this->health = arg;
    notify();
}

void Player::set_armour(int arg) {
    this->armour = arg;
    notify();
}

void Player::set_coins(int arg) {
    if(arg<0){
        this->coins = 0;
    }
    else
        this->coins = arg;
    notify();
}

void Player::set_damage(int arg) {
    if(arg<0){
        this->damage = 0;
    }
    else
        this->damage = arg;
    notify();
}

bool Player::is_max_health() const {
    return this->health == this->max_health;
}



