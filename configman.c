#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "configman.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *configman_baseserviceconfig_ce;
zend_class_entry *configman_service_serviceconfig_ce;
zend_class_entry *configman_service_memcache_memcacheconfig_ce;
zend_class_entry *configman_service_mysql_mysqlconfig_ce;
zend_class_entry *configman_service_rabbitmq_rabbitmqconfig_ce;
zend_class_entry *configman_service_redis_redisconfig_ce;

ZEND_DECLARE_MODULE_GLOBALS(configman)

PHP_INI_BEGIN()
    PHP_INI_ENTRY("configman.config_path", "/test", PHP_INI_ALL, NULL)
PHP_INI_END()

static PHP_MINIT_FUNCTION(configman)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Configman_BaseServiceConfig);
	ZEPHIR_INIT(Configman_Service_ServiceConfig);
	ZEPHIR_INIT(Configman_Service_Memcache_MemcacheConfig);
	ZEPHIR_INIT(Configman_Service_Mysql_MysqlConfig);
	ZEPHIR_INIT(Configman_Service_Rabbitmq_RabbitmqConfig);
	ZEPHIR_INIT(Configman_Service_Redis_RedisConfig);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(configman)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_configman_globals *configman_globals TSRMLS_DC)
{
	configman_globals->initialized = 0;

	/* Memory options */
	configman_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	configman_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	configman_globals->cache_enabled = 1;

	/* Recursive Lock */
	configman_globals->recursive_lock = 0;

	/* Static cache */
	memset(configman_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(configman)
{

	zend_configman_globals *configman_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(configman_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(configman_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(configman)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(configman)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_CONFIGMAN_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_CONFIGMAN_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_CONFIGMAN_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_CONFIGMAN_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Meilishuo", "Version " PHP_CONFIGMAN_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(configman)
{
	php_zephir_init_globals(configman_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(configman)
{

}


zend_function_entry php_configman_functions[] = {
ZEND_FE_END

};

zend_module_entry configman_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_CONFIGMAN_EXTNAME,
	php_configman_functions,
	PHP_MINIT(configman),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(configman),
#else
	NULL,
#endif
	PHP_RINIT(configman),
	PHP_RSHUTDOWN(configman),
	PHP_MINFO(configman),
	PHP_CONFIGMAN_VERSION,
	ZEND_MODULE_GLOBALS(configman),
	PHP_GINIT(configman),
	PHP_GSHUTDOWN(configman),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_CONFIGMAN
ZEND_GET_MODULE(configman)
#endif
