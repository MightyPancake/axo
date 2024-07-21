#include "./wasm.h"

EM_JS
  (void, axo_wasm_append_error, (const char* str), {
  axo_errors.push(String(UTF8ToString(str)));
});

void axo_add_wasm_error(const char* fmt, va_list args){
  char* str = NULL;
  vasprintf(&str, fmt, args);
  axo_wasm_append_error(str);
}
