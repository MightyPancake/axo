#ifndef AXO_ERR_H
#define AXO_ERR_H

typedef enum axo_err_code{
  axo_undeclared_var_err_code,
  axo_invalid_rval_err_code,
}axo_err_code;

char* axo_err_msg(axo_err_code err_code){
  switch(err_code){
    case axo_undeclared_var_err_code: return "Variable used before declaration."; break;
    case axo_invalid_rval_err_code: return "Invalid r-value."; break;
  }
  return "Invalid error code!";
}

#endif
