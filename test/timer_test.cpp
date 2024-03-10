#include "timer.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockTimer : public Timer {
   public:
    MOCK_METHOD1(Start, void(int timeout_ms));
    MOCK_METHOD0(Stop, void());
    MOCK_CONST_METHOD0(IsRunning, bool());
};

TEST(MyTest, TimerExample) {
    MockTimer timer;

    // Set expectations on the mock timer
    EXPECT_CALL(timer, Start(1000)).Times(1);
    EXPECT_CALL(timer, Stop()).Times(1);
    EXPECT_CALL(timer, IsRunning()).WillOnce(testing::Return(true));

    // Use the mock timer in your code
    timer.Start(1000);
    EXPECT_TRUE(timer.IsRunning());
    timer.Stop();
}
