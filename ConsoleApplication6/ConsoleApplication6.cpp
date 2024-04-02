// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
using namespace std;    
    
class Character abstract    
{
protected:
    string name;    
    int attack;
    int speed;
    int health;
    int defense;
public:
    Character(string n, int att, int sp, int hlt, int def)           
    {
        name = n;   
        attack = att;    
        speed = sp;        
        health = hlt; 
        defense = def;  
    }   
    string GetName() 
    {
        return name;    
    }
    int GetAttack()
    {
        return attack;  
    }
    int GetSpeed()
    {
        return speed;
    }
    int GetHealth()
    {
        return health;
    }
    int GetDefense()
    {
        return defense; 
    }
    virtual int Attack() abstract;
    virtual int Speed() abstract;
    virtual int Health() abstract;
    virtual int Defense() abstract; 
};

class Human : public Character
{
public:
    Human(): Character("Human", 20, 20, 150, 0)         
    {}
    int Attack() override
    {
        return 20;
    }
    int Speed() override
    {
        return 20;
    }
    int Health() override
    {
        return 150;
    }
    int Defense() override
    {
        return 1;   
    }
};

class Elf : public Character
{
public: 
    Elf(): Character("Elf", 15, 30, 100, 0) 
    {}
    int Attack() override
    {
        return 15;
    }
    int Speed() override
    {
        return 30;
    }
    int Health() override
    {
        return 100;
    }
    int Defense() override
    {
        return 1;
    }
};

class HumanDericator abstract: public Character
{
protected:
    Character* character;
public: 
    HumanDericator(string n, int att, int sp, int hlt, int def, Character* character): Character(n, att, sp, hlt, def)    
    {
        this->character = character;
    }
};

class HumanWarrior : public HumanDericator
{
public:
    HumanWarrior(Character* ptr) : HumanDericator(ptr->GetName() + ": warrior", ptr->GetAttack() +20, 
        ptr->GetSpeed() +10, ptr->GetHealth() +50, ptr->GetDefense() + 20, ptr) {}     
    int Attack() 
    {
        return character->GetAttack(); 
    }
    int Speed() 
    {
        return character->GetSpeed();
    }
    int Health()
    {
        return character->GetHealth();
    }
    int Defense() 
    {
        return character->GetDefense();
    }
};

class HumanSwordtail : public HumanDericator
{
public:
    HumanSwordtail(Character* ptr) : HumanDericator(ptr->GetName() + ": swordtail", ptr->GetAttack() + 40, 
        ptr->GetSpeed() - 10, ptr->GetHealth() + 50, ptr->GetDefense() + 40, ptr) {}     
    int Attack() 
    {
        return character->GetAttack();   
    }
    int Speed()
    {
        return character->GetSpeed();
    }
    int Health()
    {
        return character->GetHealth();
    }
    int Defense()
    {
        return character->GetDefense();    
    }
};

class HumanArcher : public HumanDericator
{
public:
    HumanArcher(Character* ptr) : HumanDericator(ptr->GetName() + ": Archer", ptr->GetAttack() + 20,
        ptr->GetSpeed() + 20, ptr->GetHealth() + 50, ptr->GetDefense() + 10, ptr) {}    
    int Attack()
    {
        return character->GetAttack();
    }
    int Speed()
    {
        return character->GetSpeed();
    }
    int Health()
    {
        return character->GetHealth();
    }
    int Defense()
    {
        return character->GetDefense();
    }
};

class HumanRider : public HumanDericator
{
public:
    HumanRider(Character* ptr) : HumanDericator(ptr->GetName() + ": Rider", ptr->GetAttack() - 10,
        ptr->GetSpeed() + 40, ptr->GetHealth() + 200, ptr->GetDefense() + 100, ptr) {}    
    int Attack()
    {
        return character->GetAttack();
    }
    int Speed()
    {
        return character->GetSpeed();
    }
    int Health()
    {
        return character->GetHealth();
    }
    int Defense()
    {
        return character->GetDefense();
    }
};

class ElfDericator abstract : public Character        
{
protected:
    Character* character;    
public:
    ElfDericator(string n, int att, int sp, int hlt, int def, Character* character) : Character(n, att, sp, hlt, def)
    {
        this->character = character;    
    }
};

