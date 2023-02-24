#include "knight.h"

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

class Enemy
{
protected:
    int level;
    int base_damage;

public:
    Enemy(int _level, int _base_damage) : level(_level), base_damage(_base_damage) {}
    virtual ~Enemy() {}
    virtual int getLevel()
    {
        return this->level;
    }
    virtual int getDamage()
    {
        return this->level * base_damage;
    }
};

class MadBear : public Enemy
{
public:
    MadBear(int _level) : Enemy(_level, 10) {}
};

class Bandit : public Enemy
{
public:
    Bandit(int _level) : Enemy(_level, 15) {}
};

class LordLupin : public Enemy
{
public:
    LordLupin(int _level) : Enemy(_level, 45) {}
};

class Elf : public Enemy
{
public:
    Elf(int _level) : Enemy(_level, 75) {}
};

class Troll : public Enemy
{
public:
    Troll(int _level) : Enemy(_level, 95) {}
};

class Shaman
{
private:
    int level;

public:
    // Constructor
    Shaman(int lvl)
    {
        this->level = lvl;
    }

    int getLevel() const
    {
        return this->level;
    }

    void setLevel(int lvl)
    {
        this->level = lvl;
    }
};

class Vajsh
{
private:
    int level;

public:
    // Constructor
    Vajsh(int lvl)
    {
        this->level = lvl;
    }

    int getLevel() const
    {
        return this->level;
    }

    void setLevel(int lvl)
    {
        this->level = lvl;
    }
};

class Knight
{
private:
    int HP;
    int MaxHP;
    int level;
    int remedy;
    int maidenkiss;
    int phoenixdown;
    bool isArthur = false;
    bool isLancelot = false;
    bool isDwarf = false;
    bool isFrog = false;
    int lvlFrog = 0;
    int countAffect = 0;

public:
    // Constructor
    Knight(int hp, int lvl, int rmd, int mk, int pd)
    {
        this->HP = hp;
        this->MaxHP = hp;
        this->level = lvl;
        this->remedy = rmd;
        this->maidenkiss = mk;
        this->phoenixdown = pd;

        if (this->HP == 999)
        {
            this->isArthur = true;
        }

        if (isPrime(this->HP))
        {
            this->isLancelot = true;
        }
    }

    // Default constructor
    Knight() : Knight(1, 1, 0, 0, 0) {}

    // Getters
    int getHP() const
    {
        return this->HP;
    }

    int getMaxHP() const
    {
        return this->MaxHP;
    }

    int getLevel() const
    {
        return this->level;
    }

    int getRemedy() const
    {
        return this->remedy;
    }

    int getMaidenKiss() const
    {
        return this->maidenkiss;
    }

    int getPhoenixDown() const
    {
        return this->phoenixdown;
    }

    bool getisArthur() const
    {
        return this->isArthur;
    }

    bool getisLancelot() const
    {
        return this->isLancelot;
    }

    bool getisDwarf()
    {
        return this->isDwarf;
    }

    bool getisFrog()
    {
        return this->isFrog;
    }

    int getLevelFrog()
    {
        return this->lvlFrog;
    }

    int getCountAffect()
    {
        return this->countAffect;
    }
    // Setters
    void setHP(int hp)
    {
        if (hp < this->MaxHP)
        {
            this->HP = hp;
        }
        else
        {
            cout << "DMM";
            this->HP = this->MaxHP;
        }
    }

    void setMaxHP(int maxhp)
    {
        this->MaxHP = maxhp;
    }

    void setLevel(int lvl)
    {
        if (lvl < 1)
        {
            this->level = 1;
        }
        else if (lvl > 10)
        {
            this->level = 10;
        }
        else
        {
            this->level = lvl;
        }
    }

    void setRemedy(int rmd)
    {
        if (rmd < 0)
        {
            this->remedy = 0;
        }
        else if (rmd > 99)
        {
            this->remedy = 99;
        }
        else
        {
            this->remedy = rmd;
        }
    }

    void setMaidenKiss(int mk)
    {
        if (mk < 0)
        {
            this->maidenkiss = 0;
        }
        else if (mk > 99)
        {
            this->maidenkiss = 99;
        }
        else
        {
            this->maidenkiss = mk;
        }
    }

    void setPhoenixDown(int pd)
    {
        if (pd < 0)
        {
            this->phoenixdown = 0;
        }
        else if (pd > 99)
        {
            this->phoenixdown = 99;
        }
        else
        {
            this->phoenixdown = pd;
        }
    }

    void setisDwarf(bool isDwarf)
    {
        this->isDwarf = isDwarf;
    }

    void setisFrog(bool isFrog)
    {
        this->isFrog = isFrog;
    }

    void setLevelFrog(int lvlFrog)
    {
        this->lvlFrog = lvlFrog;
    }

    void setCountAffect(int count)
    {
        this->countAffect = count;
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "HP: " << this->HP << "\n";
        ss << "Level: " << this->level << "\n";
        ss << "Arthur: " << (this->isArthur ? "yes" : "no") << "\n";
        ss << "Lancelot: " << (this->isLancelot ? "yes" : "no") << "\n";
        ss << "Is Dwarf: " << (this->isDwarf ? "yes" : "no") << "\n";
        ss << "Is Frog: " << (this->isFrog ? "yes" : "no") << "\n";
        ss << "Remedy: " << this->remedy << "\n";
        ss << "Maidenkiss: " << this->maidenkiss << "\n";
        ss << "Phoenixdown: " << this->phoenixdown << "\n";
        return ss.str();
    }

