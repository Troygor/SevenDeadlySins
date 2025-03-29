#include <iostream>
#include <vector>
#ifndef PatternTemplates
#define PatternTemplates

using namespace std;

const size_t MaxSize = 5;

template<typename DS>
class Iterator
{
protected:
    Iterator() {}
public:
    virtual void FirstSin() {};
    virtual void NextSin() {};
    virtual bool LastSin() const {};
    virtual DS GetSin() const {};
};

template <typename DS>
class ArrayClass
{
private:
    DS Sins[MaxSize];
    size_t ArraySize;
public:
    void AddAndJump(DS newSin)
    {
        Sins[ArraySize++] = newSin;
    }
    size_t Size() const
    {
        return ArraySize;
    }
    DS GetSin(size_t i) const
    {
        return Sins[i];
    }
    ArrayClass() : ArraySize(0) {}
};

template <typename DS>
class VectorClass
{
private:
    vector <DS> Sins;
    size_t VectorSize;
public:
    void PushAndJump(DS newSin)
    {
        Sins.push_back(newSin);
        VectorSize++;
    }
    size_t Size() const
    {
        return VectorSize;
    }
    DS GetSin(size_t i) const
    {
        return Sins[i];
    }
    VectorClass() : VectorSize(0) {}
};

template<typename DS>
class ArrayIterator : public Iterator<DS>
{
private:
    const ArrayClass<DS> *ArraySins;
    size_t Position;
public:
    ArrayIterator(ArrayClass<DS> *SinsSins) : ArraySins(SinsSins), Position(0) {}
    void FirstSin()
    {
        Position = 0;
    }
    void NextSin()
    {
        Position++;
    }
    bool LastSin() const override
    {
        return (Position >= ArraySins->Size());
    }
    DS GetSin() const
    {
        return (ArraySins->GetSin(Position));
    }
};

template<typename DS>
class VectorIterator : public Iterator<DS>
{
private:
    const VectorClass<DS> *VectorSins;
    size_t Position;
public:
    VectorIterator(VectorClass<DS> *SinsSins) : VectorSins(SinsSins), Position(0) {}
    void FirstSin()
    {
        Position = 0;
    }
    void NextSin()
    {
        Position++;
    }
    bool LastSin() const
    {
        return (Position >= VectorSins->Size());
    }
    DS GetSin() const
    {
        return (VectorSins->GetSin(Position));
    }
};

#endif