class ElfWarrior : public ElfDericator
{
public:
    ElfWarrior(Character* ptr) : ElfDericator(ptr->GetName() + ": Warrior", ptr->GetAttack() + 20,
        ptr->GetSpeed() - 10, ptr->GetHealth() + 100, ptr->GetDefense() + 20, ptr) {}
    int Attack()
    {
        return character->GetAttack();
    }
    int Speed()
    {
        return character->GetSpeed();
    }
    int Health()
    {
        return character->GetHealth();
    }
    int Defense()
    {
        return character->GetDefense();
    }
};

class ElfMagician : public ElfDericator
{
public:
    ElfMagician(Character* ptr) : ElfDericator(ptr->GetName() + ": Magician", ptr->GetAttack() + 10,    
        ptr->GetSpeed() + 10, ptr->GetHealth() - 50, ptr->GetDefense() + 10, ptr) {}    
    int Attack()
    {
        return character->GetAttack();  
    }
    int Speed()
    {
        return character->GetSpeed();
    }
    int Health()
    {
        return character->GetHealth();
    }
    int Defense()
    {
        return character->GetDefense();
    }
};

class ElfCrossbowman : public ElfDericator
{
public:
    ElfCrossbowman(Character* ptr) : ElfDericator(ptr->GetName() + ": Crossbowman", ptr->GetAttack() + 20,   
        ptr->GetSpeed() + 10, ptr->GetHealth() - 50, ptr->GetDefense() + 10, ptr) {}    
    int Attack()
    {
        return character->GetAttack();
    }
    int Speed()
    {
        return character->GetSpeed();
    }
    int Health()
    {
        return character->GetHealth();
    }
    int Defense()
    {
        return character->GetDefense();
    }
};

class ElfCEvilMage : public ElfDericator                        
{
public:
    ElfCEvilMage(Character* ptr) : ElfDericator(ptr->GetName() + ": Evil Mage", ptr->GetAttack() + 70,
        ptr->GetSpeed() + 20, ptr->GetHealth() + 0, ptr->GetDefense() + 0, ptr) {}    
    int Attack()
    {
        return character->GetAttack();
    }
    int Speed()
    {
        return character->GetSpeed();
    }
    int Health()
    {
        return character->GetHealth();
    }
    int Defense()
    {
        return character->GetDefense();
    }
};

class ElfGoodMagician : public ElfDericator
{
public:
    ElfGoodMagician(Character* ptr) : ElfDericator(ptr->GetName() + ": Good magician", ptr->GetAttack() + 50,
        ptr->GetSpeed() + 30, ptr->GetHealth() + 100, ptr->GetDefense() + 30, ptr) {}  
    int Attack()
    {
        return character->GetAttack();
    }
    int Speed()
    {
        return character->GetSpeed();
    }
    int Health()
    {
        return character->GetHealth();
    }
    int Defense()
    {
        return character->GetDefense();
    }
};



void client(Character* p) 
{
    char s[100];    
    sprintf_s(s, "Name: %s Attack: %d Speed: %d Health: %d Defense: %d", p->GetName().c_str(),
        p->GetAttack(), p->GetSpeed(), p->GetHealth(), p->GetDefense());    
    cout << s << endl;  
}


int main()
{
    Character* p = new Human();
    p = new HumanWarrior(p);    
    client(p);

    p = new Human();
    p = new HumanSwordtail(p);    
    client(p);

    p = new Human();
    p = new HumanArcher(p); 
    client(p);

    p = new Human();
    p = new HumanRider(p);  
    client(p);
    cout << "\n"; 
    Character* ptr = new Elf();       
    ptr = new ElfWarrior(ptr);  
    client(ptr);    

    ptr = new Elf();    
    ptr = new ElfMagician(ptr); 
    client(ptr);

    ptr = new Elf();
    ptr = new ElfCrossbowman(ptr);  
    client(ptr);

    ptr = new Elf();
    ptr = new ElfCEvilMage(ptr);    
    client(ptr);

    ptr = new Elf();
    ptr = new ElfGoodMagician(ptr); 
    client(ptr);

}
