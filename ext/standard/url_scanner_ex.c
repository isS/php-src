/* Generated by re2c 0.5 on Tue Sep 11 09:52:19 2001 */
#line 1 "/home/sas/src/php4/ext/standard/url_scanner_ex.re"
/*
  +----------------------------------------------------------------------+
  | PHP version 4.0                                                      |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2001 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.02 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available at through the world-wide-web at                           |
  | http://www.php.net/license/2_02.txt.                                 |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Sascha Schumann <sascha@schumann.cx>                        |
  +----------------------------------------------------------------------+
*/

#include "php.h"

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "php_ini.h"
#include "php_globals.h"
#define STATE_TAG SOME_OTHER_STATE_TAG
#include "basic_functions.h"
#undef STATE_TAG

#define url_adapt_ext url_adapt_ext_ex
#define url_scanner url_scanner_ex

#include "php_smart_str.h"

static PHP_INI_MH(OnUpdateTags)
{
	url_adapt_state_ex_t *ctx;
	char *key;
	char *lasts;
	char *tmp;
	
	ctx = &BG(url_adapt_state_ex);
	
	tmp = estrndup(new_value, new_value_length);
	
	if (ctx->tags)
		zend_hash_destroy(ctx->tags);
	else
		ctx->tags = malloc(sizeof(HashTable));
	
	zend_hash_init(ctx->tags, 0, NULL, NULL, 1);
	
	for (key = php_strtok_r(tmp, ",", &lasts);
			key;
			key = php_strtok_r(NULL, ",", &lasts)) {
		char *val;

		val = strchr(key, '=');
		if (val) {
			char *q;
			int keylen;
			
			*val++ = '\0';
			for (q = key; *q; q++)
				*q = tolower(*q);
			keylen = q - key;
			/* key is stored withOUT NUL
			   val is stored WITH    NUL */
			zend_hash_add(ctx->tags, key, keylen, val, strlen(val)+1, NULL);
		}
	}

	efree(tmp);

	return SUCCESS;
}

PHP_INI_BEGIN()
	STD_PHP_INI_ENTRY("url_rewriter.tags", "a=href,area=href,frame=src,form=fakeentry", PHP_INI_ALL, OnUpdateTags, url_adapt_state_ex, php_basic_globals, basic_globals)
PHP_INI_END()

#line 91


#define YYFILL(n) goto done
#define YYCTYPE unsigned char
#define YYCURSOR p
#define YYLIMIT q
#define YYMARKER r
	
static inline void append_modified_url(smart_str *url, smart_str *dest, smart_str *name, smart_str *val, const char *separator)
{
	register const char *p, *q;
	const char *bash = NULL;
	const char *sep = "?";
	
	q = (p = url->c) + url->len;

scan:
{
	YYCTYPE yych;
	unsigned int yyaccept;
	static unsigned char yybm[] = {
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128,   0, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128,   0, 128, 128, 128, 128,   0, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	};
	goto yy0;
yy1:	++YYCURSOR;
yy0:
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yybm[0+yych] & 128)	goto yy8;
	if(yych <= '9')	goto yy6;
	if(yych >= ';')	goto yy4;
yy2:	yych = *++YYCURSOR;
yy3:
#line 109
	{ smart_str_append(dest, url); return; }
yy4:	yych = *++YYCURSOR;
yy5:
#line 110
	{ sep = separator; goto scan; }
yy6:	yych = *++YYCURSOR;
yy7:
#line 111
	{ bash = p - 1; goto done; }
yy8:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy9:	if(yybm[0+yych] & 128)	goto yy8;
yy10:
#line 112
	{ goto scan; }
}
#line 113

done:
	
	/* Don't modify URLs of the format "#mark" */
	if (bash && bash - url->c == 0) {
		smart_str_append(dest, url);
		return;
	}

	if (bash)
		smart_str_appendl(dest, url->c, bash - url->c);
	else
		smart_str_append(dest, url);

	smart_str_appends(dest, sep);
	smart_str_append(dest, name);
	smart_str_appendc(dest, '=');
	smart_str_append(dest, val);

	if (bash)
		smart_str_appendl(dest, bash, q - bash);
}


#undef YYFILL
#undef YYCTYPE
#undef YYCURSOR
#undef YYLIMIT
#undef YYMARKER

static inline void tag_arg(url_adapt_state_ex_t *ctx, char quote TSRMLS_DC)
{
	char f = 0;

	if (strncasecmp(ctx->arg.c, ctx->lookup_data, ctx->arg.len) == 0)
		f = 1;

	smart_str_appendc(&ctx->result, quote);
	if (f) {
		append_modified_url(&ctx->val, &ctx->result, &ctx->q_name, &ctx->q_value, PG(arg_separator).output);
	} else {
		smart_str_append(&ctx->result, &ctx->val);
	}
	smart_str_appendc(&ctx->result, quote);
}

