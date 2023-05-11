#include <iostream>

#include "gtest_lite.h"
#include "memtrace.h"
#include "MVM.h"
/*
g++ -std=c++17 -g -DMEMTRACE -c memtrace.cpp -o memtrace.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c date.cpp -o date.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c contracts.cpp -o contracts.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c clients.cpp -o clients.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c MVM.cpp -o MVM.o
g++ -Wall -Werror -pedantic -std=c++17 -g -DMEMTRACE -c Test.cpp -o Test.o
g++ MVM.o memtrace.o date.o contracts.o clients.o Test.o -o runnable
 */

#define TST 2
// TEST 0: MyVector
// TEST 1: Client
// TEST 2: Contract


#define MEMTRACE_H
int main() {

#if TST > 0
    TEST(MyVector, Anya) {
        EXPECT_TRUE(0==1);
        EXPECT_FALSE(1==1);
    } END
#endif
#if TST > 1
    TEST(MVM, Apa) {
        MVM me=MVM();
        Person a("Jajecnik Marcell", 121833295);
        //Person* first=new Person("Jajecnik Marcell", 121833295);
        //me.addClient(first);
    }END
#endif

    return 0;
}
