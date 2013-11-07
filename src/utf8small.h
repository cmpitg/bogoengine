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

#ifndef __UTF8SMALL_H__
#define __UTF8SMALL_H__

#include <inttypes.h>
#include <string.h>

#define BG_MAX_BUFFER 4096
#define strlen_ strlen

typedef uint8_t   bgchar;
typedef uint8_t   bgstr[BG_MAX_BUFFER];
typedef int32_t   bglen_t;
typedef char      bgbool;

/* Useful when debugging */
void printBits (const char *str, bglen_t byteNum);

void printStrBits    (const char *str); /* No bgstr version, printing bits
                                           mean we don't care about multibyte */
void printStr        (const char *str);
void printBgStr      (const bgstr str); /* Alias of printStr, human-readable
                                           forms should be exactly the same in
                                           all cases */

/* Ha ha. Actually no kidding at all. Small but useful when debugging */
void printStrNewline    (const char *str);
void printBgStrNewLine  (const bgstr str);

bglen_t bgCharLen  (bgstr ch);
bglen_t bgStrLen   (bgstr str);
void bgGetCharAt   (bgstr str, bgstr target, bglen_t position);

void bgStrDup        (const bgstr source, bgstr target);
void strToBgStr      (const char *source, bgstr target);
void bgStrToStr      (const bgstr source, char *target);
void bgStrCopy       (bgstr source, bgstr target);
void bgStrAssign     (bgstr target, bgstr source);

void bgInsertCharAt  (bgstr str, bgstr target, bgstr ch, bglen_t position);
void bgRemoveCharAt  (bgstr str, bgstr target, bglen_t position);
void bgAppend        (bgstr str, bgstr target, bgstr str2);
void bgPrepend       (bgstr str, bgstr target, bgstr str2);
void bgSubStr        (bgstr str, bgstr target, bglen_t from, bglen_t count);

void bgStrToLower    (bgstr source, bgstr target);
void bgStrToUpper    (bgstr source, bgstr target);

int bgStrCmp         (bgstr str1, bgstr str2);
int bgStrCmpI        (bgstr str1, bgstr str2);

bgbool bgStartsWith  (bgstr str, bgstr pattern);
bgbool bgEndsWith    (bgstr str, bgstr pattern);

#endif
