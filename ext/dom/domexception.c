/*
   +----------------------------------------------------------------------+
   | PHP Version 4                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2003 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Christian Stocker <chregu@php.net>                          |
   |          Rob Richards <rrichards@php.net>                            |
   +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#if HAVE_LIBXML && HAVE_DOM
#include "php_dom.h"


/*
* class domexception 
*
* URL: http://www.w3.org/TR/2003/WD-DOM-Level-3-Core-20030226/DOM3-Core.html#core-ID-17189187
* Since: 
*/

extern zend_class_entry *dom_domexception_class_entry;

zend_function_entry php_dom_domexception_class_functions[] = {
	{NULL, NULL, NULL}
};

void php_dom_throw_error(int error_code, int strict_error TSRMLS_DC)
{
	char *error_message;

	switch (error_code)
	{
		case INDEX_SIZE_ERR:
			error_message = "Index Size Error";
			break;
		case DOMSTRING_SIZE_ERR:
			error_message = "DOM String Size Error";
			break;
		case HIERARCHY_REQUEST_ERR:
			error_message = "Hierarchy Request Error";
			break;
		case WRONG_DOCUMENT_ERR:
			error_message = "Wrong Document Error";
			break;
		case INVALID_CHARACTER_ERR:
			error_message = "Invalid Character Error";
			break;
		case NO_DATA_ALLOWED_ERR:
			error_message = "No Data Allowed Error";
			break;
		case NO_MODIFICATION_ALLOWED_ERR:
			error_message = "No Modification Allowed Error";
			break;
		case NOT_FOUND_ERR:
			error_message = "Not Found Error";
			break;
		case NOT_SUPPORTED_ERR:
			error_message = "Not Supported Error";
			break;
		case INUSE_ATTRIBUTE_ERR:
			error_message = "Inuse Attribute Error";
			break;
		case INVALID_STATE_ERR:
			error_message = "Invalid State Error";
			break;
		case SYNTAX_ERR:
			error_message = "Syntax Error";
			break;
		case INVALID_MODIFICATION_ERR:
			error_message = "Invalid Modification Error";
			break;
		case NAMESPACE_ERR:
			error_message = "Namespace Error";
			break;
		case INVALID_ACCESS_ERR:
			error_message = "Invalid Access Error";
			break;
		case VALIDATION_ERR:
			error_message = "Validation Error";
			break;
		default:
			error_message = "Unhandled Error";
	}

	if (strict_error == 1) {
		zend_throw_exception(dom_domexception_class_entry, error_message, error_code TSRMLS_CC);
	} else {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, error_message);
	}
}

#endif /* HAVE_LIBXML && HAVE_DOM */
