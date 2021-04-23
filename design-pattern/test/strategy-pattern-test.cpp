#include "design-pattern/strategy-pattern.h"
#include "design-pattern/test/strategy-pattern-test.h"

void StrategyPatternTest()
{
    BaseStrategy<int>* base_strategy_ptr;
    StrategyA<int> strategy_a;
    StrategyB<int> strategy_b;

    base_strategy_ptr = &strategy_a;
    base_strategy_ptr->StrategyImpl();
    
    base_strategy_ptr = &strategy_b;
    base_strategy_ptr->StrategyImpl();
}