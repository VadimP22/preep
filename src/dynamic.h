#define DYNAMIC_APPEND(type, ptr, count, capacity, element) \
    do { \
        (count) += 1; \
        if ((count) > (capacity)) { \
            int _old_capacity = (capacity); \
            if ((capacity) == 0) { \
                (capacity) = 1; \
            } else { \
                (capacity) *= 2; \
            } \
            type* _new_array = (type*) malloc(sizeof(type) * (capacity)); \
            assert(_new_array != 0); \
            if (_old_capacity != 0) { \
                assert((ptr) != 0); \
                memcpy(_new_array, (ptr), sizeof(type) * _old_capacity); \
            } \
            (ptr) = _new_array; \
        } \
        (ptr)[(count) - 1] = (element); \
    } while(0)
