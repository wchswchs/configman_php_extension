
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
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Configman_BaseServiceConfig) {

	ZEPHIR_REGISTER_CLASS(Configman, BaseServiceConfig, configman, baseserviceconfig, configman_baseserviceconfig_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(configman_baseserviceconfig_ce, SL("service"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(configman_baseserviceconfig_ce, SL("return_type"), 1, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(configman_baseserviceconfig_ce, SL("config_path"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Configman_BaseServiceConfig, __construct) {

	int type, ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *type_param = NULL, *_0, _1, *_2 = NULL;
	zval *service = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &service_param, &type_param);

	zephir_get_strval(service, service_param);
	if (!type_param) {
		type = 1;
	} else {
		type = zephir_get_intval(type_param);
	}


	zephir_update_property_this(this_ptr, SL("service"), service TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, type);
	zephir_update_property_this(this_ptr, SL("return_type"), _0 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "configman.config_path", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "ini_get", NULL, 1, &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config_path"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Configman_BaseServiceConfig, getService) {

	zend_class_entry *_2;
	int type, ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *type_param = NULL, *service_class_name = NULL, *upcase_service, _0, *_1 = NULL, *_3;
	zval *service = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &service_param, &type_param);

	zephir_get_strval(service, service_param);
	if (!type_param) {
		type = 1;
	} else {
		type = zephir_get_intval(type_param);
	}


	ZEPHIR_INIT_VAR(upcase_service);
	zephir_ucfirst(upcase_service, service);
	ZEPHIR_INIT_VAR(service_class_name);
	ZVAL_STRING(service_class_name, "", 1);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "aaa", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "printf", NULL, 2, &_0);
	zephir_check_call_status();
	if (type == 1) {
		ZEPHIR_INIT_NVAR(service_class_name);
		ZEPHIR_CONCAT_SVSVS(service_class_name, "\\Configman\\Service\\", upcase_service, "\\", upcase_service, "Config");
	}
	zephir_fetch_safe_class(_1, service_class_name);
	_2 = zend_fetch_class(Z_STRVAL_P(_1), Z_STRLEN_P(_1), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, type);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, service, _3);
		zephir_check_call_status();
	}
	RETURN_MM();

}

