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

void printBgStr (const bgstr str) {
    printStr (str);
}

void printStrNewline (const char *str) {
    printStr (str);
    fprintf (stdout, "\n");
}

void printBgStrNewline (const bgstr str) {
    printStrNewline (str);
}

/* ----------------------------------------------------------------------- */
/* Main */

void bgstrDup (const bgstr source,
               bgstr target) {
    strncpy (target, source, strlen_ (source));
}

void strToBgStr (const char *source,
                 bgstr target) {
    bgstrDup (source, target);
}

void bgstrToStr (const bgstr source,
                 char *target) {
    bgstrDup (source, target);
}

bglen_t bgCharLen (bgstr ch) {
    bglen_t mask = 0xfc;
    bglen_t maskShift = 4;

    bgchar  c = ch[0];
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

bglen_t bgstrLen (bgstr str) {
    bglen_t res = 0;
    bglen_t pos = 0;
    bglen_t byteNum = strlen (str);

    while (pos < byteNum) {
        res++;
        pos += bgCharLen (str + pos);
    }

    return res;
}

void bgGetCharAt (bgstr str,
                  bgstr target,
                  bglen_t pos) {
    /* Out-of-range guard */
    if (pos < 0 || bgstrLen (str) <= pos) {
        target[0] = 0;
        return;
    }

    bglen_t currentUnicodePos = 0;
    bglen_t currentBytePos    = 0;

    while (currentUnicodePos < pos) {
        currentBytePos += bgCharLen (str + currentBytePos);
        currentUnicodePos++;
    }

    bglen_t charLength = bgCharLen (str + currentBytePos);

    memcpy (target, str + currentBytePos, charLength);
    target[charLength] = 0;
}
