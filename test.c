//use core
#define AXO_DEFINE_ENTRY_POINT int axo__main(axo__arr args);
#define AXO_MAIN_ENTRY_POINT axo__main
/*
	name: axo
	prefix: axo_mod_
	version: 0.0.1
	author: mightypancake
	website: https://axolang.com
	license_name: Apache 2.0
	license: https://www.apache.org/licenses/LICENSE-2.0.txt
	description: This file is used in every axo program to provide basic functionality that C itself just lacks by default. It also includes some (hopefully light) C headers.
*/
//accepting type va_list
#include <stdbool.h>
#include "/home/mightypancake/axo/modules/core/defer/defer.h"
#include "/home/mightypancake/axo/modules/core/core.h"
#include "/home/mightypancake/axo/modules/core/arr.h"
//including './mod.axo'
typedef struct axo_module{
char *name;
char *prefix;
char *version;
char *author;
char *website;
char *license_name;
char *license;
char *description;
}axo_module;
axo__arr modules;
axo_module axo_mods[] = {(axo_module){.name="axo",.prefix="axo_mod_",.version="0.0.1", .author="mightypancake",.website="https://axolang.com",.license_name="Apache 2.0",.license="https://www.apache.org/licenses/LICENSE-2.0.txt",.description="This file is used in every axo program to provide basic functionality that C itself just lacks by default. It also includes some (hopefully light) C headers."},(axo_module){.name="std",.prefix="std_mod_",.version="0.0.1", .author="mightypancake",.website="https://axolang.com",.license_name="Apache 2.0",.license="https://www.apache.org/licenses/LICENSE-2.0.txt",.description="Axo standard library. This mostly reuses C stdlib."},(axo_module){.name="io",.prefix="io_mod_",.version="0.0.0", .author="mightypancake",.website="https://www.website.com",.license_name="Support free software! <3",.license="https://www.license-website.org/license.txt",.description="I/O module"},(axo_module){.name="aesc",.prefix="aesc_mod_",.version="0.0.1", .author="mightypancake",.website="https://axolang.com",.license_name="Apache 2.0",.license="https://www.apache.org/licenses/LICENSE-2.0.txt",.description="ANSII escape sequences"},(axo_module){.name="str",.prefix="str_mod_",.version="0.0.1", .author="mightypancake",.website="https://axolang.com",.license_name="MIT",.license="https://www.apache.org/licenses/LICENSE-2.0.txt",.description="Basic string functionality"},(axo_module){.name="mem",.prefix="mem_mod_",.version="0.0.1", .author="mightypancake",.website="https://axolang.com",.license_name="Apache 2.0",.license="https://www.apache.org/licenses/LICENSE-2.0.txt",.description="Memory module"},(axo_module){.name="time",.prefix="time_mod_",.version="0.0.0", .author="mightypancake",.website="https://www.website.com",.license_name="Support free software! <3",.license="https://www.license-website.org/license.txt",.description="Provides basic time functionality."}};
axo__arr modules = {.data=axo_mods, .len=((axo_arr_dim_t[]){7}),.flags=AXO_ARR_STATIC};

