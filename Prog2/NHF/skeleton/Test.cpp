#include <iostream>

#include "gtest_lite.h"
#include "memtrace.h"

/*
g++ -std=c++17 -g -DMEMTRACE -c memtrace.cpp -o memtrace.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c date.cpp -o date.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c contracts.cpp -o contracts.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c clients.cpp -o clients.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c MVM.cpp -o MVM.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c Test.cpp -o Test.o
g++ MVM.o memtrace.o date.o contracts.o clients.o Test.o -o runnable
 */

#define TST 1
// TEST 0: MyVector
// TEST 1: Client
// TEST 2: Contract



int main() {

#if TST > 0
    TEST(MyVector, ) {
        EXPECT_TRUE(0==1);
        EXPECT_FALSE(1==1);
    } END
#endif
#if TST > 1
    TEST() {

    }END
#endif

    return 0;
}
