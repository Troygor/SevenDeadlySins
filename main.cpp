#include <iostream>
#include <vector>
#include "PatternTemplates.h"
#include <list>

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
    const char* GetNameOfSin()
    {
        return Sin;
    }
    const char* GetColourOfSin()
    {
        return Colour;
    }
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
    wcout << "�������� �� ����..." << endl;
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
    wcout << "�������� �� �����..." << endl;
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
    wcout << "�������� �� �������..." << endl;
    }
    void PrintSin() const
    {
        SevenDeadlySins::PrintSin();
        wcout << "� ��� ������ ������ ��������������� ������� >:(" << endl;
    }
};


// ������������ 2


enum class DeadlySinType : int
{
    Sloth = 1,
    Wrath = 2,
    Envy = 3
};

SevenDeadlySins *CreateDeadlySin (DeadlySinType CinSin)
{
    SevenDeadlySins *newDeadlySin = NULL;
    if (CinSin == DeadlySinType::Sloth)
    {
        newDeadlySin = new Sloth;
    }
    if (CinSin == DeadlySinType::Wrath)
    {
        newDeadlySin = new Wrath;
    }
    if (CinSin == DeadlySinType::Envy)
    {
        newDeadlySin = new Envy;
    }
    return newDeadlySin;
}

void PrintColourIterator(Iterator<SevenDeadlySins*> *sinsIter)
{
    for(sinsIter->FirstSin(); !sinsIter->LastSin(); sinsIter->NextSin())
    {
        SevenDeadlySins *topSin = sinsIter->GetSin();
        topSin->PrintColour();
    }
}


// ������������ 3


class NameOfSinDecorator : public Decorator<class SevenDeadlySins*>
{
private:
    const char* NameOfSin;
public:
    NameOfSinDecorator(Iterator<SevenDeadlySins*> *iter, const char* nameOfSin) : Decorator<SevenDeadlySins*>(iter), NameOfSin(nameOfSin) {}
    void FirstSin()
    {
        SinsIterator -> FirstSin();
        while(!SinsIterator -> LastSin() && SinsIterator -> GetSin() -> GetNameOfSin() != NameOfSin)
        {
            SinsIterator -> NextSin();
        }
    }
    void NextSin()
    {
        do
        {
        SinsIterator -> NextSin();
        }while(!SinsIterator -> LastSin() && SinsIterator -> GetSin() -> GetNameOfSin() != NameOfSin);
    }
};

class NotColourOfSinDecorator : public Decorator<class SevenDeadlySins*>
{
private:
    const char* ColourOfSin;
public:
    NotColourOfSinDecorator(Iterator<SevenDeadlySins*> *iter, const char* colourOfSin) : Decorator<SevenDeadlySins*>(iter), ColourOfSin(colourOfSin) {}
    void FirstSin()
    {
        SinsIterator -> FirstSin();
        while(!SinsIterator -> LastSin() && SinsIterator -> GetSin() -> GetColourOfSin() == ColourOfSin)
        {
            SinsIterator -> FirstSin();
        }
    }
    void NextSin()
    {
        do
        {
        SinsIterator -> NextSin();
        }while(!SinsIterator -> LastSin() && SinsIterator -> GetSin() -> GetColourOfSin() == ColourOfSin);
    }
};

