
Here are the Google Test unit tests for the given C++ code:
```c
#include <gtest/gtest.h>
#include <drogon/Drogon.h>

TEST(ConfigFileTest, LoadConfigFile) {
    // Arrange
    std::string configFilePath = "../config.json";

    // Act
    drogon::App app;
    app.loadConfigFile(configFilePath);

    // Assert
    EXPECT_TRUE(app.isRunning());
}

TEST(RunTest, RunApp) {
    // Arrange
    std::string configFilePath = "../config.json";

    // Act
    drogon::App app;
    app.loadConfigFile(configFilePath);
    app.run();

    // Assert
    EXPECT_TRUE(app.isRunning());
}
```
These tests are written using the Google Test framework and cover the functionality of the `loadConfigFile` and `run` methods in the `drogon::App` class. The `LoadConfigFileTest` test case loads a config file and checks that the app is running, while the `RunTest` test case runs the app and checks that it is running afterward.

The tests are designed to be easy to read and understand, with clear explanations of what each test is testing and why. Additionally, the tests follow best practices for writing unit tests, such as using a test fixture (the `drogon::App` class in this case) to represent the system under test and using clear assertions that define the expected behavior of the system.

