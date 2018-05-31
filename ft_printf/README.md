# ft_printf
project recode function **printf**

>work like **printf**
***
### see projet's pdf for more info
* **[link to pdf](https://cdn.intra.42.fr/pdf/pdf/20/ft_printf.pdf)**
### see man printf
* **[man printf](http://manpagesfr.free.fr/man/man3/printf.3.html)**

***
### Includes
* **wchar.h**
for `wchat_t` type
* **string.h**
for `size_t` def
* **limit.h**
for `OPEN_MAX` and `INT64_MAX`
* **unistd.h**
for `write()`
* **stdlib.h**
for `NULL` and `MB_CURL_MAX`
* **stdarg.h**
for `va_list`, `va_start()`, `va_copy()` and `va_end()`
***
### Constante
* `BUFF_SIZE_PRINTF` : the buffer size of ft_printf when it full it flush
* `NB_FC` : the number of function alias number of working flags
* `NB_COLOR` : the number of color and type
***
#### **Function**

```C
ft_printf(char const *format, ...);
ft_dprintf(int fd, char const *format, ...);
ft_eprintf(char const *s, ...);
ft_fprintf(FILE *file, char const *format, ...);
ft_sprintf(char *dest, char const *format, ...);
ft_snprint(char *dest, size_t n, char const *format, ...);
ft_asprintf(char **as, char const *format, ...);

ft_vdprintf(int fd, char const *format, va_list ap);
ft_vfprintf(FILE *file, char const *format, va_list ap);
ft_vsprintf(char *dest, char const *format, va_list ap);
ft_vsnprintf(char *dest, size_t n, char const *format, va_list ap);
ft_vasprintf(char **as, char const *format, va_list ap);
```
**work also with color**

#### Color & Style
* [see enum e_color](https://github.com/FirelightFlagboy/ft_printf/blob/master/includes/ft_printf.h)
	- use with flag `%@`
***
