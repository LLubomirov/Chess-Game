TEST_CASE("Test queen generating path: (3, 3) -> (7, 7)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {7, 7};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({4, 4});
    correctPath.push_back({5, 5});
    correctPath.push_back({6, 6});
    correctPath.push_back({7, 7});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen generating path: (3, 3) -> (3, 0)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 0};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({3, 2});
    correctPath.push_back({3, 1});
    correctPath.push_back({3, 0});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen not generating path: (3, 3) -> (2, 7)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 7};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generatePath(start, destination);

    CHECK(generatedPath.empty());
}

TEST_CASE("Test queen can access: (3, 3) -> (3, 5)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 5};
    CHECK(queen.isAccessible(start, destination));
}

TEST_CASE("Test queen can access: (4, 5) -> (2, 3)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {4, 5};
    pair<int, int> destination = {2, 3};
    CHECK(queen.isAccessible(start, destination));
}

TEST_CASE("Test queen cannot access: (6, 2) -> (3, 3)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {6, 2};
    pair<int, int> destination = {3, 3};
    CHECK(queen.isAccessible(start, destination) == false);
}

TEST_CASE("Test queen is on straight move: (3, 3) -> (3, 1)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 1};
    CHECK(queen.isStraightMove(start, destination));
}

TEST_CASE("Test queen is on straight move: (3, 3) -> (6, 3)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {6, 3};
    CHECK(queen.isStraightMove(start, destination));
}

TEST_CASE("Test queen is not on straight move: (3, 3) -> (2, 7)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 7};
    CHECK(queen.isStraightMove(start, destination) == false);
}

TEST_CASE("Test queen is on horizontal move: (3, 3) -> (3, 6)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 6};
    CHECK(queen.isHorizontalMove(start, destination));
}

TEST_CASE("Test queen is on horizontal move: (3, 3) -> (3, 2)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 2};
    CHECK(queen.isHorizontalMove(start, destination));
}

TEST_CASE("Test queen is not on horizontal move: (3, 3) -> (4, 6)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {4, 6};
    CHECK(queen.isHorizontalMove(start, destination) == false);
}

TEST_CASE("Test queen is on vertical move: (3, 3) -> (5, 3)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {5, 3};
    CHECK(queen.isVerticalMove(start, destination));
}

TEST_CASE("Test queen is on vertical move: (3, 3) -> (2, 3)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 3};
    CHECK(queen.isVerticalMove(start, destination));
}

TEST_CASE("Test queen is not on vertical move: (3, 3) -> (5, 2)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {5, 2};
    CHECK(queen.isVerticalMove(start, destination) == false);
}

TEST_CASE("Test queen is on diagonal move: (2, 2) -> (7, 7)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {2, 2};
    pair<int, int> destination = {7, 7};
    CHECK(queen.isDiagonalMove(start, destination));
}

TEST_CASE("Test queen is on diagonal move: (3, 0) -> (0, 3)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 0};
    pair<int, int> destination = {0, 3};
    CHECK(queen.isDiagonalMove(start, destination));
}

TEST_CASE("Test queen is on diagonal move: (3, 3) -> (5, 1)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {5, 1};
    CHECK(queen.isDiagonalMove(start, destination));
}

TEST_CASE("Test queen is on diagonal move: (3, 5) -> (0, 2)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 5};
    pair<int, int> destination = {0, 2};
    CHECK(queen.isDiagonalMove(start, destination));
}

TEST_CASE("Test queen is not on diagonal move: (1, 4) -> (5, 5)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {1, 4};
    pair<int, int> destination = {5, 5};
    CHECK(queen.isDiagonalMove(start, destination) == false);
}

TEST_CASE("Test queen generating path with helper: (3, 3) -> (7, 7)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {7, 7};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generatePathHelper(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({4, 4});
    correctPath.push_back({5, 5});
    correctPath.push_back({6, 6});
    correctPath.push_back({7, 7});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen generating path with helper: (3, 3) -> (3, 0)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 0};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generatePathHelper(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({3, 2});
    correctPath.push_back({3, 1});
    correctPath.push_back({3, 0});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen generating straight path: (6, 6) -> (3, 6)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {6, 6};
    pair<int, int> destination = {3, 6};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generateStraightPath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({5, 6});
    correctPath.push_back({4, 6});
    correctPath.push_back({3, 6});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen generating horizontal path: (6, 6) -> (6, 4)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {6, 6};
    pair<int, int> destination = {6, 4};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generateHorizontalPath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({6, 5});
    correctPath.push_back({6, 4});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen generating horizontal path: (5, 2) -> (5, 0)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {5, 2};
    pair<int, int> destination = {5, 0};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generateHorizontalPath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({5, 1});
    correctPath.push_back({5, 0});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen generating vertical path: (6, 6) -> (4, 6)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {6, 6};
    pair<int, int> destination = {4, 6};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generateVerticalPath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({5, 6});
    correctPath.push_back({4, 6});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen generating vertical path: (2, 5) -> (0, 5)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {2, 5};
    pair<int, int> destination = {0, 5};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generateVerticalPath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({1, 5});
    correctPath.push_back({0, 5});
    
    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen generating diagonal path: (2, 2) -> (0, 4)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {2, 2};
    pair<int, int> destination = {0, 4};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generateDiagonalPath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({1, 3});
    correctPath.push_back({0, 4});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test queen generating diagonal path: (3, 5) -> (5, 3)")
{
    Queen queen(EMPTY, NONE);

    pair<int, int> start = {3, 5};
    pair<int, int> destination = {5, 3};

    vector<pair<int, int>> generatedPath;
    generatedPath = queen.generateDiagonalPath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({4, 4});
    correctPath.push_back({5, 3});

    CHECK(generatedPath == correctPath);
}