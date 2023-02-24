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
        return level;
    }
    virtual int getDamage()
    {
        return level * base_damage;
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
        setLevel(lvl);
    }

    int getLevel() const
    {
        return level;
    }

    void setLevel(int lvl)
    {
        level = lvl;
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
        setLevel(lvl);
    }

    int getLevel() const
    {
        return level;
    }

    void setLevel(int lvl)
    {
        level = lvl;
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
        setHP(hp);
        setMaxHP(hp);
        setLevel(lvl);
        setRemedy(rmd);
        setMaidenKiss(mk);
        setPhoenixDown(pd);

        if (HP == 999)
        {
            isArthur = true;
        }

        if (isPrime(HP))
        {
            isLancelot = true;
        }
    }

    // Default constructor
    Knight() : Knight(1, 1, 0, 0, 0) {}

    // Getters
    int getHP() const
    {
        return HP;
    }

    int getMaxHP() const
    {
        return MaxHP;
    }

    int getLevel() const
    {
        return level;
    }

    int getRemedy() const
    {
        return remedy;
    }

    int getMaidenKiss() const
    {
        return maidenkiss;
    }

    int getPhoenixDown() const
    {
        return phoenixdown;
    }

    bool getisArthur() const
    {
        return isArthur;
    }

    bool getisLancelot() const
    {
        return isLancelot;
    }

    bool getisDwarf()
    {
        return isDwarf;
    }

    bool getisFrog()
    {
        return isFrog;
    }

    int getLevelFrog()
    {
        return lvlFrog;
    }

    int getCountAffect()
    {
        return countAffect;
    }
    // Setters
    void setHP(int hp)
    {
        if (hp < MaxHP)
        {
            HP = hp;
        }
        else
        {
            HP = MaxHP;
        }
    }

    void setMaxHP(int maxhp)
    {
        MaxHP = maxhp;
    }

    void setLevel(int lvl)
    {
        if (lvl < 1)
        {
            level = 1;
        }
        else if (lvl > 10)
        {
            level = 10;
        }
        else
        {
            level = lvl;
        }
    }

    void setRemedy(int rmd)
    {
        if (rmd < 0)
        {
            remedy = 0;
        }
        else if (rmd > 99)
        {
            remedy = 99;
        }
        else
        {
            remedy = rmd;
        }
    }

    void setMaidenKiss(int mk)
    {
        if (mk < 0)
        {
            maidenkiss = 0;
        }
        else if (mk > 99)
        {
            maidenkiss = 99;
        }
        else
        {
            maidenkiss = mk;
        }
    }

    void setPhoenixDown(int pd)
    {
        if (pd < 0)
        {
            phoenixdown = 0;
        }
        else if (pd > 99)
        {
            phoenixdown = 99;
        }
        else
        {
            phoenixdown = pd;
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
        countAffect = count;
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "HP: " << getHP() << "\n";
        ss << "Level: " << getLevel() << "\n";
        ss << "Arthur: " << (getisArthur() ? "yes" : "no") << "\n";
        ss << "Lancelot: " << (getisLancelot() ? "yes" : "no") << "\n";
        ss << "Is Dwarf: " << (getisDwarf() ? "yes" : "no") << "\n";
        ss << "Is Frog: " << (getisFrog() ? "yes" : "no") << "\n";
        ss << "Remedy: " << getRemedy() << "\n";
        ss << "Maidenkiss: " << getMaidenKiss() << "\n";
        ss << "Phoenixdown: " << getPhoenixDown() << "\n";
        return ss.str();
    }

    void fight(Enemy enemy)
    {
        int enemyLevel = enemy.getLevel();
        int enemyDamage = enemy.getDamage();
        int knightLevel = getLevel();
        int knightHP = getHP();

        if (knightLevel > enemyLevel || getisArthur() || getisArthur())
        {
            // Knight wins
            if (knightLevel < 10)
            {
                setLevel(knightLevel + 1);
            }
        }
        else if (knightLevel == enemyLevel)
        {
            // Draw
            cout << "DRAW" << endl;
        }
        else
        {
            // Knight loses
            int newHP = knightHP - enemyDamage;
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
        int knightLevel = getLevel();
        int knightHP = getHP();

        if (knightLevel > shaman.getLevel() || getisArthur() || getisArthur())
        {
            // Knight wins
            if (knightLevel < 10)
            {
                setLevel(knightLevel + 2);
            }
        }
        else if (level == shaman.getLevel())
        {
            // Draw
        }
        else
        {
            // Lose
            if (getRemedy() > 0)
            {
                setRemedy(getRemedy() - 1);
            }
            else
            {
                // turn the knight into a dwarf for the next 3 events
                setisDwarf(true);
                setCountAffect(0);
                int newHP = HP / 5;
                if (HP < 5)
                {
                    newHP = 1;
                }
                else
                {
                    HP = newHP;
                }
            }
        }
    }

    void fight(Vajsh vajsh)
    {
        int knightLevel = getLevel();
        int knightHP = getHP();

        if (knightLevel > vajsh.getLevel() || getisArthur() || getisArthur())
        {
            // Knight wins
            if (knightLevel < 10)
            {
                setLevel(knightLevel + 1);
            }
        }
        else if (level == vajsh.getLevel())
        {
            // Draw
        }
        else
        {
            // Lose
            if (getMaidenKiss() > 0)
            {
                setMaidenKiss(getMaidenKiss() - 1);
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
    else
    {
        cout << "Error" << endl;
        return;
    }

    Knight knight(HP, level, remedy, maidenkiss, phoenixdown);

    cout << knight.toString() << endl;

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

        cout << knight.toString() << endl;

        if (knight.getHP() < 1)
        {
            cout << "Ngu vcc" << endl;
            return;
        }
    }
}