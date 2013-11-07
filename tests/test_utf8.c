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

bgstr   mainString, buff;
bglen_t i;

int testNthBgcharToNthByte (void) {
    initTestCase ("bgNthBgcharToNthByte");

    const char ch3[6] = "ư";      /* 2 */
    const char ch4[6] = "ờ";      /* 3 */
    const char str[24] = "ường";  /* 7 */

    assertInt (0, bgNthBgcharToNthByte (str, 0));
    assertInt (2, bgNthBgcharToNthByte (str, 1));
    assertInt (5, bgNthBgcharToNthByte (str, 2));
    assertInt (6, bgNthBgcharToNthByte (str, 3));

    /* Invalid */
    assertInt (0, bgNthBgcharToNthByte (str, -1));
    assertInt (0, bgNthBgcharToNthByte (str, 4));

    /* 0123456 */
    /* ||---ab */

    return finishTestCase ();
}

int testCountBytes (void) {
    initTestCase ("bgcharCountBytes | bgstrCountBytes");

    const char ch1[6] = "à";      /* 2 */
    const char ch2[6] = "ế";      /* 3 */
    const char ch3[6] = "ư";      /* 2 */
    const char ch4[6] = "ờ";      /* 3 */
    const char str[24] = "ường";  /* 7 */

    assertInt (2, bgcharCountBytes (ch1));
    assertInt (3, bgcharCountBytes (ch2));
    assertInt (2, bgcharCountBytes (ch3));
    assertInt (3, bgcharCountBytes (ch4));
    assertInt (2, bgcharCountBytes (str));
    assertInt (7, bgstrCountBytes (str));

    return finishTestCase ();
}

int testLengthFunctions (void) {
    initTestCase ("bgcharLen | bgstrLen >> input: utf8_input.txt");

    assertInt (22, strlen (mainString));
    assertInt (1, bgcharLen (mainString));
    assertInt (17, bgstrLen (mainString));

    return finishTestCase ();
}

int testCharAccess (void) {
    initTestCase ("bgstrGetCharAt >> input: utf8_input.txt");

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

    for (i = 0; i < bgstrLen (mainString); i++) {
        bgstrGetCharAt (mainString, buff, i);
        assertStr (res[i], buff);
        // fprintf (stdout, "-> Char at %i: %s\n", i, buff);
    }

    return finishTestCase ();
}

int testStringConversion (void) {
    initTestCase ("toBgString");

    const char *aStr = "Xin chào thế giới!";
    char        sameStr[1024];
    bgstr       res;
    
    strToBgstr (aStr, res);
    bgstrToStr (res, sameStr);

    assertStr (aStr, sameStr);

    return finishTestCase ();
}

int testStringDuplication (void) {
    initTestCase ("bgstrDup");

    bgstr str1, str2;
    char pointerAddr1[20];
    char pointerAddr2[20];

    strToBgstr ("Xin chào thế giới!", str1);
    bgstrDup (str1, str2);

    assertStr (str1, str2);

    return finishTestCase ();
}

int testStringCopy (void) {
    initTestCase ("bgstrCopy | bgstrAssign");

    bgstr str1, str2, str3, str4, str5, str6, str7, str8;
    char pointerAddr1[20];
    char pointerAddr2[20];
    char pointerAddr3[20];

    strToBgstr ("Xin chào thế giới!", str1);
    bgstrCopy (str1, str2, 0, bgstrLen (str1));
    bgstrAssign (str3, str2);
    bgstrCopy (str1, str4, 0, 7);
    bgstrCopy (str1, str5, 6, 6);
    bgstrCopy (str1, str6, -1, 3);
    bgstrCopy (str1, str7, bgstrLen (str1), 3);
    bgstrCopy (str1, str8, 1, bgstrLen (str1) + 3);

    assertStr (str1, str2);
    assertStr (str1, str3);
    assertStr ("Xin chà", str4);
    assertStr ("ào thế", str5);
    assertStr ("", str6);
    assertStr ("", str7);
    assertStr ("in chào thế giới!", str8);

    return finishTestCase ();
}

/* int testInsertChar (void) { */
/*     initTestCase ("bgstrInsertCharAt"); */

/*     bgstr aString; */
/*     bgstr aChar; */

/*     strToBgstr ("Xin chào t", aString); */

/*     bgstrInsertCharAt (aString, aString, " ", 0); */
/*     assertStr (" Xin chào t", aString); */

/*     bgstrInsertCharAt (aString, aString, "h", 11); */
/*     assertStr (" Xin chào th", aString); */

/*     bgstrInsertCharAt (aString, aString, "ế", 12); */
/*     assertStr (" Xin chào thế", aString); */

/*     return finishTestCase (); */
/* } */

void readInput (void) {
    /* This is supposed to read from `test_utf8_input.txt` */
    fgets (mainString, BG_MAX_BUFFER, stdin);
    mainString[strlen (mainString) - 1] = 0;
}

int main (int argc, char *argv[]) {
    readInput ();
    printf ("\n");

    addTest (testCountBytes);
    addTest (testNthBgcharToNthByte);

    addTest (testLengthFunctions);
    addTest (testCharAccess);
    addTest (testStringConversion);
    addTest (testStringDuplication);
    addTest (testStringCopy);
    /* addTest (testInsertChar); */

    runAllTests ();

    return 0;
}
