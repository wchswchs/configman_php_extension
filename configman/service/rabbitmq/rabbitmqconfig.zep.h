
extern zend_class_entry *configman_service_rabbitmq_rabbitmqconfig_ce;

ZEPHIR_INIT_CLASS(Configman_Service_Rabbitmq_RabbitmqConfig);

PHP_METHOD(Configman_Service_Rabbitmq_RabbitmqConfig, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_configman_service_rabbitmq_rabbitmqconfig_parse, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, configure, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(configman_service_rabbitmq_rabbitmqconfig_method_entry) {
	PHP_ME(Configman_Service_Rabbitmq_RabbitmqConfig, parse, arginfo_configman_service_rabbitmq_rabbitmqconfig_parse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
