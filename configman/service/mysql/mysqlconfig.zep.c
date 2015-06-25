
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Configman_Service_Mysql_MysqlConfig) {

	ZEPHIR_REGISTER_CLASS_EX(Configman\\Service\\Mysql, MysqlConfig, configman, service_mysql_mysqlconfig, configman_service_serviceconfig_ce, configman_service_mysql_mysqlconfig_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Configman_Service_Mysql_MysqlConfig, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *config_param = NULL, *config_arr, *k = NULL, *item = NULL, **_2, *_3 = NULL, *_4, *_5, _6;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(config, config_param);
	ZEPHIR_INIT_VAR(config_arr);
	array_init(config_arr);


	zephir_is_iterable(config, &_1, &_0, 0, 0, "configman/service/mysql/MysqlConfig.zep", 14);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(item, _2);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSV(_3, k, "=", item);
		zephir_array_append(&config_arr, _3, PH_SEPARATE, "configman/service/mysql/MysqlConfig.zep", 11);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("file"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(" "), config_arr TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_3);
	ZEPHIR_CONCAT_VS(_3, _5, "\r\n");
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 3, _4, _3, &_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Configman_Service_Mysql_MysqlConfig, parse) {

	HashTable *_1;
	HashPosition _0;
	zval *configure_param = NULL, *rs_config, *config = NULL, *db_config = NULL, *db = NULL, *host = NULL, *port = NULL, *weight = NULL, *user = NULL, *password = NULL, *is_master = NULL, *master = NULL, **_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_12 = NULL, *_13;
	zval *configure = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configure_param);

	zephir_get_arrval(configure, configure_param);
	ZEPHIR_INIT_VAR(rs_config);
	array_init(rs_config);
	ZEPHIR_INIT_VAR(db_config);
	array_init(db_config);


	zephir_is_iterable(configure, &_1, &_0, 0, 0, "configman/service/mysql/MysqlConfig.zep", 40);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(config, _2);
		ZEPHIR_INIT_NVAR(db_config);
		zephir_fast_explode_str(db_config, SL(" "), config, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_3, db_config, 0, PH_NOISY | PH_READONLY, "configman/service/mysql/MysqlConfig.zep", 23 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(db);
		zephir_fast_explode_str(db, SL("="), _3, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_4, db_config, 1, PH_NOISY | PH_READONLY, "configman/service/mysql/MysqlConfig.zep", 24 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(host);
		zephir_fast_explode_str(host, SL("="), _4, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_5, db_config, 2, PH_NOISY | PH_READONLY, "configman/service/mysql/MysqlConfig.zep", 25 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(port);
		zephir_fast_explode_str(port, SL("="), _5, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_6, db_config, 3, PH_NOISY | PH_READONLY, "configman/service/mysql/MysqlConfig.zep", 26 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(weight);
		zephir_fast_explode_str(weight, SL("="), _6, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_7, db_config, 4, PH_NOISY | PH_READONLY, "configman/service/mysql/MysqlConfig.zep", 27 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(user);
		zephir_fast_explode_str(user, SL("="), _7, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_8, db_config, 5, PH_NOISY | PH_READONLY, "configman/service/mysql/MysqlConfig.zep", 28 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(password);
		zephir_fast_explode_str(password, SL("="), _8, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_9, db_config, 6, PH_NOISY | PH_READONLY, "configman/service/mysql/MysqlConfig.zep", 29 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(is_master);
		zephir_fast_explode_str(is_master, SL("="), _9, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_10, is_master, 1, PH_NOISY | PH_READONLY, "configman/service/mysql/MysqlConfig.zep", 31 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(master);
		if (ZEPHIR_IS_LONG(_10, 1)) {
			ZVAL_STRING(master, "master", 1);
		} else {
			ZVAL_STRING(master, "slave", 1);
		}
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 5, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_12);
		zephir_array_fetch_long(&_12, host, 1, PH_NOISY, "configman/service/mysql/MysqlConfig.zep", 37 TSRMLS_CC);
		zephir_array_fast_append(_11, _12);
		ZEPHIR_OBS_NVAR(_12);
		zephir_array_fetch_long(&_12, port, 1, PH_NOISY, "configman/service/mysql/MysqlConfig.zep", 37 TSRMLS_CC);
		zephir_array_fast_append(_11, _12);
		ZEPHIR_OBS_NVAR(_12);
		zephir_array_fetch_long(&_12, weight, 1, PH_NOISY, "configman/service/mysql/MysqlConfig.zep", 37 TSRMLS_CC);
		zephir_array_fast_append(_11, _12);
		ZEPHIR_OBS_NVAR(_12);
		zephir_array_fetch_long(&_12, user, 1, PH_NOISY, "configman/service/mysql/MysqlConfig.zep", 37 TSRMLS_CC);
		zephir_array_fast_append(_11, _12);
		ZEPHIR_OBS_NVAR(_12);
		zephir_array_fetch_long(&_12, password, 1, PH_NOISY, "configman/service/mysql/MysqlConfig.zep", 37 TSRMLS_CC);
		zephir_array_fast_append(_11, _12);
		zephir_array_fetch_long(&_13, db, 1, PH_NOISY | PH_READONLY, "configman/service/mysql/MysqlConfig.zep", 37 TSRMLS_CC);
		zephir_array_update_multi(&rs_config, &_11 TSRMLS_CC, SL("zza"), 3, _13, master);
	}
	RETURN_CCTOR(rs_config);

}

