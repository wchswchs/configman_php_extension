
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Configman_BaseServiceConfig) {

	ZEPHIR_REGISTER_CLASS(Configman, BaseServiceConfig, configman, baseserviceconfig, configman_baseserviceconfig_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(configman_baseserviceconfig_ce, SL("service"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(configman_baseserviceconfig_ce, SL("config_path"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Configman_BaseServiceConfig, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, _0, *_1 = NULL, *_2;
	zval *service = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service_param);

	zephir_get_strval(service, service_param);


	zephir_update_property_this(this_ptr, SL("service"), service TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "configman.config_path", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 1, &_0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config_path"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config_path"), PH_NOISY_CC);
	if (!(zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "config item configman.config_path error!", "configman/BaseServiceConfig.zep", 14);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Configman_BaseServiceConfig, getService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *service_param = NULL, *service_class_name, *upcase_service, *_0 = NULL;
	zval *service = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service_param);

	zephir_get_strval(service, service_param);


	ZEPHIR_INIT_VAR(upcase_service);
	zephir_ucfirst(upcase_service, service);
	ZEPHIR_INIT_VAR(service_class_name);
	ZEPHIR_CONCAT_SVSVS(service_class_name, "\\Configman\\Service\\", upcase_service, "\\", upcase_service, "Config");
	zephir_fetch_safe_class(_0, service_class_name);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, service);
		zephir_check_call_status();
	}
	RETURN_MM();

}

