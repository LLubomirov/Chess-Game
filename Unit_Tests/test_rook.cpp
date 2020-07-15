TEST_CASE("Test rook generating path: (7, 0) -> (3, 0)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {7, 0};
    pair<int, int> destination = {3, 0};

    vector<pair<int, int>> generatedPath;
    generatedPath = rook.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({6, 0});
    correctPath.push_back({5, 0});
    correctPath.push_back({4, 0});
    correctPath.push_back({3, 0});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test rook generating path: (4, 3) -> (4, 1)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {4, 3};
    pair<int, int> destination = {4, 1};

    vector<pair<int, int>> generatedPath;
    generatedPath = rook.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({4, 2});
    correctPath.push_back({4, 1});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test rook not generating path: (3, 3) -> (5, 5)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {5, 5};

    vector<pair<int, int>> generatedPath;
    generatedPath = rook.generatePath(start, destination);

    CHECK(generatedPath.empty());
}

TEST_CASE("Test rook can access: (3, 3) -> (3, 6)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 6};
    CHECK(rook.isAccessible(start, destination));
}

TEST_CASE("Test rook can access: (2, 1) -> (2, 5)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {2, 1};
    pair<int, int> destination = {2, 5};
    CHECK(rook.isAccessible(start, destination));
}

TEST_CASE("Test rook cannot access: (3, 3) -> (2, 6)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 6};
    CHECK(rook.isAccessible(start, destination) == false);
}

TEST_CASE("Test rook is on horizontal move (3, 3) -> (3, 6)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 6};
    CHECK(rook.isHorizontalMove(start, destination));
}

TEST_CASE("Test rook is on horizontal move (3, 3) -> (3, 1)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 1};
    CHECK(rook.isHorizontalMove(start, destination));
}

TEST_CASE("Test rook is not on horizontal move (3, 3) -> (4, 1)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {4, 1};
    CHECK(rook.isHorizontalMove(start, destination) == false);
}

TEST_CASE("Test rook is on vertical move (2, 4) -> (5, 4)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {2, 4};
    pair<int, int> destination = {5, 4};
    CHECK(rook.isVerticalMove(start, destination));
}

TEST_CASE("Test rook is on vertical move (2, 4) -> (0, 4)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {2, 4};
    pair<int, int> destination = {0, 4};
    CHECK(rook.isVerticalMove(start, destination));
}

TEST_CASE("Test rook is not on vertical move (3, 3) -> (3, 5)")
{
    Rook rook(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 5};
    CHECK(rook.isVerticalMove(start, destination) == false);
}