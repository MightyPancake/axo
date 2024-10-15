#include "./wasm.h"

void axo_add_wasm_error(const char* fmt, va_list args){
  char* str = NULL;
  vasprintf(&str, fmt, args);
  EM_ASM_({
    axo_errors.push(UTF8ToString($0));
  }, str);
}