enum {
	STATE_PLAIN = 0,
	STATE_TAG,
	STATE_NEXT_ARG,
	STATE_ARG,
	STATE_BEFORE_VAL,
	STATE_VAL
};

#define YYFILL(n) goto stop
#define YYCTYPE unsigned char
#define YYCURSOR xp
#define YYLIMIT end
#define YYMARKER q
#define STATE ctx->state

#define STD_PARA url_adapt_state_ex_t *ctx, char *start, char *YYCURSOR TSRMLS_DC
#define STD_ARGS ctx, start, xp TSRMLS_CC

static inline void passthru(STD_PARA) 
{
	smart_str_appendl(&ctx->result, start, YYCURSOR - start);
}

static inline void handle_form(STD_PARA) 
{
	if (ctx->tag.len == 4 && strncasecmp(ctx->tag.c, "form", 4) == 0) {
		smart_str_appends(&ctx->result, "<input type=\"hidden\" name=\""); 
		smart_str_append(&ctx->result, &ctx->q_name);
		smart_str_appends(&ctx->result, "\" value=\"");
		smart_str_append(&ctx->result, &ctx->q_value);
		smart_str_appends(&ctx->result, "\" />");
	}
}

/*
 *  HANDLE_TAG copies the HTML Tag and checks whether we 
 *  have that tag in our table. If we might modify it,
 *  we continue to scan the tag, otherwise we simply copy the complete
 *  HTML stuff to the result buffer.
 */

static inline void handle_tag(STD_PARA) 
{
	int ok = 0;
	int i;

	ctx->tag.len = 0;
	smart_str_appendl(&ctx->tag, start, YYCURSOR - start);
	for (i = 0; i < ctx->tag.len; i++)
		ctx->tag.c[i] = tolower(ctx->tag.c[i]);
	if (zend_hash_find(ctx->tags, ctx->tag.c, ctx->tag.len, (void **) &ctx->lookup_data) == SUCCESS)
		ok = 1;
	STATE = ok ? STATE_NEXT_ARG : STATE_PLAIN;
}

static inline void handle_arg(STD_PARA) 
{
	ctx->arg.len = 0;
	smart_str_appendl(&ctx->arg, start, YYCURSOR - start);
}

static inline void handle_val(STD_PARA, char quotes, char type) 
{
	smart_str_setl(&ctx->val, start + quotes, YYCURSOR - start - quotes * 2);
	tag_arg(ctx, type TSRMLS_CC);
}

#ifdef SCANNER_DEBUG
#define scdebug(x) printf x
#else
#define scdebug(x)
#endif

static inline void mainloop(url_adapt_state_ex_t *ctx, const char *newdata, size_t newlen TSRMLS_DC)
{
	char *end, *q;
	char *xp;
	char *start;
	int rest;

	smart_str_appendl(&ctx->buf, newdata, newlen);
	
	YYCURSOR = ctx->buf.c;
	YYLIMIT = ctx->buf.c + ctx->buf.len;

	switch (STATE) {
		case STATE_PLAIN: goto state_plain;
		case STATE_TAG: goto state_tag;
		case STATE_NEXT_ARG: goto state_next_arg;
		case STATE_ARG: goto state_arg;
		case STATE_BEFORE_VAL: goto state_before_val;
		case STATE_VAL: goto state_val;
	}
	

state_plain_begin:
	STATE = STATE_PLAIN;
	
state_plain:
	start = YYCURSOR;
{
	YYCTYPE yych;
	unsigned int yyaccept;
	static unsigned char yybm[] = {
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128,   0, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	};
	goto yy11;
yy12:	++YYCURSOR;
yy11:
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yybm[0+yych] & 128)	goto yy15;
yy13:	yych = *++YYCURSOR;
yy14:
#line 261
	{ passthru(STD_ARGS); STATE = STATE_TAG; goto state_tag; }
yy15:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy16:	if(yybm[0+yych] & 128)	goto yy15;
yy17:
#line 262
	{ passthru(STD_ARGS); goto state_plain; }
}
#line 263


state_tag:	
	start = YYCURSOR;
{
	YYCTYPE yych;
	unsigned int yyaccept;
	static unsigned char yybm[] = {
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128,   0,   0,   0,   0,   0, 
	  0, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	};
	goto yy18;
yy19:	++YYCURSOR;
yy18:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= '@')	goto yy22;
	if(yych <= 'Z')	goto yy20;
	if(yych <= '`')	goto yy22;
	if(yych >= '{')	goto yy22;
yy20:	yych = *++YYCURSOR;
	goto yy25;