    void fight(Enemy enemy)
    {

        if (this->level > enemy.getLevel() || this->isArthur || this->isLancelot)
        {
            // Knight wins
            if (this->level < 10)
            {
                setLevel(this->level + 1);
            }
        }
        else if (this->level == enemy.getLevel())
        {
            // Draw
        }
        else
        {
            // Knight loses
            int newHP = this->HP - enemy.getDamage();
            if (newHP < 1)
            {
                if (getPhoenixDown() > 0)
                {
                    setPhoenixDown(getPhoenixDown() - 1);
                    setisDwarf(false);
                    newHP = getMaxHP();
                }
            }
            setHP(newHP);
        }
    }

    void fight(Shaman shaman)
    {

        if (this->level > shaman.getLevel() || this->isArthur || this->isLancelot)
        {
            // Knight wins
            if (this->level < 10)
            {
                setLevel(this->level + 2);
            }
        }
        else if (this->level == shaman.getLevel())
        {
            // Draw
        }
        else
        {
            // Lose
            if (this->remedy > 0)
            {
                setRemedy(this->remedy - 1);
                int newHP = this->HP / 5;
                setHP(newHP * 5);
            }
            else
            {
                // turn the knight into a dwarf for the next 3 events
                setisDwarf(true);
                setCountAffect(0);
                int newHP = this->HP / 5;
                if (newHP < 5)
                {
                    setHP(1);
                }
                else
                {
                    setHP(newHP);
                }
            }
        }
    }

    void fight(Vajsh vajsh)
    {
        if (this->level > vajsh.getLevel() || this->isArthur || this->isLancelot)
        {
            // Knight wins
            if (this->level < 10)
            {
                setLevel(this->level + 1);
            }
        }
        else if (this->level == vajsh.getLevel())
        {
            // Draw
        }
        else
        {
            // Lose
            if (this->maidenkiss > 0)
            {
                setMaidenKiss(this->maidenkiss - 1);
            }
            else
            {
                // turn the knight into a frog for the next 3 events
                setisFrog(true);
                setCountAffect(0);
                setLevelFrog(getLevel());
                setLevel(1);
            }
        }
    }
};

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    int events[100];
    string file_mush_ghost;
    string file_asclepius_pack;
    string file_merlin_pack;
    int num_events = 0;
    rescue = 0;

    ifstream input_file(file_input);
    if (input_file.is_open())
    {
        input_file >> HP >> level >> remedy >> maidenkiss >> phoenixdown;

        string line;
        getline(input_file, line); // read the end of the first line
        getline(input_file, line); // read the second line
        istringstream iss(line);
        int event;
        while (iss >> event)
        {
            events[num_events++] = event;
        }

        getline(input_file, line); // read the third line
        istringstream iss2(line);
        getline(iss2, file_mush_ghost, ',');
        getline(iss2, file_asclepius_pack, ',');
        getline(iss2, file_merlin_pack);
        input_file.close();
    }

    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

    Knight knight(HP, level, remedy, maidenkiss, phoenixdown);

    for (int i = 0; i < num_events; i++)
    {
        int b = (i + 1) % 10;
        int levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
        cout << "LevelO: " << levelO << endl;
        int event = events[i];
        cout << "Event: " << event << endl;
        if (knight.getisDwarf())
        {
            knight.setCountAffect(knight.getCountAffect() + 1);
        }
        switch (event)
        {
        case 0: // Bowser đầu hàng và trả lại công chúa
            rescue = 1;
            return;
        case 1: // Gặp gấu MadBear
            knight.fight(MadBear(levelO));
            break;
        case 2: // Gặp cướp Bandit
            knight.fight(Bandit(levelO));
            break;
        case 3: // Gặp tướng cướp LordLupin
            knight.fight(LordLupin(levelO));
            break;
        case 4: // Gặp yêu tinh Elf
            knight.fight(Elf(levelO));
            break;
        case 5: // Gặp quỷ khổng lồ Troll
            knight.fight(Troll(levelO));
            break;
        case 6: // Gặp phù thuỷ Shaman
            knight.fight(Shaman(levelO));
            break;
        case 7: // Gặp Siren Vajsh
            knight.fight(Vajsh(levelO));
            break;
        case 11: // Nhặt được nấm tăng lực MushMario

            break;
        case 12: // Nhặt được nấm Fibonacci MushFib

            break;
        case 13: // Nhặt được nấm ma MushGhost

            break;
        case 15: // Nhặt được thuốc phục hồi Remedy

            break;
        case 16: // Nhặt được thuốc giải MaidenKiss

            break;
        case 17: // Nhặt được giọt nước mắt phượng hoàng PhoenixDown

            break;
        case 18: // Gặp phù thuỷ Merlin

            break;
        case 19: // Gặp thần Asclepius

            break;
        case 99: // Gặp Bowser

            break;
        default:
            return;
        }

        if (knight.getCountAffect() == 3)
        {
            if (knight.getisDwarf())
            {
                knight.setisDwarf(false);
                knight.setCountAffect(0);
                knight.setHP(knight.getHP() * 5);
            }
            if (knight.getisFrog())
            {
                knight.setisFrog(false);
                knight.setCountAffect(0);
                knight.setLevel(knight.getLevelFrog());
            }
        }

        if (knight.getHP() < 1)
        {
            cout << "Ngu vcc" << endl;
            return;
        }

        cout << knight.toString() << endl;
    }
}