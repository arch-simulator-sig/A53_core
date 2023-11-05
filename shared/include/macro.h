#ifndef __MACRO_H__
#define __MACRO_H__

#include <string.h>

#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

// macro stringizing
#define _STR(x) #x
#define STR(x) _STR(x)

// strlen() for string constant
#define STRLEN(CONST_STR) (sizeof(CONST_STR) - 1)

// calculate the length of an array
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

// macro concatenation
#define _CONCAT(x, y) x##y
#define CONCAT(x, y) _CONCAT(x, y)
#define CONCAT3(x, y, z) CONCAT(CONCAT(x, y), z)
#define CONCAT4(x, y, z, w) CONCAT3(CONCAT(x, y), z, w)
#define CONCAT5(x, y, z, v, w) CONCAT4(CONCAT(x, y), z, v, w)

#define CHOOSE1st(a, ...) a
#define CHOOSE2nd(a, b, ...) b
#define EMPTY()

// code generator
#define EVAL(...) EVAL32(__VA_ARGS__)
#define EVAL32(...) EVAL16(EVAL16(__VA_ARGS__))
#define EVAL16(...) EVAL8(EVAL8(__VA_ARGS__))
#define EVAL8(...) EVAL4(EVAL4(__VA_ARGS__))
#define EVAL4(...) EVAL2(EVAL2(__VA_ARGS__))
#define EVAL2(...) EVAL1(EVAL1(__VA_ARGS__))
#define EVAL1(...) __VA_ARGS__

#define DEFER1(m) m EMPTY()
#define DEFER2(m) m EMPTY EMPTY()()

#define NOT(x) _NOT(CONCAT(_NOT_, x))
#define _NOT(...) CHOOSE2nd(__VA_ARGS__, 0)
#define _NOT_0 ~, 1

#define BOOL(x) NOT(NOT(x))

#define IF(condition) CONCAT(_IF_, BOOL(condition))
#define _IF_0(...)
#define _IF_1(...) __VA_ARGS__

#define HAS_ARGS(...) BOOL(CHOOSE1st(_END_OF_ARGUMENTS_ __VA_ARGS__)())
#define HAS_TWO_ARGS(first, ...) HAS_ARGS(__VA_ARGS__)
#define _END_OF_ARGUMENTS_() 0

#define MAP(m, first, ...) EVAL(_MAP(m, first, __VA_ARGS__))
#define _MAP(m, first, ...) m(first) IF(HAS_ARGS(__VA_ARGS__))(DEFER2(__MAP)()(m, __VA_ARGS__))
#define __MAP() _MAP

#define MAP_TWO_ARGS(m, first, second, ...) EVAL(_MAP_TWO_ARGS(m, first, second, __VA_ARGS__))
#define _MAP_TWO_ARGS(m, first, second, ...) \
    m(first, second) IF(HAS_TWO_ARGS(__VA_ARGS__))(DEFER2(__MAP_TWO_ARGS)()(m, __VA_ARGS__))
#define __MAP_TWO_ARGS() _MAP_TWO_ARGS

// macro testing
// See https://stackoverflow.com/questions/26099745/test-if-preprocessor-symbol-is-defined-inside-macro

#define MUX_WITH_COMMA(contain_comma, a, b) CHOOSE2nd(contain_comma a, b)
#define MUX_MACRO_PROPERTY(p, macro, a, b) MUX_WITH_COMMA(CONCAT(p, macro), a, b)
// define placeholders for some property
#define __P_DEF_0 X,
#define __P_DEF_1 X,
#define __P_ONE_1 X,
#define __P_ZERO_0 X,
// define some selection functions based on the properties of BOOLEAN macro
#define MUXDEF(macro, X, Y) MUX_MACRO_PROPERTY(__P_DEF_, macro, X, Y)
#define MUXNDEF(macro, X, Y) MUX_MACRO_PROPERTY(__P_DEF_, macro, Y, X)
#define MUXONE(macro, X, Y) MUX_MACRO_PROPERTY(__P_ONE_, macro, X, Y)
#define MUXZERO(macro, X, Y) MUX_MACRO_PROPERTY(__P_ZERO_, macro, X, Y)

// test if a boolean macro is defined
#define ISDEF(macro) MUXDEF(macro, 1, 0)
// test if a boolean macro is undefined
#define ISNDEF(macro) MUXNDEF(macro, 1, 0)
// test if a boolean macro is defined to 1
#define ISONE(macro) MUXONE(macro, 1, 0)
// test if a boolean macro is defined to 0
#define ISZERO(macro) MUXZERO(macro, 1, 0)
// test if a macro of ANY type is defined
// NOTE1: it ONLY works inside a function, since it calls `strcmp()`
// NOTE2: macros defined to themselves (#define A A) will get wrong results
#define isdef(macro) (strcmp("" #macro, "" STR(macro)) != 0)

// simplification for conditional compilation
#define __IGNORE(...)
#define __KEEP(...) __VA_ARGS__
// keep the code if a boolean macro is defined
#define IFDEF(macro, ...) MUXDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)
// keep the code if a boolean macro is undefined
#define IFNDEF(macro, ...) MUXNDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)
// keep the code if a boolean macro is defined to 1
#define IFONE(macro, ...) MUXONE(macro, __KEEP, __IGNORE)(__VA_ARGS__)
// keep the code if a boolean macro is defined to 0
#define IFZERO(macro, ...) MUXZERO(macro, __KEEP, __IGNORE)(__VA_ARGS__)

#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog
#define SEXT(x, len)         \
    ({                       \
        struct               \
        {                    \
            int64_t n : len; \
        } __x = {.n = x};    \
        (uint64_t) __x.n;    \
    })

#ifdef __cplusplus
#undef SEXT
#define SEXT(x, len)                            \
    ({                                          \
        struct                                  \
        {                                       \
            int64_t n : len;                    \
        } __x = {.n = static_cast<int64_t>(x)}; \
        (uint64_t) __x.n;                       \
    })

#endif

#define ROUNDUP(a, sz) ((((uintptr_t)a) + (sz)-1) & ~((sz)-1))
#define ROUNDDOWN(a, sz) ((((uintptr_t)a)) & ~((sz)-1))

#define PG_ALIGN __attribute((aligned(4096)))

#if !defined(likely)
#define likely(cond) __builtin_expect(cond, 1)
#define unlikely(cond) __builtin_expect(cond, 0)
#endif

// for AM IOE
#define io_read(reg)                \
    ({                              \
        reg##_T __io_param;         \
        ioe_read(reg, &__io_param); \
        __io_param;                 \
    })

#define io_write(reg, ...)                           \
    ({                                               \
        reg##_T __io_param = (reg##_T){__VA_ARGS__}; \
        ioe_write(reg, &__io_param);                 \
    })

#endif