yy21:
#line 268
	{ handle_tag(STD_ARGS); /* Sets STATE */; passthru(STD_ARGS); if (STATE == STATE_PLAIN) goto state_plain; else goto state_next_arg; }
yy22:	yych = *++YYCURSOR;
yy23:
#line 269
	{ passthru(STD_ARGS); goto state_plain_begin; }
yy24:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy25:	if(yybm[0+yych] & 128)	goto yy24;
	goto yy21;
}
#line 270


state_next_arg_begin:
	STATE = STATE_NEXT_ARG;
	
state_next_arg:
	start = YYCURSOR;
{
	YYCTYPE yych;
	unsigned int yyaccept;
	static unsigned char yybm[] = {
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0, 128, 128, 128,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	128,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	};
	goto yy26;
yy27:	++YYCURSOR;
yy26:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= '='){
		if(yych <= '\v'){
			if(yych <= '\b')	goto yy34;
			goto yy30;
		} else {
			if(yych == ' ')	goto yy30;
			goto yy34;
		}
	} else {
		if(yych <= 'Z'){
			if(yych <= '>')	goto yy28;
			if(yych <= '@')	goto yy34;
			goto yy32;
		} else {
			if(yych <= '`')	goto yy34;
			if(yych <= 'z')	goto yy32;
			goto yy34;
		}
	}
yy28:	yych = *++YYCURSOR;
yy29:
#line 278
	{ passthru(STD_ARGS); handle_form(STD_ARGS); goto state_plain_begin; }
yy30:	yych = *++YYCURSOR;
	goto yy37;
yy31:
#line 279
	{ passthru(STD_ARGS); goto state_next_arg; }
yy32:	yych = *++YYCURSOR;
yy33:
#line 280
	{ --YYCURSOR; STATE = STATE_ARG; goto state_arg; }
yy34:	yych = *++YYCURSOR;
yy35:
#line 281
	{ passthru(STD_ARGS); goto state_plain_begin; }
yy36:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy37:	if(yybm[0+yych] & 128)	goto yy36;
	goto yy31;
}
#line 282


state_arg:
	start = YYCURSOR;
{
	YYCTYPE yych;
	unsigned int yyaccept;
	static unsigned char yybm[] = {
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128,   0,   0,   0,   0,   0, 
	  0, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128, 128, 128, 128, 128, 128, 
	128, 128, 128,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	};
	goto yy38;
yy39:	++YYCURSOR;
yy38:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= '@')	goto yy42;
	if(yych <= 'Z')	goto yy40;
	if(yych <= '`')	goto yy42;
	if(yych >= '{')	goto yy42;
yy40:	yych = *++YYCURSOR;
	goto yy45;
yy41:
#line 287
	{ passthru(STD_ARGS); handle_arg(STD_ARGS); STATE = STATE_BEFORE_VAL; goto state_before_val; }
yy42:	yych = *++YYCURSOR;
yy43:
#line 288
	{ passthru(STD_ARGS); STATE = STATE_NEXT_ARG; goto state_next_arg; }
yy44:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy45:	if(yybm[0+yych] & 128)	goto yy44;
	goto yy41;
}
#line 289


state_before_val:
	start = YYCURSOR;
{
	YYCTYPE yych;
	unsigned int yyaccept;
	static unsigned char yybm[] = {
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	128,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	  0,   0,   0,   0,   0,   0,   0,   0, 
	};
	goto yy46;
yy47:	++YYCURSOR;
yy46:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych == ' ')	goto yy48;
	if(yych == '=')	goto yy50;
	goto yy52;
yy48:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == ' ')	goto yy55;
	if(yych == '=')	goto yy53;
yy49:
#line 295
	{ --YYCURSOR; goto state_next_arg_begin; }
yy50:	yych = *++YYCURSOR;
	goto yy54;
yy51:
#line 294
	{ passthru(STD_ARGS); STATE = STATE_VAL; goto state_val; }
yy52:	yych = *++YYCURSOR;
	goto yy49;
yy53:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy54:	if(yybm[0+yych] & 128)	goto yy53;
	goto yy51;
yy55:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy56:	if(yych == ' ')	goto yy55;
	if(yych == '=')	goto yy53;
yy57:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy49;
	}
}
#line 296



state_val:
	start = YYCURSOR;
{
	YYCTYPE yych;
	unsigned int yyaccept;
	static unsigned char yybm[] = {
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 192, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	192, 224,  64, 224, 224, 224, 224, 128, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224,   0, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	224, 224, 224, 224, 224, 224, 224, 224, 
	};
	goto yy58;
yy59:	++YYCURSOR;
yy58:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= '!'){
		if(yych <= '\n'){
			if(yych <= '\t')	goto yy63;
			goto yy65;
		} else {
			if(yych == ' ')	goto yy65;
			goto yy63;
		}
	} else {
		if(yych <= '\''){
			if(yych <= '"')	goto yy60;
			if(yych <= '&')	goto yy63;
			goto yy62;
		} else {
			if(yych == '>')	goto yy65;
			goto yy63;
		}
	}
