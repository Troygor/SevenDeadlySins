#include <iostream>

using namespace std;

class SevenDeadlySins
{
private:
    int Sins;
protected:
    const char* Sin;
    const char* Colour; // ������������� ������ � ���� ������ // �������� - ������, ������� - �������, ���� - �������, ���� - �������, ������ - �������. ����������� � �������?
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
    wcout << "��������..." << endl;
}

void SevenDeadlySins::PrintSin() const
{
    cout << "����:" << Sin << endl;
}

void SevenDeadlySins::PrintColour() const
{
    cout << "����, �������������� ����:" << Colour << endl;
}

void SevenDeadlySins::PrintNumberOfSins() const
{
    wcout << "����� �������� ������:" << Sins << endl;
}

void SevenDeadlySins::SetSinColour(const char* a)
{
    printf("��� �� �������� ���������� ����� %s � ������ %s. �������� ��� �� ����� ����:%s\n", Sin, Colour, a);
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
    wcout << "���������� ����..." << endl;
}

Sloth::~Sloth()
{
    wcout << "��������..." << endl;
}

void Sloth::PrintSin() const
{
    wcout << "��� ���� �������� ���� ����" << endl;
}

void Sloth::SetSinColour(const char* a)
{
    wcout << "�� ���� � ������ ����" << endl;
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
    wcout << "���������� ������..." << endl;
}

Wrath::~Wrath()
{
    wcout << "��������..." << endl;
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
        wcout << " ������� �����:" << LevelOfWrath << endl;
    }
}


class Envy : public SevenDeadlySins
{
public:
    Envy(): SevenDeadlySins("envy", 7, "green")
    {
        wcout << "���������� �������..." << endl;
    }
    ~Envy()
    {
    wcout << "��������..." << endl;
    }
    void PrintSin() const
    {
        SevenDeadlySins::PrintSin();
        wcout << "� ��� ������ ������ ��������������� ������� >:(" << endl;
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
    wcout << "�� ������ �� ��� �������" << endl;
    return 0;
}
