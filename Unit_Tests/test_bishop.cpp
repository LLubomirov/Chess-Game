TEST_CASE("Test bishop generating path: (3, 3) -> (7, 7)")
{
    Bishop bishop(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {7, 7};

    vector<pair<int, int>> generatedPath;
    generatedPath = bishop.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({4, 4});
    correctPath.push_back({5, 5});
    correctPath.push_back({6, 6});
    correctPath.push_back({7, 7});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test bishop generating path: (5, 3) -> (2, 0)")
{
    Bishop bishop(EMPTY, NONE);

    pair<int, int> start = {5, 3};
    pair<int, int> destination = {2, 0};

    vector<pair<int, int>> generatedPath;
    generatedPath = bishop.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({4, 2});
    correctPath.push_back({3, 1});
    correctPath.push_back({2, 0});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test bishop generating path: (4, 6) -> (6, 4)")
{
    Bishop bishop(EMPTY, NONE);

    pair<int, int> start = {4, 6};
    pair<int, int> destination = {6, 4};

    vector<pair<int, int>> generatedPath;
    generatedPath = bishop.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({5, 5});
    correctPath.push_back({6, 4});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test bishop not generating path: (4, 6) -> (3, 4)")
{
    Bishop bishop(EMPTY, NONE);

    pair<int, int> start = {4, 6};
    pair<int, int> destination = {3, 4};

    vector<pair<int, int>> generatedPath;
    generatedPath = bishop.generatePath(start, destination);

    CHECK(generatedPath.empty());
}

TEST_CASE("Test bishop can access: (4, 5) -> (2, 3)")
{
    Bishop bishop(EMPTY, NONE);

    pair<int, int> start = {4, 5};
    pair<int, int> destination = {2, 3};
    CHECK(bishop.isAccessible(start, destination));
}

TEST_CASE("Test bishop can access: (3, 3) -> (7, 7)")
{
    Bishop bishop(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {7, 7};
    CHECK(bishop.isAccessible(start, destination));
}

TEST_CASE("Test bishop cannot access: (0, 1) -> (3, 3)")
{
    Bishop bishop(EMPTY, NONE);

    pair<int, int> start = {0, 1};
    pair<int, int> destination = {3, 3};
    CHECK(bishop.isAccessible(start, destination) == false);
}

