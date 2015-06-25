
extern zend_class_entry *configman_baseserviceconfig_ce;

ZEPHIR_INIT_CLASS(Configman_BaseServiceConfig);

PHP_METHOD(Configman_BaseServiceConfig, __construct);
PHP_METHOD(Configman_BaseServiceConfig, getService);

ZEND_BEGIN_ARG_INFO_EX(arginfo_configman_baseserviceconfig___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_configman_baseserviceconfig_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(configman_baseserviceconfig_method_entry) {
	PHP_ME(Configman_BaseServiceConfig, __construct, arginfo_configman_baseserviceconfig___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Configman_BaseServiceConfig, getService, arginfo_configman_baseserviceconfig_getservice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