yy60:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych != '>')	goto yy74;
yy61:
#line 305
	{ passthru(STD_ARGS); goto state_next_arg_begin; }
yy62:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == '>')	goto yy61;
	goto yy69;
yy63:	yych = *++YYCURSOR;
	goto yy67;
yy64:
#line 304
	{ handle_val(STD_ARGS, 0, '"'); goto state_next_arg_begin; }
yy65:	yych = *++YYCURSOR;
	goto yy61;
yy66:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy67:	if(yybm[0+yych] & 32)	goto yy66;
	goto yy64;
yy68:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy69:	if(yybm[0+yych] & 64)	goto yy68;
	if(yych <= '=')	goto yy71;
yy70:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy61;
	}
yy71:	yych = *++YYCURSOR;
yy72:
#line 303
	{ handle_val(STD_ARGS, 1, '\''); goto state_next_arg_begin; }
yy73:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy74:	if(yybm[0+yych] & 128)	goto yy73;
	if(yych >= '>')	goto yy70;
yy75:	yych = *++YYCURSOR;
yy76:
#line 302
	{ handle_val(STD_ARGS, 1, '"'); goto state_next_arg_begin; }
}
#line 306


stop:
	rest = YYLIMIT - start;
	scdebug(("stopped in state %d at pos %d (%d:%c) %d\n", STATE, YYCURSOR - ctx->buf.c, *YYCURSOR, *YYCURSOR, rest));
	/* XXX: Crash avoidance. Need to work with reporter to figure out what goes wrong */	
	if (rest < 0) rest = 0;
	
	if (rest) memmove(ctx->buf.c, start, rest);
	ctx->buf.len = rest;
}


char *url_adapt_single_url(const char *url, size_t urllen, const char *name, const char *value, size_t *newlen TSRMLS_DC)
{
	smart_str surl = {0};
	smart_str buf = {0};
	smart_str sname = {0};
	smart_str sval = {0};

	smart_str_setl(&surl, url, urllen);
	smart_str_sets(&sname, name);
	smart_str_sets(&sval, value);

	append_modified_url(&surl, &buf, &sname, &sval, PG(arg_separator).output);

	smart_str_0(&buf);
	if (newlen) *newlen = buf.len;
	
	return buf.c;
}

char *url_adapt_ext(const char *src, size_t srclen, const char *name, const char *value, size_t *newlen, zend_bool do_flush TSRMLS_DC)
{
	url_adapt_state_ex_t *ctx;
	char *retval;

	ctx = &BG(url_adapt_state_ex);

	smart_str_sets(&ctx->q_name, name);
	smart_str_sets(&ctx->q_value, value);
	mainloop(ctx, src, srclen TSRMLS_CC);

	*newlen = ctx->result.len;
	if (!ctx->result.c) {
		smart_str_appendl(&ctx->result, "", 0);
	}
	smart_str_0(&ctx->result);
	if (do_flush) {
		smart_str_appendl(&ctx->result, ctx->buf.c, ctx->buf.len);
		*newlen += ctx->buf.len;
		smart_str_free(&ctx->buf);
	}
	retval = ctx->result.c;
	ctx->result.c = NULL;
	ctx->result.len = 0;
	return retval;
}

int php_url_scanner_ex_activate(TSRMLS_D)
{
	url_adapt_state_ex_t *ctx;
	
	ctx = &BG(url_adapt_state_ex);

	memset(ctx, 0, ((size_t) &((url_adapt_state_ex_t *)0)->tags));

	return SUCCESS;
}

int php_url_scanner_ex_deactivate(TSRMLS_D)
{
	url_adapt_state_ex_t *ctx;
	
	ctx = &BG(url_adapt_state_ex);

	smart_str_free(&ctx->result);
	smart_str_free(&ctx->buf);
	smart_str_free(&ctx->tag);
	smart_str_free(&ctx->arg);

	return SUCCESS;
}

PHP_MINIT_FUNCTION(url_scanner)
{
	url_adapt_state_ex_t *ctx;
	
	ctx = &BG(url_adapt_state_ex);

	ctx->tags = NULL;
	
	REGISTER_INI_ENTRIES();
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(url_scanner)
{
	UNREGISTER_INI_ENTRIES();
	zend_hash_destroy(BG(url_adapt_state_ex).tags);
	free(BG(url_adapt_state_ex).tags);
	return SUCCESS;
}
