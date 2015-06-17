
extern zend_class_entry *configman_service_serviceconfig_ce;

ZEPHIR_INIT_CLASS(Configman_Service_ServiceConfig);

PHP_METHOD(Configman_Service_ServiceConfig, setConfigKey);
PHP_METHOD(Configman_Service_ServiceConfig, add);
PHP_METHOD(Configman_Service_ServiceConfig, read);
PHP_METHOD(Configman_Service_ServiceConfig, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_configman_service_serviceconfig_setconfigkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_configman_service_serviceconfig_add, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_configman_service_serviceconfig_parse, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, configure, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(configman_service_serviceconfig_method_entry) {
	PHP_ME(Configman_Service_ServiceConfig, setConfigKey, arginfo_configman_service_serviceconfig_setconfigkey, ZEND_ACC_PUBLIC)
	PHP_ME(Configman_Service_ServiceConfig, add, arginfo_configman_service_serviceconfig_add, ZEND_ACC_PUBLIC)
	PHP_ME(Configman_Service_ServiceConfig, read, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Configman_Service_ServiceConfig, parse, arginfo_configman_service_serviceconfig_parse, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
