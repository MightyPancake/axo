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

typedef struct axo__arr{
    axo_arr_flags   flags;
    axo_arr_dim_t*  len;
    void*           data;
}axo__arr;

#define AXO_ARR_CAP_FLAG ((char)(0x1F))
#define AXO_ARR_STATIC 0x00
//Default cap set to 6 (2^5=32)
// #define axo_default_arr_cap (char) 0x06
#define axo_default_arr_cap ((char)(1))

#define axo_arr_cap_tab(CAP) ( \
    (unsigned[32]){ \
        0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824 \
    }[CAP] \
)

#define AXO_NULL_ARR (axo_arr){ \
    .flags = AXO_ARR_STATIC, \
    .len=(axo_arr_dimt_t[]){0,0,0,0}, \
    .data=NULL \
}

#define axo_arr_from_stat_str(STR) (axo__arr){ \
    .data=STR, \
    .len=(axo_arr_dim_t[]){(axo_arr_dim_t)strlen(STR)} \
}

#define axo_arr_cap(AXO_ARR) (((AXO_ARR).flags)&AXO_ARR_CAP_FLAG)
#define axo_arr_get_cap(AXO_ARR) axo_arr_cap_tab(axo_arr_cap(AXO_ARR))
#define axo_arr_is_dynamic(AXO_ARR) axo_arr_cap(AXO_ARR)
#define axo_arr_is_static(AXO_ARR) (!axo_arr_is_dynamic(AXO_ARR))

#define axo_arr_at(TYP, AXO_ARR, A) (((TYP)(AXO_ARR.data))[A])

#define axo_arr_1d_at(TYP, AXO_ARR, A) (((TYP)(AXO_ARR.data))[A])
#define axo_arr_2d_at(TYP, AXO_ARR, A, B) (((TYP)(AXO_ARR.data))[(A)*(AXO_ARR.len[1]) + (B)])
#define axo_arr_3d_at(TYP, AXO_ARR, A, B, C) (((TYP)(AXO_ARR.data))[(A)*(AXO_ARR.len[1]*(AXO_ARR.len[2])) + (B)*(AXO_ARR.len[1]) + (C)])   

#define axo_dyn_bytes_cpy(RES_TYP, SRC, SZ) ({ \
    RES_TYP TMP = malloc(SZ); \
    TMP = memcpy(TMP, (SRC), (SZ)); \
    TMP; \
})

#define axo_arr_new(DATA, DIMS, FLAGS) ((axo__arr){ \
    .flags = FLAGS, \
    .len=DIMS, \
    .data=DATA \
})

#define axo_arr_new_stat(DATA, DIMS) axo_arr_new(DATA, DIMS, AXO_ARR_STATIC)
#define axo_arr_new_dyn(DATA, DIMS) axo_arr_new(DATA, DIMS, axo_default_arr_cap)

//Array methods
//FIX: This should | the flags byte?
#define axo_arr_set_cap(AXO_ARR, CAP) ({ \
    (AXO_ARR)->flags = ((char)((CAP)&AXO_ARR_CAP_FLAG)); \
    (AXO_ARR); \
})

//Get the length of the underlying data
#define axo_arr_data_len_1d(AXO_ARR) ((AXO_ARR).len[0])
#define axo_arr_data_len_2d(AXO_ARR) ((AXO_ARR).len[0]*(AXO_ARR).len[1])
#define axo_arr_data_len_3d(AXO_ARR) ((AXO_ARR).len[0]*(AXO_ARR).len[1]*(AXO_ARR).len[2])

//Shrink the array (len=sz)
#define axo_arr_shrink_1d(TYP, AXO_ARR) axo_arr_rsz(TYP, (AXO_ARR), axo_arr_data_len_1d((AXO_ARR)))

#define axo_arr_shrink_2d(TYP, AXO_ARR) axo_arr_rsz(TYP, (AXO_ARR), axo_arr_data_len_2d((AXO_ARR)))
#define axo_arr_shrink_3d(TYP, AXO_ARR) axo_arr_rsz(TYP, (AXO_ARR), axo_arr_data_len_3d((AXO_ARR)))

#define axo_arr_pop_1d(PTYP, AXO_ARR) (((PTYP)((AXO_ARR)->data))[--((AXO_ARR)->len[0])])
#define axo_arr_pop_2d(PTYP, AXO_ARR) (((PTYP)((AXO_ARR)->data))[--((AXO_ARR)->len[1])])

//FIX: Error handling
//Resize the underlying ptr
#define axo_arr_rsz(ELEM_TYP, AXO_ARR, SZ){ \
    (AXO_ARR).data = realloc((AXO_ARR).data, (SZ)*sizeof(ELEM_TYP)); \
    ((unsigned)(SZ)); \
}

#define axo_arr_1d_append(TYP, ELEM_TYP, AXO_ARR, ELEM) ({ \
    if (axo_arr_data_len_1d((*(AXO_ARR))) % axo_arr_get_cap((*(AXO_ARR))) == 0) \
        axo_arr_rsz(ELEM_TYP, *(AXO_ARR), ((AXO_ARR)->len[0]+axo_arr_get_cap((*(AXO_ARR))))*sizeof(ELEM_TYP)) \
    axo_arr_1d_at(TYP, (*(AXO_ARR)), (AXO_ARR)->len[0]++) = ELEM; \
    ELEM; \
})

#define axo_arr_free(AXO_ARR) free((AXO_ARR)->data)
