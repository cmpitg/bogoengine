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
#include <string.h>
#include "utf8small.h"

int main (int argc, char *argv[]) {
    bgstr s, buff;
    bglen_t i;
    void *tmp;

    tmp = fgets (s, BG_MAX_BUFFER, stdin);
    s[strlen (s) - 1] = 0;
    fprintf (stdout, "-> Input string: %s\n", s);
    printBits (s, strlen (s));
    fprintf (stdout, "-> Str Length: %i; Expected: 22\n", (int)strlen (s));
    fprintf (stdout, "-> Char Length: %i; Expected: 1\n", (int)bgCharLen (s));
    fprintf (stdout, "-> Unicode Str Length: %i; Expected 17\n", (int)bgStrLen (s));

    for (i = 0; i < bgStrLen (s); i++) {
        bgGetCharAt (s, buff, i);
        fprintf (stdout, "-> Char at %i: %s\n", i, buff);
    }

    return 0;
}
