
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/hash.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Configman_Service_Memcache_MemcacheConfig) {

	ZEPHIR_REGISTER_CLASS_EX(Configman\\Service\\Memcache, MemcacheConfig, configman, service_memcache_memcacheconfig, configman_service_serviceconfig_ce, configman_service_memcache_memcacheconfig_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Configman_Service_Memcache_MemcacheConfig, parse) {

	HashTable *_1;
	HashPosition _0;
	zval *configure_param = NULL, *rs_config = NULL, *config = NULL, *memcache_config = NULL, *host = NULL, *port = NULL, **_2, _3 = zval_used_for_init, *_4, _5 = zval_used_for_init, *_6, _7 = zval_used_for_init, *_8 = NULL;
	zval *configure = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configure_param);

	zephir_get_arrval(configure, configure_param);
	ZEPHIR_INIT_VAR(rs_config);
	array_init(rs_config);


	zephir_is_iterable(configure, &_1, &_0, 0, 0, "configman/service/memcache/MemcacheConfig.zep", 19);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(config, _2);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, ' ');
		ZEPHIR_INIT_NVAR(memcache_config);
		zephir_fast_explode(memcache_config, &_3, config, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_4, memcache_config, 0, PH_NOISY | PH_READONLY, "configman/service/memcache/MemcacheConfig.zep", 13 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, '=');
		ZEPHIR_INIT_NVAR(host);
		zephir_fast_explode(host, &_5, _4, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_6, memcache_config, 1, PH_NOISY | PH_READONLY, "configman/service/memcache/MemcacheConfig.zep", 14 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, '=');
		ZEPHIR_INIT_NVAR(port);
		zephir_fast_explode(port, &_7, _6, LONG_MAX TSRMLS_CC);
		ZEPHIR_INIT_NVAR(rs_config);
		zephir_create_array(rs_config, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_8);
		zephir_array_fetch_long(&_8, host, 1, PH_NOISY, "configman/service/memcache/MemcacheConfig.zep", 16 TSRMLS_CC);
		zephir_array_fast_append(rs_config, _8);
		ZEPHIR_OBS_NVAR(_8);
		zephir_array_fetch_long(&_8, port, 1, PH_NOISY, "configman/service/memcache/MemcacheConfig.zep", 16 TSRMLS_CC);
		zephir_array_fast_append(rs_config, _8);
	}
	RETURN_CCTOR(rs_config);

}

