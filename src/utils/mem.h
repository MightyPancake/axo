#ifndef TYCI_UTIL_H
#define TYCI_UTIL_H
    //General pointer helpers
    #define alloc_one(typ) ((typ*)malloc(sizeof(typ)))
    #define new_ptr_one(name, typ) typ* name = (typ*)malloc(sizeof(typ));
    #define realloc_n(ptr, n, typ) ({ptr = (typ*)realloc(ptr, n*sizeof(typ));})
    //String related helpers
    #define empty_str ({char* str = (char*)malloc(sizeof(char)); str[0] = '\0'; str;})
    #define alloc_str(content) ({char* _STR_ = (char*)malloc((strlen(content) + 1)*sizeof(char)); strcpy(_STR_, content); _STR_;})
    #define is_empty_str(str) (str[0] == '\0')
    #define str_cpy(target, content) ({*target = (char*)realloc(target, (strlen(content+1)*sizeof(char))); strcpy(*target, content); target;})
    #define resize_dyn_arr_if_needed(typ, ptr, len, cap) if(len%cap==0) ptr=(typ*)realloc(ptr,(len+cap)*sizeof(typ))
#endif