//including './test.axo'
typedef struct axo_test{
char *name;
bool (*func)();
}axo_test;
#include "/home/mightypancake/axo/modules/core/main.h"
//including './error.axo'
#include <errno.h>
#include <string.h>
//provided int errno
typedef struct error{
int code;
char *msg;
}error;
error* met_error_set(error *_axo_self_param,int code,char *msg){
(*_axo_self_param).code=code;
(*_axo_self_param).msg=msg;
return _axo_self_param;
}
bool met_error_ok(error *_axo_self_param){
return !((((bool)((*_axo_self_param).code))));
}
void met_error_clear(error *_axo_self_param){
(*_axo_self_param).code=0;
(*_axo_self_param).msg="";
}
error err = ((error){.code=0, .msg="No error"});
error *errptr = &err;
//use std
/*
	name: std
	prefix: std_mod_
	version: 0.0.1
	author: mightypancake
	website: https://axolang.com
	license_name: Apache 2.0
	license: https://www.apache.org/licenses/LICENSE-2.0.txt
	description: Axo standard library. This mostly reuses C stdlib.
*/
#include <stdlib.h>
#include <stdbool.h>
//provided bool true
//provided bool false
//provided void *(*malloc)(size_t)
//provided void *(*realloc)(void*,size_t)
//provided void (*free)(void*)
//provided int (*system)(char*)
//provided void (*exit)(int)
//provided int (*atexit)(void)
//provided int (*getenv)(void)
//provided int (*setenv)(char*,char*)
//provided int (*unsetenv)(char*)
//provided int (*clearenv)(void)
//provided void (*qsort)(void*,size_t,size_t,int(*)(const void*,const void*))
//provided void *(*bsearch)(void*,void*,size_t,size_t,int*)
//provided int (*rand)()
//provided void (*srand)(unsigned)
//provided int (*abs)(char*,char*,int)
//provided int64_t (*labs)(char*,char*,int64_t)
//provided int (*mbtowc)(char*,char*,char*,int)
//provided int (*mbstowcs)(char*,char*,char*)
//provided int (*wctomb)(char*,char*,char*,int)
//provided int (*wcstombs)(char*,char*,char*)
//provided int (*atoi)(char*,char*)
//provided int64_t (*atol)(char*,char*)
//provided double (*atof)(char*,char*)
//provided int (*strtol)(char*,char*,char*)
//provided uint64_t (*strtoul)(char*,char*,char*)
//provided uint64_t (*strtoull)(char*,char*,char*)
//provided double (*strtod)(char*,char*,char*)
//provided float (*strtof)(char*,char*,char*)
//provided void *(*calloc)(size_t)
//provided int (*abort)(void)
//provided int (*_Exit)(void)
//provided int (*div)(char*)
//provided int64_t (*ldiv)(char*)
//provided char *(*mktemp)(char*)
//provided int (*mkstemp)(char*)
//provided char *(*tmpnam)(char*)
//provided int (*rand_r)()
//provided int (*realpath)(char*)
//provided int (*mkfifo)(char*,char*,int,int)
//use io
/*
	name: io
	prefix: io_mod_
	version: 0.0.0
	author: mightypancake
	website: https://www.website.com
	license_name: Support free software! <3
	license: https://www.license-website.org/license.txt
	description: I/O module
*/
#include <stdio.h>
//accepting type FILE
//accepting type fpos_t
//provided int (*fclose)(FILE*)
//provided void (*clearerr)(FILE*)
//provided int (*feof)(FILE*)
//provided int (*ferror)(FILE*)
//provided int (*fflush)(FILE*)
//provided int (*fgetpos)(FILE*,fpos_t*)
//provided FILE *(*fopen)(char*,char*)
//provided size_t (*fread)(char*,size_t,size_t,FILE*)
//provided FILE *(*freopen)(FILE*,char*,FILE*)
//provided int (*fseek)(FILE*,int64_t,int)
//provided int (*fsetpos)(FILE*,fpos_t*)
//provided int64_t (*ftell)(FILE*)
//provided size_t (*fwrite)(char*,size_t,size_t,FILE*)
//provided int (*remove)(char*)
//provided int (*rename)(char*,char*)
//provided void (*rewind)(FILE*)
//provided void (*setbuf)(FILE*,char*)
//provided int (*setvbbuf)(FILE*,char*,int,size_t)
//provided FILE *(*tmpfile)()
//provided char *(*nmpnam)(char*)
//provided int (*fprintf)(FILE*,char*,...)
//provided int (*printf)(char*,...)
//provided int (*sprintf)(char*,char*,...)
//provided int (*vfprintf)(FILE*,char*,va_list)
//provided int (*vprintf)(FILE*,va_list)
//provided int (*vsprintf)(FILE*,char*,va_list)
//provided int (*fscanf)(FILE*,char*,...)
//provided int (*scanf)(char*,...)
//provided int (*sscanf)(char*,char*,...)
//provided int (*fgetc)(FILE*)
//provided char *(*fgets)(char*,int,FILE*)
//provided int (*fputc)(int,FILE*)
//provided int (*fputs)(char*,FILE*)
//provided int (*getc)(FILE*)
//provided int (*getchar)()
//provided char *(*gets)(char*)
//provided int (*putc)(int,FILE*)
//provided int (*putchar)(int)
//provided int (*puts)(char*)
//provided int (*ungetc)(int,FILE*)
//provided void (*perror)(char*)
//provided FILE *stderr
//provided FILE *stdin
//provided FILE *stdout
//use aesc
/*
	name: aesc
	prefix: aesc_mod_
	version: 0.0.1
	author: mightypancake
	website: https://axolang.com
	license_name: Apache 2.0
	license: https://www.apache.org/licenses/LICENSE-2.0.txt
	description: ANSII escape sequences
*/
char *aesc_mod_reset = "\x1B[0m";
char *aesc_mod_bold = "\x1B[1m";
char *aesc_mod_inverse = "\x1B[7m";
char *aesc_mod_black = "\x1B[30m";
char *aesc_mod_red = "\x1B[31m";
char *aesc_mod_green = "\x1B[32m";
char *aesc_mod_yellow = "\x1B[33m";
char *aesc_mod_blue = "\x1B[34m";
char *aesc_mod_magenta = "\x1B[35m";
char *aesc_mod_cyan = "\x1B[36m";
char *aesc_mod_white = "\x1B[37m";
//use str
/*
	name: str
	prefix: str_mod_
	version: 0.0.1
	author: mightypancake
	website: https://axolang.com
	license_name: MIT
	license: https://www.apache.org/licenses/LICENSE-2.0.txt
	description: Basic string functionality
*/
//use mem
/*
	name: mem
	prefix: mem_mod_
	version: 0.0.1
	author: mightypancake
	website: https://axolang.com
	license_name: Apache 2.0
	license: https://www.apache.org/licenses/LICENSE-2.0.txt
	description: Memory module
*/
void* mem_mod_alc(size_t sz){
return malloc(sz);
}
void* met_none_rlc(void *_axo_self_param,size_t sz){
return realloc(_axo_self_param,sz);
}
int mem_mod_free(void *ptr){
free(ptr);
return 0;
}
#include <string.h>
//provided char *(*memchr)(char*,int,size_t)
//provided int (*memcmp)(char*,char*,size_t)
//provided char *(*memcpy)(char*,char*,size_t)
//provided char *(*memmove)(char*,char*,size_t)
//provided char *(*memset)(char*,int,size_t)
//provided char *(*strcat)(char*,char*)
//provided char *(*strncat)(char*,char*,size_t)
//provided char *(*strchr)(char*,int)
//provided int (*strcmp)(char*,char*)
//provided int (*strncmp)(char*,char*,size_t)
//provided int (*strcoll)(char*,char*)
//provided char *(*strcpy)(char*,char*)
//provided char *(*strncpy)(char*,char*,size_t)
//provided size_t (*strcspn)(char*,char*)
//provided char *(*strerror)(int)
//provided size_t (*strlen)(char*)
//provided char *(*strpbrk)(char*,char*)
//provided char *(*strrchr)(char*,int)
//provided size_t (*strspn)(char*,char*)
//provided char *(*strstr)(char*,char*)
//provided char *(*strtok)(char*,char*)
//provided size_t (*strxfrm)(char*,char*,size_t)
char* str_mod_alc(char *str){
char *res = ((char*)(mem_mod_alc(strlen(str)+((size_t)(1)))));
strcpy(res,str);
return res;
}
char* met_byte_cpy(char *_axo_self_param){
return str_mod_alc(_axo_self_param);
}
void met_byte_to_arr(char *_axo_self_param){
axo__arr res = axo_arr_new_dyn(malloc((0)*sizeof(char)), axo_dyn_bytes_cpy(axo_arr_dim_t*, (axo_arr_dim_t[]){0}, (1)*sizeof(axo_arr_dim_t)));
}
error* met_error_get_c(error *_axo_self_param){
return met_error_set((&((*_axo_self_param))),errno,strerror(errno));
}
void met_error_oops(error *_axo_self_param){
if(met_error_ok((&((*_axo_self_param)))))
return;
fprintf(stderr,"%sError: %s%s\n",aesc_mod_red,(*(_axo_self_param)).msg,aesc_mod_reset);
}
FILE* io_mod_open(char *filename,char *mode,error *ep){
met_error_oops((&((*ep))));
FILE *f = fopen(filename,mode);
met_error_get_c((&((*errptr))));
return f;
}
FILE* met_FILE_to_str(FILE *_axo_self_param,char *o,size_t r_sz,error *ep){
met_error_oops((&((*ep))));
while((fread(o,1,r_sz,_axo_self_param)==r_sz))
;
met_error_get_c((&((*ep))));
return _axo_self_param;
}
int met_FILE_close(FILE *_axo_self_param,error *ep){
met_error_oops((&((*ep))));
return fclose(_axo_self_param);
}
//use time
/*
	name: time
	prefix: time_mod_
	version: 0.0.0
	author: mightypancake
	website: https://www.website.com
	license_name: Support free software! <3
	license: https://www.license-website.org/license.txt
	description: Provides basic time functionality.
*/
#include <time.h>
//accepting type time_t
//provided time_t (*time)(time_t*)
//provided char *(*ctime)(const time_t*)
time_t time_mod_now(){
return time(NULL);
}
char* time_mod_str(){
time_t t = time_mod_now();
return ctime(&t);
}
int std_mod_seed_rand(unsigned seed){
srand(seed);
return 0;
}
int std_mod_rand(){
return rand();
}
void panic(char *msg,int exit_code){
fprintf(stderr,"%s%s%s\n",aesc_mod_red,msg,aesc_mod_reset);
exit(exit_code);
}
void met_error_panic(error *_axo_self_param){
panic((*_axo_self_param).msg,(*_axo_self_param).code);
}
int print_module(axo_module mod){
printf("name: %s\nprefix: %s\nversion: %s\nauthor: %s\nwebsite: %s\nlicense_name: %s\nlicense: %s\ndescription: %s\n",mod.name,mod.prefix,mod.version,mod.author,mod.website,mod.license_name,mod.license,mod.description);
return 0;
}
int axo__main(axo__arr args){
printf("Hello world\n");
return 0;
}
