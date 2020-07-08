TEST_CASE("Test knight generating path: (4, 4) -> (5, 2)")
{
    Knight knight(EMPTY, NONE);

    pair<int, int> start = {4, 4};
    pair<int, int> destination = {5, 2};

    vector<pair<int, int>> generatedPath;
    generatedPath = knight.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({5, 2});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test knight generating path: (4, 4) -> (2, 3)")
{
    Knight knight(EMPTY, NONE);

    pair<int, int> start = {4, 4};
    pair<int, int> destination = {2, 3};

    vector<pair<int, int>> generatedPath;
    generatedPath = knight.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({2, 3});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test knight generating path: (4, 4) -> (2, 5)")
{
    Knight knight(EMPTY, NONE);

    pair<int, int> start = {4, 4};
    pair<int, int> destination = {2, 5};

    vector<pair<int, int>> generatedPath;
    generatedPath = knight.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({2, 5});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test knight not generating path: (4, 4) -> (2, 2)")
{
    Knight knight(EMPTY, NONE);

    pair<int, int> start = {4, 4};
    pair<int, int> destination = {2, 2};

    vector<pair<int, int>> generatedPath;
    generatedPath = knight.generatePath(start, destination);

    CHECK(generatedPath.empty());
}

TEST_CASE("Test knight can access: (4, 5) -> (2, 4)")
{
    Knight knight(EMPTY, NONE);

    pair<int, int> start = {4, 5};
    pair<int, int> destination = {2, 4};
    CHECK(knight.isAccessible(start, destination));
}

TEST_CASE("Test knight can access: (3, 3) -> (1, 2)")
{
    Knight knight(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {1, 2};
    CHECK(knight.isAccessible(start, destination));
}

TEST_CASE("Test knight cannot access: (0, 1) -> (2, 3)")
{
    Knight knight(EMPTY, NONE);

    pair<int, int> start = {0, 1};
    pair<int, int> destination = {2, 3};
    CHECK(knight.isAccessible(start, destination) == false);
}