#ifndef __UTIL_H
#define __UTIL_H

#include "stmt.h"

extern char *scanned_text;
extern char *append_scan(char *in);
extern void append_stmt(Statement *stmt);
extern Statement *get_stmts();

#endif  // __UTIL_H