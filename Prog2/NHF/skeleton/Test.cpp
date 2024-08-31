#include <iostream>

#include "gtest_lite.h"
#include "memtrace.h"
#include "MVM.h"

/**
*@brief Teszt makro vezerli a vegrehajtando tesztesetek szamat.
*/
#define TST 2
// TEST 1: MyVector
// TEST 2: Contract_date
// TEST 3: Contract


#define MEMTRACE_H
int main() {

#if TST > 0
    TEST(MyVector, tesztek) {
        MyVector<int> int_test;
        MyVector<double> double_test;
        EXPECT_EQ(10, int_test.capacity()); // Alapertelmezett ertek
        EXPECT_EQ(0, int_test.size());
        int_test.push_back(1);
        EXPECT_EQ(1, int_test.size());
        int_test.pop_back();
        EXPECT_EQ(0, int_test.size());
        int_test.pop_back(); //Torles ha nincs semmi bajt okoz-e?

        for(size_t i = 0; i < 11; ++i) {
            int_test.push_back(i);
            double_test.push_back(i);
        }
        EXPECT_EQ(20, int_test.capacity());
        EXPECT_EQ(11, int_test.size());

        for(size_t i = 0; i < 11; ++i) {
            int_test.erase(0);
            double_test.pop_back();
        }

        EXPECT_EQ(0, int_test.size());
        EXPECT_EQ(0, double_test.size());

        for (size_t i = 0; i < 5; ++i) {
            int_test.push_back(i);
        }
        for (size_t i = 0; i < 5; i++)
        {
            EXPECT_EQ(i, int_test[i]);
        }
        EXPECT_THROW(int_test[-1], std::range_error);
        EXPECT_THROW(int_test[5], std::range_error);

    } END
#endif
#if TST > 1
    TEST(Contract_date, tesztek) {
        // class Date(day, month, year)
        // Contract_date(Date begin(day, month, year), Date end(day, month, year))


    }END
#endif

    return 0;
}
