
extern zend_class_entry *configman_service_mysql_mysqlconfig_ce;

ZEPHIR_INIT_CLASS(Configman_Service_Mysql_MysqlConfig);

PHP_METHOD(Configman_Service_Mysql_MysqlConfig, add);
PHP_METHOD(Configman_Service_Mysql_MysqlConfig, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_configman_service_mysql_mysqlconfig_add, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_configman_service_mysql_mysqlconfig_parse, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, configure, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(configman_service_mysql_mysqlconfig_method_entry) {
	PHP_ME(Configman_Service_Mysql_MysqlConfig, add, arginfo_configman_service_mysql_mysqlconfig_add, ZEND_ACC_PUBLIC)
	PHP_ME(Configman_Service_Mysql_MysqlConfig, parse, arginfo_configman_service_mysql_mysqlconfig_parse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
