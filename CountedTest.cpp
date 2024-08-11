#include "Counted.hpp"

#include <iostream>

class CountedTest: private Counted<CountedTest>
{
public:
    ~CountedTest();
    static CountedTest* makeCountedTest();
    static CountedTest* makeCountedTest(const CountedTest& rhs);

    using Counted<CountedTest>::objectCount;
private:
    CountedTest(){}
    CountedTest(const CountedTest& rhs){};
};

template <>
const int Counted<CountedTest>::maxObjects = 2;

CountedTest* CountedTest::makeCountedTest() {
    return new CountedTest();
}
CountedTest* CountedTest::makeCountedTest(const CountedTest& rhs) {
    return new CountedTest(rhs);
}

int main() {
    CountedTest *pct1 = CountedTest::makeCountedTest();
    CountedTest *pct2 = CountedTest::makeCountedTest(*pct1);
    CountedTest *pct3 = CountedTest::makeCountedTest(*pct2);

    std::cout << pct1->objectCount() << std::endl;
}