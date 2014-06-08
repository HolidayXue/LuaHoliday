/* Lua CJSON floating point conversion routines */

/* Buffer required to store the largest string representation of a double.
 *
 * Longest double printed with %.14g is 21 characters long:
 * -1.7976931348623e+308 */
# define FPCONV_G_FMT_BUFSIZE   32

#ifdef USE_INTERNAL_FPCONV
static inline void fpconv_init()
{
    /* Do nothing - not required */
}
#else
extern void fpconv_init();
#endif
#ifndef __fpconv_g_fmt_D__
#define __fpconv_g_fmt_D__
extern int fpconv_g_fmt(char*, double, int);
extern double fpconv_strtod(const char*, char**);
#endif
#ifdef WIN32
#define snprintf _snprintf
#define inline _inline
#endif


/* vi:ai et sw=4 ts=4:
 */
