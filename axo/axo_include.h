#include <stdlib.h>
typedef struct axo__arr {
	unsigned int len;		//Array length
	unsigned short cap; //This is 0 for static arrays
	void* data;					//Array elements
}axo__arr;

#define axo_arr_is_dynamic(ARR) (ARR.cap)
#define axo_arr_is_static(ARR) (!axo_arr_is_dynamic(ARR))
#define axo_arr_size(TYP, ARR) (ARR.len*sizeof(TYP))
#define axo_new_arr(CAP) ((axo__arr){.len=0, .cap=CAP, .data=NULL})
#define axo_arr_static(ARR, LEN) ((axo__arr){.len=LEN, .cap=0, .data=ARR})

#define axo_arr_at(TYP, ARR, INDEX) (((TYP*)(ARR.data))[INDEX])
#define axo_arr_first(TYP, ARR) (((TYP*)(ARR.data))[0])
#define axo_arr_last(TYP, ARR) (((TYP*)(ARR.data))[ARR.len])

#define axo_arr_del(TYP, ARR, INDEX) ({ \
	TYP AXO_ARR_DEL_RET_ELEM = axo_arr_get(TYP, ARR, INDEX); \
	memmove(&((TYP*)(ARR.data))[INDEX], &((TYP*)(ARR.data))[INDEX+1], (ARR.len-- - INDEX-1)*sizeof(TYP)); \
	AXO_ARR_DEL_RET_ELEM; \
})
//FIX! Add realloc error handling!
#define axo_arr_push(TYP, ARR, VAL) ({ \
	if (!(ARR.len % ARR.cap)) \
		ARR.data=realloc(ARR.data, (ARR.len+ARR.cap)*sizeof(TYP)); \
	axo_arr_at(TYP, ARR, ARR.len++) = VAL; \
})

#define axo_arr_pop(TYP, ARR) ({ \
	ARR.len--; \
	axo_arr_last(TYP, ARR); \
})

#define axo_arr_empty(ARR) (ARR.len == 0)
#define axo_arr_free(ARR) (free(ARR.data))


