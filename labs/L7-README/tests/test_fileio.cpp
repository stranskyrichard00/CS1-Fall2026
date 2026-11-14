#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/fileio.hpp"

#include <climits>
#include <fstream>
#include <iterator>
#include <stdexcept>

using namespace std;

// Run tests from the fileio project root.
// Temporary test files are written into build/.
namespace {

void createFile(const string& filename, const string& contents) {
    ofstream output(filename);
    REQUIRE(output.is_open());

    output << contents;
    output.close();

    REQUIRE_FALSE(output.fail());
}

string readFile(const string& filename) {
    ifstream input(filename);
    REQUIRE(input.is_open());

    return string(
        istreambuf_iterator<char>(input),
        istreambuf_iterator<char>()
    );
}

}

TEST_CASE("Read the input test file") {
    vector<int> numbers;

    REQUIRE(readNumbers("data/test_input.txt", numbers));

    const vector<int> expected{
        12, -5, 8, 20, 0, 15, -10, 7, 3, 10
    };

    CHECK(numbers == expected);
}

TEST_CASE("Calculate statistics for mixed numbers") {
    const vector<int> numbers{
        12, -5, 8, 20, 0, 15, -10, 7, 3, 10
    };

    CHECK(findMaximum(numbers) == 20);
    CHECK(findMinimum(numbers) == -10);
    CHECK(calculateSum(numbers) == 60);
    CHECK(calculateAverage(numbers) == doctest::Approx(6.0));
}

TEST_CASE("All numbers are negative") {
    const vector<int> numbers{-8, -2, -10};

    CHECK(findMaximum(numbers) == -2);
    CHECK(findMinimum(numbers) == -10);
    CHECK(calculateSum(numbers) == -20);
    CHECK(calculateAverage(numbers) == doctest::Approx(-20.0 / 3.0));
}

TEST_CASE("A single number") {
    const vector<int> numbers{7};

    CHECK(findMaximum(numbers) == 7);
    CHECK(findMinimum(numbers) == 7);
    CHECK(calculateSum(numbers) == 7);
    CHECK(calculateAverage(numbers) == doctest::Approx(7.0));
}

TEST_CASE("Average retains its fractional part") {
    CHECK(calculateAverage({1, 2}) == doctest::Approx(1.5));
}

TEST_CASE("Sum can exceed the int range") {
    const vector<int> numbers{INT_MAX, INT_MAX};

    CHECK(calculateSum(numbers) == 2LL * INT_MAX);
}

TEST_CASE("Empty data is handled explicitly") {
    const vector<int> numbers;

    CHECK(calculateSum(numbers) == 0);
    CHECK_THROWS_AS(findMaximum(numbers), invalid_argument);
    CHECK_THROWS_AS(findMinimum(numbers), invalid_argument);
    CHECK_THROWS_AS(calculateAverage(numbers), invalid_argument);
    CHECK_FALSE(writeResults("build/empty_output.txt", numbers));
}

TEST_CASE("Invalid input preserves existing data") {
    const string filename = "data/invalid_input.txt";
    vector<int> numbers{42};
    const vector<int> original{42};

    SUBCASE("Too few integers") {
        createFile(filename, "3\n1 2\n");
    }

    SUBCASE("Too many integers") {
        createFile(filename, "2\n1 2 3\n");
    }

    SUBCASE("Non-integer value") {
        createFile(filename, "3\n1 hello 3\n");
    }

    SUBCASE("Zero count") {
        createFile(filename, "0\n");
    }

    SUBCASE("Negative count") {
        createFile(filename, "-2\n1 2\n");
    }

    SUBCASE("Invalid count") {
        createFile(filename, "hello\n1 2\n");
    }

    CHECK_FALSE(readNumbers(filename, numbers));
    CHECK(numbers == original);
}

TEST_CASE("Missing input file") {
    vector<int> numbers;

    CHECK_FALSE(
        readNumbers("build/missing_directory/input.txt", numbers)
    );
}

TEST_CASE("Write results in the expected format") {
    const vector<int> numbers{
        12, -5, 8, 20, 0, 15, -10, 7, 3, 10
    };

    const string filename = "data/unit_output.txt";

    REQUIRE(writeResults(filename, numbers));

    const string expected =
        "Count: 10\n"
        "Numbers: 12 -5 8 20 0 15 -10 7 3 10\n"
        "Maximum: 20\n"
        "Minimum: -10\n"
        "Sum: 60\n"
        "Average: 6.00\n";

    CHECK(readFile(filename) == expected);
}

TEST_CASE("Invalid output location") {
    CHECK_FALSE(
        writeResults("build/missing_directory/output.txt", {1, 2})
    );
}

TEST_CASE("Delete loaded data") {
    vector<int> numbers{1, 2, 3};

    deleteData(numbers);

    CHECK(numbers.empty());

    // Deleting empty data should also be safe.
    deleteData(numbers);

    CHECK(numbers.empty());
}