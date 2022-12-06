#include <algorithm>
#include <iostream>

#define free_ptr(p) if(p) delete p; p = nullptr;

//strategy 类，定义所有支持的算法的公共接口
class Strategy 
{
public:
    virtual ~Strategy() {};
    virtual void AlgorithmInterface() = 0;
};

//ConcretStrategy 封装具体的算法，继承子Strategy
class ConcreteStrategyA : public Strategy
{
    void AlgorithmInterface()
    {
        std::cout << "算法A实现" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    void AlgorithmInterface()
    {
        std::cout << "算法B实现" << std::endl;
    }
};

class ConcreteStrategyC : public Strategy
{
public:
    void AlgorithmInterface()
    {
        std::cout << "算法C实现" << std::endl;
    }
};


//context 用一个ConcreteStrategy来配置，维护一个对Strategy的引用
class Context
{
public:
    Context(Strategy* strategy) : m_strategy(strategy) { };
    ~Context() { free_ptr(m_strategy); }
    void AlgorithmInterface()
    {
        m_strategy->AlgorithmInterface();
    }
private:
    Strategy *m_strategy;
};

int main()
{
    Strategy* A = new ConcreteStrategyA();
    Strategy* B = new ConcreteStrategyB();
    Strategy* C = new ConcreteStrategyC();
    A->AlgorithmInterface();
    B->AlgorithmInterface();
    C->AlgorithmInterface();

    free_ptr(A);
    free_ptr(B);
    free_ptr(C);
    return 0;

}