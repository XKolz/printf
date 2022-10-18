#ifndef _MAIN_H_
#define _MAIN_H_
#define INT_BITS (4 * 8)

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/**
 * struct call - struct call
 * @t: t - flag for data type
 * @f: function - assocated function
 *
 */
typedef struct call
{
	char t;
	int (*f)(char *, va_list, int);
} call_t;


/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;


int _printf(const char *format, ...);
int buff_append(char *buff_dest, va_list arg, int buff_count, char type);
int print_buff(char *buff, unsigned int nbuff);
int str_len(char *s);
char *_strcpy(char *dest, char *src);
int parse_char(char *buff_dest, va_list arg, int buff_count);
int parse_str(char *buff_dest, va_list arg, int buff_count);
int parse_int(char *buff_dest, va_list list, int buff_count);
int parse_perc(char *buff_dest, va_list arg, int buff_count);
unsigned int parse_bin(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
int parse_oct(char *buff_dest, va_list arg, int buff_count);
int parse_hex(char *buff_dest, va_list arg, int buff_count);
int parse_X(char *buff_dest, va_list arg, int buff_count);
int parse_uint(char *buff_dest, va_list arg, int buff_count);
int parse_rev(char *buff_dest, va_list arg, int buff_count);
int parse_R13(char *buff_dest, va_list arg, int buff_count);

buffer_t *init_buffer(void);
void free_buffer(buffer_t *output);
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
unsigned int convert_sbase(buffer_t *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int convert_ubase(buffer_t *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

#endif
