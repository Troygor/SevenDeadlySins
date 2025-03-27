#include <iostream>

using namespace std;

class SevenDeadlySins
{
private:
    int Sins;
protected:
    const char* Sin;
    const char* Colour; // Олицетворение грехов в виде цветов // Жадность - желтый, Зависть - зеленый, Гнев - красный, Лень - годубой, Похоть - розовый. Чревоугодие и Гордыня?
public:
    SevenDeadlySins(const char* a, int b, const char* c);
    virtual ~SevenDeadlySins();
    virtual void PrintSin() const;
    void PrintColour() const;
    void PrintNumberOfSins() const;
    void SetSinColour(const char* a);
};

SevenDeadlySins::SevenDeadlySins(const char* a, int b, const char* c) : Sin(a), Sins(b), Colour(c){}

SevenDeadlySins::~SevenDeadlySins()
{
    wcout << "Очищение..." << endl;
}

void SevenDeadlySins::PrintSin() const
{
    cout << "Грех:" << Sin << endl;
}

void SevenDeadlySins::PrintColour() const
{
    cout << "Цвет, олицетворяющий грех:" << Colour << endl;
}

void SevenDeadlySins::PrintNumberOfSins() const
{
    wcout << "Всего смертных грехов:" << Sins << endl;
}

void SevenDeadlySins::SetSinColour(const char* a)
{
    printf("Мне не нравится ассоциация греха %s с цветом %s. Поменяем его на новый цвет:%s\n", Sin, Colour, a);
    Colour = a;
}


class Sloth : public SevenDeadlySins
{
public:
    Sloth();
    ~Sloth();
    void PrintSin() const;
    void SetSinColour(const char* a);
};

Sloth::Sloth(): SevenDeadlySins("sloth", 7, "blue")
{
    wcout << "Появляется лень..." << endl;
}

Sloth::~Sloth()
{
    wcout << "Очищение..." << endl;
}

void Sloth::PrintSin() const
{
    wcout << "Мне лень выводить этот грех" << endl;
}

void Sloth::SetSinColour(const char* a)
{
    wcout << "Не буду я менять цвет" << endl;
}

class Wrath : public SevenDeadlySins
{
private:
    int LevelOfWrath;
public:
    Wrath();
    ~Wrath();
    void PrintSin() const;
};

Wrath::Wrath(): SevenDeadlySins("wrath", 7, "red")
{
    wcout << "Появляется злость..." << endl;
}

Wrath::~Wrath()
{
    wcout << "Очищение..." << endl;
}

void Wrath::PrintSin() const
{
    for(int LevelOfWrath = 1; LevelOfWrath < 6; LevelOfWrath++)
    {
        cout << Sin;
        for(int j = 1; j <= LevelOfWrath; j++)
        {
            cout << "!";
        }
        wcout << " Уровень гнева:" << LevelOfWrath << endl;
    }
}


class Envy : public SevenDeadlySins
{
public:
    Envy(): SevenDeadlySins("envy", 7, "green")
    {
        wcout << "Появляется зависть..." << endl;
    }
    ~Envy()
    {
    wcout << "Очищение..." << endl;
    }
    void PrintSin() const
    {
        SevenDeadlySins::PrintSin();
        wcout << "А вот другие классы реализовывались снаружи >:(" << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    SevenDeadlySins DeadlySin("greed", 7, "yellow");
    DeadlySin.PrintNumberOfSins();
    DeadlySin.PrintSin();
    Wrath WrathSin;
    WrathSin.PrintSin();
    Envy EnvySin;
    EnvySin.PrintSin();
    EnvySin.~Envy();
    Sloth SlothSin;
    SlothSin.PrintSin();
    SlothSin.SetSinColour("cyan");
    SevenDeadlySins *newDeadlySin = new Sloth;
    newDeadlySin->PrintSin();
    newDeadlySin->SetSinColour("cyan");
    delete newDeadlySin;
    wcout << "Да откуда их тут столько" << endl;
    return 0;
}
