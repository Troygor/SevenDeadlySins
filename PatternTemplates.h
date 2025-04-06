#include <iostream>
#include <vector>
#ifndef PatternTemplates
#define PatternTemplates

using namespace std;

const size_t MaxSize = 7;

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

template<typename DS>
class ArrayIterator : public Iterator<DS>
{
private:
    const DS *ArraySins;
    size_t Position;
    size_t ArraySize;
public:
    ArrayIterator(DS *SinsSins, size_t arraySize) : ArraySins(SinsSins), ArraySize(arraySize), Position(0) {}
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
        return (Position >= ArraySize);
    }
    DS GetSin() const
    {
        return ArraySins[Position];
    }
};

template<typename DS>
class VectorIterator : public Iterator<DS>
{
private:
    const DS *VectorSins;
    size_t Position;
    size_t VectorSize;
public:
    VectorIterator(DS *SinsSins, size_t vectorSize) : VectorSins(SinsSins), VectorSize(vectorSize), Position(0) {}
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
        return (Position >= VectorSize);
    }
    DS GetSin() const
    {
        return VectorSins[Position];
    }
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
    class Iterator<DS> *GetIterator()
    {
        return new ArrayIterator(Sins, ArraySize);
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
    class Iterator<DS> *GetIterator()
    {
        return new VectorIterator(Sins, VectorSize);
    }
    VectorClass() : VectorSize(0) {}
};

template <typename DS>
class Decorator : public Iterator<DS>
{
protected:
    Iterator<DS> *SinsIterator;
public:
    Decorator(Iterator<DS> *Iter) : SinsIterator(Iter) {}
    virtual void FirstSin()
    {
        SinsIterator -> FirstSin();
    }
    virtual void NextSin()
    {
        SinsIterator -> NextSin();
    }
    virtual bool LastSin() const
    {
        return SinsIterator -> LastSin();
    }
    virtual DS GetSin() const
    {
        return SinsIterator -> GetSin();
    }
};

template<typename ContType, typename DS>
class Adapter : public Iterator<DS>
{
protected:
    ContType *Container;
    typename ContType::const_iterator Iter;
public:
    Adapter(ContType *container) : Container(container) {}
    virtual void FirstSin()
    {
        Iter = Container->begin();
    }
    virtual void NextSin()
    {
        Iter++;
    }
    virtual bool LastSin() const
    {
        return (Iter == Container->end());
    }
    virtual DS GetSin() const
    {
        return *Iter;
    }
};
#endif
