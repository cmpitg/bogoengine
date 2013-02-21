/*

  This file is a part of bogoengine project.

  Copyright (C) 2012-2013 Duong H. Nguyen <cmpitgATgmaildotcom>

  bogoengine is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  bogoengine is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "unittest.h"

int produceOne (void) {
    return 10 - 9;
}

int test1 (void) {
    initTestCase ("Test Int");

    assertInt (10, 5 + 5);
    assertInt (1, produceOne ());

    return finishTestCase ();
}

int test2 (void) {
    initTestCase ("Test something else");

    assertInt (10, 10);
    assertIntDescription (5, 5, "Simple calculation");

    return finishTestCase ();
}

int test3 (void) {
    initTestCase ("Test string");

    assertStr ("World Hello", "World Hello");
    assertStrI ("World Hello", "WorlD hEllo");
    assertStrI ("world HellO_", "WorlD hEllo_");

    return finishTestCase ();
}

int main (int argc, char const *argv[]) {
    addTest (test1);
    addTest (test2);
    addTest (test3);
    runAllTests ();

    return 0;
}
