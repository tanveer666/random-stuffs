//List of headers for the sort functions.


#ifndef header_h
#define header_h

int isBiggerInt(void* key1, void* key2);
int isBiggerFloat( void* key1, void* key2);
int isBiggerChar( void* key1, void* key2);

int inssort(void *data, int num_of_obj, int type_size, int (*comp) (void *dat1, void *dat2));
int partition(void *data, int array_start, int array_end, int e_size, int (*fp_compare)(void *key1, void *key2));
int qk_sort(void *data, int array_size, int e_size, int high, int low, int (*compare)(void *key1, void *key2));


#endif
