
#include "pf_all.h"
#include "blink1-lib.h"

static cell_t CountBlinks(void) {
  int n = blink1_enumerate();

  return n;
}

#ifdef PF_NO_GLOBAL_INIT

#define NUM_CUSTOM_FUNCTIONS (1)
CFunc0 CustomFunctionTable[NUM_CUSTOM_FUNCTIONS];

Err LoadCustomFunctionTable(void) {
  CustomFunctionTable[0] = CountBlinks;
  return 0;
}

#else

CFunc0 CustomFunctionTable[] = {
  (CFunc0) CountBlinks
};

#endif

#if (!defined(PF_NO_INIT)) && (!defined(PF_NO_SHELL))
Err CompileCustomFunctions() {
  Err err;

  err = CreateGlueToC("COUNTBLINKS", 0, C_RETURNS_VALUE, 0);
  if (err < 0) { return err; }
  
  return 0;
}

#else

Err CompileCustomFunctions() { return 0; }

#endif