class SecondSinDecorator : public Decorator<class SevenDeadlySins*>
{
public:
    SecondSinDecorator(Iterator<SevenDeadlySins*> *iter) : Decorator<SevenDeadlySins*>(iter) {}
    void NextSin()
    {
        SinsIterator -> NextSin();
        SinsIterator -> NextSin();
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    ArrayClass<SevenDeadlySins*> DeadlySinsArray;
    for(size_t i = 0; i<7; i++)
    {
        int randNum = rand()%3+1;
        DeadlySinType type = static_cast<DeadlySinType>(randNum);
        SevenDeadlySins *newDeadlySin2 = CreateDeadlySin(type);
        DeadlySinsArray.AddAndJump(newDeadlySin2);
    }
    wcout << "������ ������� ������: " << DeadlySinsArray.Size() << endl;
    wcout << "������ ��������" << endl;
    Iterator<SevenDeadlySins*> *sinsIter = DeadlySinsArray.GetIterator();
    PrintColourIterator(sinsIter);
    delete sinsIter;
    wcout << "����� ����" << endl;
    Iterator<SevenDeadlySins*> *sinsIter2 = new NameOfSinDecorator(DeadlySinsArray.GetIterator(), "sloth");
    PrintColourIterator(sinsIter2);
    delete sinsIter2;
    wcout << "����� ������, �� ��������������� � ������� ������" << endl;
    Iterator<SevenDeadlySins*> *sinsIter3 = new NotColourOfSinDecorator(DeadlySinsArray.GetIterator(), "red");
    PrintColourIterator(sinsIter3);
    delete sinsIter3;
     wcout << "����� �������� ������" << endl;
    Iterator<SevenDeadlySins*> *sinsIter4 = new SecondSinDecorator(DeadlySinsArray.GetIterator());
    PrintColourIterator(sinsIter4);
    delete sinsIter4;
    wcout << "����� �������� ������, �� ��������������� � ������� ������" << endl;
    Iterator<SevenDeadlySins*> *sinsIter5 = new NotColourOfSinDecorator(new SecondSinDecorator(DeadlySinsArray.GetIterator()), "red");
    PrintColourIterator(sinsIter5);
    delete sinsIter5;
    wcout << "..." << endl;
    list<SevenDeadlySins*> DeadlySinsList;
    for(size_t i = 0; i<7; i++)
    {
        int randNum = rand()%3+1;
        DeadlySinType type = static_cast<DeadlySinType>(randNum);
        SevenDeadlySins *newDeadlySin3 = CreateDeadlySin(type);
        DeadlySinsList.push_back(newDeadlySin3);
    }
    Iterator<SevenDeadlySins*> *adaptedSinsIter = new Adapter<list<SevenDeadlySins*>, SevenDeadlySins*>(&DeadlySinsList);
    wcout << "����� ������, �� ��������������� � ������� ������" << endl;
    Iterator<SevenDeadlySins*> *sinsIter6 = new NotColourOfSinDecorator(adaptedSinsIter, "green");
    PrintColourIterator(sinsIter6);
    delete sinsIter6;
    return 0;
}







// � main
// ������������ 1
//    SevenDeadlySins DeadlySin("greed", 7, "yellow");
//    DeadlySin.PrintNumberOfSins();
//    DeadlySin.PrintSin();
//    Wrath WrathSin;
//    WrathSin.PrintSin();
//    Envy EnvySin;
//    EnvySin.PrintSin();
//    EnvySin.~Envy();
//    Sloth SlothSin;
//    SlothSin.PrintSin();
//    SlothSin.SetSinColour("cyan");
//    SevenDeadlySins *newDeadlySin = new Sloth;
//    newDeadlySin->PrintSin();
//    newDeadlySin->SetSinColour("cyan");
//    delete newDeadlySin;

// ������������ 2
//    wcout << "����� ���� �� ������ �������?(���� - 1, ���� - 2, ������� - 3)" << endl;
//    int i;
//    cin >> i;
//    DeadlySinType in;
//    in = static_cast<DeadlySinType>(i);
//    SevenDeadlySins *newDeadlySin = CreateDeadlySin(in);
//    newDeadlySin->PrintSin();
//    delete newDeadlySin;
//    size_t N;
//    cout << endl;
//    wcout << "������� ���������� ������" << endl;
//    cin >> N;
//    ArrayClass<Sloth> SlothArray;
//    for(size_t i = 0; i<N; i++)
//    {
//        Sloth newSloth;
//        SlothArray.AddAndJump(newSloth);
//    }
//    wcout << "������ ������� ����: " << SlothArray.Size() << endl;
//    Iterator<Sloth> *slothIter = new ArrayIterator(&SlothArray);
//    for(slothIter->FirstSin(); !slothIter->LastSin(); slothIter->NextSin())
//    {
//        Sloth abc = slothIter->GetSin();
//        abc.PrintSin();
//    }
//    ArrayClass<SevenDeadlySins*> DeadlySinsArray;
//    for(size_t i = 0; i<N; i++)
//    {
//        int randNum = rand()%3+1;
//        DeadlySinType type = static_cast<DeadlySinType>(randNum);
//        SevenDeadlySins *newDeadlySin2 = CreateDeadlySin(type);
//        DeadlySinsArray.AddAndJump(newDeadlySin2);
//    }
//    wcout << "������ ������� ������: " << DeadlySinsArray.Size() << endl;
//    Iterator<SevenDeadlySins*> *sinsIter = new ArrayIterator(&DeadlySinsArray);
//    PrintColourIterator(sinsIter);
//    delete sinsIter;
//    cout << endl;
//    VectorClass<SevenDeadlySins*> DeadlySinsVector;
//    for(size_t i = 0; i<N; i++)
//    {
//        int randNum = rand()%3+1;
//        DeadlySinType type = static_cast<DeadlySinType>(randNum);
//        SevenDeadlySins *newDeadlySin3 = CreateDeadlySin(type);
//        DeadlySinsVector.PushAndJump(newDeadlySin3);
//    }
//    wcout << "������ ������� ������: " << DeadlySinsVector.Size() << endl;
//    Iterator<SevenDeadlySins*> *sinsIter2 = new VectorIterator(&DeadlySinsVector);
//    PrintColourIterator(sinsIter2);
//    delete sinsIter2;
