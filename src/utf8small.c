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

#include <stdio.h>
#include "utf8small.h"

/* ----------------------------------------------------------------------- */
/* Helpers */

int getBit (int num,
            int n) {
    return (n >> num) & 1;
}

void printBits (const char *str,
                bglen_t byteNum) {
    bglen_t i, j;

    for (i = 0; i < byteNum; i++) {
        for (j = 7; j >= 0; j--) {
            printf ("%i", getBit (j, str[i]));
        }
        printf (" ");
    }
    printf ("\n");
}

void printStrBits (const char *str) {
    printBits(str, strlen_ (str));
}

void printStr (const char *str) {
    fprintf (stdout, "%s", str);
}

void printBgstr (const bgstr str) {
    printStr (str);
}

void printStrNewline (const char *str) {
    printStr (str);
    fprintf (stdout, "\n");
}

void printBgstrNewline (const bgstr str) {
    printStrNewline (str);
}

/* ----------------------------------------------------------------------- */
/* Main */

void bgstrFirstChar (const bgstr source,
                     bgstr target) {
    bgstrGetCharAt (source, target, 0);
}

void bgstrLastChar (const bgstr source,
                    bgstr target) {
    bgstrGetCharAt (source, target, bgstrLen (source) - 1);
}

void bgstrPrepend (bgstr source,
                   bgstr target,
                   bgstr str) {
    bgstrInsertStrAt (source, target, str, 0);
}

void bgstrAppend (bgstr source,
                  bgstr target,
                  bgstr str) {
    bgstrInsertStrAt (source, target, str, bgstrLen (source));
}

bglen_t bgcharCountBytesAt (const bgstr str,
                            bglen_t position) {
    bgchar ch;
    bgstrGetCharAt (str, ch, position);
    return bgcharCountBytes (ch);
}

bglen_t bgNthBgcharToNthByte (const bgstr str,
                              bglen_t position) {
    bglen_t i;
    bglen_t nth;
    bgchar tmpChar;

    /* Guarding */
    if (position < 0 || bgstrLen (str) <= position) {
        return 0;
    }

    nth = 0;
    for (i = 0; i < position; i++) {
        nth += bgcharCountBytesAt (str, i);
    }

    return nth;
}

bglen_t bgcharCountBytes (const bgchar ch) {
    bgchar tmpChar;

    bgstrGetCharAt (ch, tmpChar, 0);
    return bgstrCountBytes (tmpChar);
}

bglen_t bgstrCountBytes (const bgstr str) {
    return strlen_ (str);
}

void bgstrInsertStrAt  (bgstr source,
                        bgstr target,
                        bgstr ch,
                        bglen_t position) {
    bglen_t length = bgstrLen (source);
    bglen_t newLength = 0;
    bgstr substr1, substr2;

    bgstr result;               /* Safe copying, in case source == target */
    bgstrAssign (result, "");   /* Make sure it's a completely empty string */

    /* Guarding */
    if (position < 0 || length < position) {
        bgstrDup (result, target);
        return;
    }

    bgstrSubStr (source, substr1, 0, position);
    bgstrSubStr (source, substr2, position, -1);

    strcat (result, substr1);
    strcat (result, ch);
    strcat (result, substr2);
    newLength = bgstrCountBytes (source) + bgstrCountBytes (ch);
    result[newLength + 1] = 0;      /* Make sure it's NULL-terminated */

    bgstrAssign (target, result);
}

void bgstrInsertCharAt  (bgstr source,
                         bgstr target,
                         bgstr ch,
                         bglen_t position) {
    bgstrInsertStrAt (source, target, ch, position);
}

void bgstrAssign (bgstr target,
                bgstr source) {
    bgstrDup (source, target);
}

bglen_t bgstrGetCharLenAt (const bgstr str,
                           bglen_t position) {
    bgchar ch;
    bgstrGetCharAt (str, ch, position);
    return bgcharLen (ch);
}

void bgstrSubStr (bgstr source,
                  bgstr target,
                  bglen_t from,
                  bglen_t count) {
    bgstrCopy (source, target, from, count);
}

void strCopy (const char *source,
              char *target,
              bglen_t fromByte,
              bglen_t count) {
    memcpy (target, source + fromByte, count);
    target[count] = 0;          /* Make sure the string is properly ended */
}

void bgstrCopy (bgstr source,
                bgstr target,
                bglen_t from,
                bglen_t count) {
    bglen_t length = bgstrLen (source);
    bglen_t lastCharPosition;
    bglen_t startFrom;
    bglen_t nBytes;

    bgstr result;

    /* By default, copy all character from `from` to the end */
    if (count == -1 || length <= from + count) {
        count = length - from;
    }

    /* Guarding */
    if (from < 0 || length <= from || count == 0) {
        bgstrAssign (target, "");
        return;
    }

    lastCharPosition = from + count - 1;

    startFrom = bgNthBgcharToNthByte (source, from);
    nBytes    = bgNthBgcharToNthByte (source, from + count - 1)
        + bgstrGetCharLenAt (source, lastCharPosition) - startFrom;

    strCopy (source, result, startFrom, nBytes);
    bgstrAssign (target, result); /* Guard in case source == target */
}

void bgstrDup (const bgstr source,
               bgstr target) {
    memset (target, 0, sizeof (target));

    /* Empty string */
    if (strcmp ("", source) == 0) {
        return;
    }

    strCopy (source, target, 0, strlen_ (source));
}

void strToBgstr (const char *source,
                 bgstr target) {
    bgstrDup (source, target);
}

void bgstrToStr (const bgstr source,
                 char *target) {
    bgstrDup (source, target);
}

bglen_t bgcharLen (const bgchar ch) {
    bglen_t mask = 0xfc;
    bglen_t maskShift = 4;

    bgbyte  c = ch[0];
    bglen_t res;

    for (res = 6; res > 1; res--) {
        if ((c & mask) == mask) {
            break;
        }
        mask &= ~maskShift;
        maskShift <<= 1;
    }

    return res;
}

bglen_t bgstrLen (const bgstr str) {
    bglen_t res = 0;
    bglen_t pos = 0;
    bglen_t byteNum = strlen (str);

    while (pos < byteNum) {
        res++;
        pos += bgcharLen (str + pos);
    }

    return res;
}

void bgstrGetCharAt (const bgstr source,
                     bgstr target,
                     bglen_t pos) {
    /* Out-of-range guard */
    if (pos < 0 || bgstrLen (source) <= pos) {
        target[0] = 0;
        return;
    }

    bglen_t currentUnicodePos = 0;
    bglen_t currentBytePos    = 0;

    while (currentUnicodePos < pos) {
        currentBytePos += bgcharLen (source + currentBytePos);
        currentUnicodePos++;
    }

    bglen_t charLength = bgcharLen (source + currentBytePos);

    memcpy (target, source + currentBytePos, charLength);
    target[charLength] = 0;
}
