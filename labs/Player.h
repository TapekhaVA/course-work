#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H


class Player{
public:
    enum STEP{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NOTHING
    };

    explicit Player(unsigned int health = 100,
           unsigned int shield = 0,
           unsigned int damage = 10,
           unsigned int xp = 0);

    unsigned int getHealth() const;
    unsigned int getShield() const;
    unsigned int getDamage() const;

    void setHealth(unsigned int health);
    void setShield(unsigned int shield);
    void setDamage(unsigned int damage);

    void addHealth(unsigned int health);
    void addShield(unsigned int shield);
    void addXp(unsigned int xp);

    void downHealth(unsigned int health);
    void downShield(unsigned int health);

    void roundValue(unsigned int& value);


private:
    unsigned int health;
    unsigned int shield;
    unsigned int damage;
    unsigned int xp;
};


#endif
