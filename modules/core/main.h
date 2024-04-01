/*

    Main entry

*/
// #define AXO_MAIN_ENTRY_POINT axo__main
// int axo__main(axo__arr args);
AXO_DEFINE_ENTRY_POINT

int main(int argc, char** argv){
    axo__arr args = (axo__arr){
        .data=malloc(argc*sizeof(axo__arr)),
        .len=(axo_arr_dim_t[]){argc}
    };
    for (int i=0; i<argc; i++)
        axo_arr_1d_at(axo__arr*, args, i) = axo_arr_from_stat_str(argv[i]);
    AXO_MAIN_ENTRY_POINT(args);
}

