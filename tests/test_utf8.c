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

/* See `Makefile` for more details on how this file is used */

#include <stdio.h>
#include <string.h>
#include "utf8small.h"
#include "unittest.h"

bgstr s, buff;
bglen_t i;
void *tmp;

int testLengthFunctions (void) {
    initTestCase ("bgCharLen | bgStrLen >> input: utf8_input.txt");

    assertInt (22, strlen (s));
    assertInt (1, bgCharLen (s));
    assertInt (17, bgStrLen (s));

    return finishTestCase ();
}

int testCharAccess (void) {
    initTestCase ("bgGetCharAt >> input: utf8_input.txt");

    char res[20][10];

    strcpy (res[0],  "X");
    strcpy (res[1],  "i");
    strcpy (res[2],  "n");
    strcpy (res[3],  " ");
    strcpy (res[4],  "c");
    strcpy (res[5],  "h");
    strcpy (res[6],  "à");
    strcpy (res[7],  "o");
    strcpy (res[8],  " ");
    strcpy (res[9],  "t");
    strcpy (res[10], "h");
    strcpy (res[11], "ế");
    strcpy (res[12], " ");
    strcpy (res[13], "g");
    strcpy (res[14], "i");
    strcpy (res[15], "ớ");
    strcpy (res[16], "i");

    for (i = 0; i < bgStrLen (s); i++) {
        bgGetCharAt (s, buff, i);
        assertStr (res[i], buff);
        // fprintf (stdout, "-> Char at %i: %s\n", i, buff);
    }

    return finishTestCase ();
}

void readInput (void) {
    /* This is supposed to read from `test_utf8_input.txt` */
    tmp = fgets (s, BG_MAX_BUFFER, stdin);
    s[strlen (s) - 1] = 0;
}

int main (int argc, char *argv[]) {
    readInput ();

    addTest (testLengthFunctions);
    addTest (testCharAccess);
    runAllTests ();

    return 0;
}
