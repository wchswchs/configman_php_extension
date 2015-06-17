
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Configman_Service_ServiceConfig) {

	ZEPHIR_REGISTER_CLASS_EX(Configman\\Service, ServiceConfig, configman, service_serviceconfig, configman_baseserviceconfig_ce, configman_service_serviceconfig_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(configman_service_serviceconfig_ce, SL("file"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Configman_Service_ServiceConfig, setConfigKey) {

	zval *key_param = NULL, *_0, *_1, *_2, *_3 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	if (!(ZEPHIR_IS_EMPTY(key))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("config_path"), PH_NOISY_CC);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("service"), PH_NOISY_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("service"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VSVSVSVS(_3, _0, "/", _1, "/", key, ".", _2, ".ini");
		zephir_update_property_this(this_ptr, SL("file"), _3 TSRMLS_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("config_path"), PH_NOISY_CC);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("service"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSVS(_3, _0, "/", _1, ".ini");
		zephir_update_property_this(this_ptr, SL("file"), _3 TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Configman_Service_ServiceConfig, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *config_param = NULL, *config_arr, *k = NULL, *item = NULL, **_2, *_3 = NULL, *_4, *_5, _6, _7;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(config, config_param);
	ZEPHIR_INIT_VAR(config_arr);
	array_init(config_arr);


	zephir_is_iterable(config, &_1, &_0, 0, 0, "configman/service/ServiceConfig.zep", 26);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(item, _2);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSV(_3, k, "=", item);
		zephir_array_append(&config_arr, _3, PH_SEPARATE, "configman/service/ServiceConfig.zep", 23);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, ' ');
	zephir_fast_join(_5, &_6, config_arr TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_VS(_3, _5, "\r\n");
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 2, _4, _3, &_7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Configman_Service_ServiceConfig, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *configure = NULL, *config = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&configure, "file", NULL, 3, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&config, this_ptr, "parse", NULL, 0, configure);
	zephir_check_call_status();
	RETURN_CCTOR(config);

}

PHP_METHOD(Configman_Service_ServiceConfig, parse) {

}

