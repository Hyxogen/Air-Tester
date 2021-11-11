//
// Created by Daan Meijer on 11/11/21.
//

#ifndef INTERNALAIRTESTER_H
#define INTERNALAIRTESTER_H

#define AIRTEST_TEST_CLASS_NAME(group, test) group##_##test##_test

#define AIRTEST_TEST_(group, test, parent) \
class AIRTEST_TEST_CLASS_NAME(group, test) : public parent { \
public:                                   \
        AIRTEST_TEST_CLASS_NAME(group, test)() = default;                \
        ~AIRTEST_TEST_CLASS_NAME(group, test)() = default;             \
                                           \
        void TestBody() override;\
};                                   \
void AIRTEST_TEST_CLASS_NAME(group, test)::TestBody()
#endif //INTERNALAIRTESTER_H