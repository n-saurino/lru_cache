#include <gtest/gtest.h>
#include "LRUCache.hpp"
// Include your application headers if needed
// #include "my_application.h"

int main(int argc, char **argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    // Run all tests
    return RUN_ALL_TESTS();

    // If you want to conditionally execute your application logic, uncomment below:
    /*
    // Run your application logic when not testing
    // MyApplication app;
    // return app.run(argc, argv);
    */
}
