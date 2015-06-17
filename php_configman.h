
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_CONFIGMAN_H
#define PHP_CONFIGMAN_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_CONFIGMAN_NAME        "configman"
#define PHP_CONFIGMAN_VERSION     "0.0.1"
#define PHP_CONFIGMAN_EXTNAME     "configman"
#define PHP_CONFIGMAN_AUTHOR      "Jobs Wang"
#define PHP_CONFIGMAN_ZEPVERSION  "0.7.0b"
#define PHP_CONFIGMAN_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(configman)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(configman)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(configman)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(configman_globals_id, zend_configman_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (configman_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_configman_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(configman_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(configman_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def configman_globals
#define zend_zephir_globals_def zend_configman_globals

extern zend_module_entry configman_module_entry;
#define phpext_configman_ptr &configman_module_entry

#endif
