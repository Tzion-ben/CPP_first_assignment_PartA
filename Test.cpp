/*
* AUTHORS: <Tzion Beniaminov>
* Tests for drawing a Snowman fon input 8 digits nmber
* in range of 11111111 to 44444444 
*/

#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <algorithm>

using namespace std;
using namespace ariel;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {
    //first HAT tests
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11322423)) == nospaces("_===_\n\(O,o)\n(] [)\n(___)"));
    CHECK(nospaces(snowman(11221111)) == nospaces("_===_\n(o,o)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(12444444)) == nospaces("_===_\n(-.-)\n(   )\n(   )"));   
    CHECK(nospaces(snowman(12222313)) == nospaces("_===_\n\(o.o)\n( : )\\n(___)"));
    CHECK(nospaces(snowman(12112111)) == nospaces("_===_\n\(...)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(13443234)) == nospaces("_===_\n(-_-)/\n\(> <)\n(   )"));
    CHECK(nospaces(snowman(13323324)) == nospaces("_===_\n(O_o)\n/(] [)\\n(   )"));
    CHECK(nospaces(snowman(13141222)) == nospaces("_===_\n(._-)/\n<(] [)\n(" ")"));
    CHECK(nospaces(snowman(14141112)) == nospaces("_===_\n(. -)\n<( : )>\n(" ")"));
    CHECK(nospaces(snowman(14322212)) == nospaces("_===_\n\(O o)/\n( : )\n(" ")"));
    CHECK(nospaces(snowman(14322111)) == nospaces("_===_\n\(O o)\n( : )>\n( : )"));

    //second HAT tests
    CHECK(nospaces(snowman(21234441)) == nospaces("___\n.....\n(o,O)\n(   )\n( : )"));
    CHECK(nospaces(snowman(22112311)) == nospaces("___\n.....\n\(...)\n( : )\\n( : )"));
    CHECK(nospaces(snowman(22444422)) == nospaces("___\n.....\n(-.-)\n(> <)\n(" ")"));
    CHECK(nospaces(snowman(23332234)) == nospaces("___\n.....\n\(O_O)/\n(> <)\n(   )"));
    CHECK(nospaces(snowman(23311141)) == nospaces("___\n.....\n(O_.)\n<(   )>\n( : )"));
    CHECK(nospaces(snowman(23331121)) == nospaces("___\n.....\n(O_O)\n<(] [)>\n( : )"));
    CHECK(nospaces(snowman(24234141)) == nospaces("___\n.....\n(o O)\n(   )>\n( : )"));

    //third HAT tests
    CHECK(nospaces(snowman(31321433)) == nospaces(" _ \n/_\\\n(O,o)\n<(> <)\n(___)"));
    CHECK(nospaces(snowman(32113212)) == nospaces(" _ \n/_\\\n(...)/\n/( : )\n(" ")"));
    CHECK(nospaces(snowman(33323231)) == nospaces(" _ \n/_\\\n(O_o)/\n/(> <)/\n( : )"));
    CHECK(nospaces(snowman(34331111)) == nospaces(" _ \n/_\\\n(O O)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(34332221)) == nospaces(" _ \n/_\\\n\(O O)/\n(] [)\n( : )"));
    CHECK(nospaces(snowman(34331131)) == nospaces(" _ \n/_\\\n() ))\n<(> <)>\n( : )"));
    CHECK(nospaces(snowman(34112331)) == nospaces(" _ \n/_\\\n\(. .)\\n(> <)\n( : )"));
    CHECK(nospaces(snowman(34442433)) == nospaces(" _ \n/_\\\n\(- -)\n(> <)\n(___)"));

    //forth HAT tests
    CHECK(nospaces(snowman(41443342)) == nospaces("___\n(_*_)\n(-,-)\n/( : )\\n(" ")"));
    CHECK(nospaces(snowman(41443334)) == nospaces("___\n(_*_)\n\(-,-)/\n(> <)\n(   )"));
    CHECK(nospaces(snowman(41331414)) == nospaces("___\n(_*_)\n(O,O)\n<( : )\n(   )"));
    CHECK(nospaces(snowman(42332323)) == nospaces("___\n(_*_)\n\(O.O)\n(] [)\\n(___)"));
    CHECK(nospaces(snowman(43223241)) == nospaces("___\n(_*_)\n\(o_o)\n(   )\\n( : )"));
    CHECK(nospaces(snowman(42333343)) == nospaces("___\n(_*_)\n\(O.O)/\n(   )\n(___)"));
    CHECK(nospaces(snowman(44224214)) == nospaces("___\n(_*_)\n(O O)\n( : )/\n(   )"));

}

TEST_CASE("Bad snowman code") {
    //out of range
    CHECK_THROWS(snowman(1111110));
    CHECK_THROWS(snowman(44444445));
    //negative input
    CHECK_THROWS(snowman(-2345346));
    CHECK_THROWS(snowman(-3454294));
    //one or more wrong digit
    CHECK_THROWS(snowman(19111111));
    CHECK_THROWS(snowman(18111111));
    CHECK_THROWS(snowman(98712364));
    CHECK_THROWS(snowman(9876123));
    CHECK_THROWS(snowman(22228312));
    //too small input
    CHECK_THROWS(snowman(987));
    CHECK_THROWS(snowman(8765));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(986456));
}