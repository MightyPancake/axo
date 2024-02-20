#include <stdlib.h>
#include <string.h>
/*

    AXO_ARRAY

*/

typedef char axo_arr_flags;
#define axo_arr_dim_t unsigned
#define axo_arr_it_t unsigned

#define AXO_ARR_FLAG_0 0x01
#define AXO_ARR_FLAG_1 0x02
#define AXO_ARR_FLAG_2 0x04
#define AXO_ARR_FLAG_3 0x08
#define AXO_ARR_FLAG_4 0x10
#define AXO_ARR_FLAG_5 0x20
#define AXO_ARR_FLAG_6 0x40
#define AXO_ARR_FLAG_7 0x80

#define AXO_ARR_DYN_FLAG AXO_ARR_FLAG_7
#define AXO_ARR_DYNAMIC AXO_ARR_DYN_FLAG
#define AXO_ARR_STATIC 0x00

typedef struct axo__arr{
    axo_arr_flags   flags;
    axo_arr_dim_t*  len;
    void*           data;
}axo__arr;

//FIX: Flags?
#define axo_arr_from_stat_str(STR) (axo__arr){ \
    .data=STR, \
    .len=(axo_arr_dim_t[]){(axo_arr_dim_t)strlen(STR)} \
}

#define axo_arr_is_dynamic(AXO_ARR) ((AXO_ARR_DYN_FLAG & AXO_ARR.flags)>>7)
#define axo_arr_dim_count(AXO_ARR) (0x7F & AXO_ARR.flags)

#define axo_arr_1d_at(TYP, AXO_ARR, A) (((TYP*)(AXO_ARR.data))[A])
#define axo_arr_2d_at(TYP, AXO_ARR, A, B) (((TYP*)(AXO_ARR.data))[(A)*(AXO_ARR.len[1]) + (B)])
#define axo_arr_3d_at(TYP, AXO_ARR, A, B, C) (((TYP*)(AXO_ARR.data))[(A)*(AXO_ARR.len[1]*(AXO_ARR.len[2])) + (B)*(AXO_ARR.len[1]) + (C)])   

#define axo_arr_nd_at(TYP, AXO_ARR, INDICES) ({ \
    arr_it_t index=0; \
    for (axo_arr_dim_flags arr_dim_it = 0; arr_dim_it < arr_dim_count(AXO_ARR); arr_dim_it++){ \
        1; \
    } \
    1; \
})

#define axo_arr_new(DATA, DIMS, FLAGS) ((axo__arr){ \
    .flags = FLAGS, \
    .len=DIMS, \
    .data=DATA \
})

#define axo_arr_new_dyn(DATA, DIMS) axo_arr_new(DATA, DIMS, AXO_ARR_DYNAMIC)
#define axo_arr_new_stat(DATA, DIMS) axo_arr_new(DATA, DIMS, AXO_ARR_STATIC)

#define axo_arr_new_with_dim_count(DATA, DIMS, FLAGS, DIM_COUNT) ((arr){ \
    .flags = (FLAGS) | (DIM_COUNT), \
    .len=DIMS, \
    .data=DATA \
})

/*

    Main entry

*/

int axo__main(axo__arr args);

int main(int argc, char** argv){
    axo__arr args = (axo__arr){
        .data=malloc(argc*sizeof(axo__arr)),
        .len=(axo_arr_dim_t[]){argc}
    };
    for (int i=0; i<argc; i++)
        axo_arr_1d_at(axo__arr, args, i) = axo_arr_from_stat_str(argv[i]);
    axo__main(args);
}
