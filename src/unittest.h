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

/*
 * - Linear test case, no parallel
 * - Internal variables: prefixed with `_`
 **/

#ifndef __UNITTEST_H__
#define __UNITTEST_H__

#include <stdio.h>
#include <string.h>

/* Maximum number of tests */
#define _MAX_NTEST 500

/* Maximum number of chars in a string */
#define _MAX_STRLEN 3000

typedef int        testcase_t (void);

static testcase_t  *_tests_[_MAX_NTEST];
static int         _nTests_ = 0;

static int         _currentRes_ = 1;
char               _currentTestName_[_MAX_STRLEN];

/* Add and remove a test case */
void addTest         (testcase_t *);
void removeLastTest  (void);

/* Return 0 if passed and non-0 if failed */
int runTest (testcase_t *);
int runTestNth (int pos);

/* Return number of passed tests */
int runAllTests (void);

/* Setup and tear down */
void initTestCase    (const char *testName);
int finishTestCase   (void);

/* Helpers */
void toStrLower (const char *, char *);

/* Assertion */
void assertInt                 (int, int);
void assertNotInt              (int, int);
void assertIntDescription      (int, int, const char *);
void assertNotIntDescription   (int, int, const char *);
void assertStr                 (const char *, const char *);
void assertNotStr              (const char *, const char *);
void assertStrDescription      (const char *, const char *, const char *);
void assertNotStrDescription   (const char *, const char *, const char *);
void assertStrI                (const char *, const char *);
void assertNotStrI             (const char *, const char *);
void assertStrIDescription     (const char *, const char *, const char *);
void assertNotStrIDescription  (const char *, const char *, const char *);

#endif
