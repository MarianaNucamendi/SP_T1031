#pragma once
#include <string>

class Monster{
public:
    Monster();
    Monster(std::string name, float cr, std::string type, 
            std::string size, int ac, int hp, std::string align);
    ~Monster();

    void setName(std::string newName);
    void setCr(float newCr);
    void setType(std::string newType);
    void setSize(std::string newSize);
    void setAc(int newAc);
    void setHp(int newHp);
    void setAlign(std::string newAlign);

    bool operator<(const Monster &monster);
    bool operator>(const Monster &monster);
    friend std::ostream& operator<<(std::ostream& os, const Monster &monster);


private:
    std::string name;
    float cr;
    std::string type;
    std::string size;
    int ac;
    int hp;
    std::string align;
};