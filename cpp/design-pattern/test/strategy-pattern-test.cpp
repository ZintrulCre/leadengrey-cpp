#include "design-pattern/strategy-pattern.h"
#include "design-pattern/test/strategy-pattern-test.h"

void StrategyPatternTest()
{
    BaseStrategy* base_strategy_ptr;
    StrategyA strategy_a;
    StrategyB strategy_b;

    base_strategy_ptr = &strategy_a;
    base_strategy_ptr->StrategyImpl();
    
    base_strategy_ptr = &strategy_b;
    base_strategy_ptr->StrategyImpl();
}