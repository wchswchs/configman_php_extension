
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Configman_Service_Rabbitmq_RabbitmqConfig) {

	ZEPHIR_REGISTER_CLASS_EX(Configman\\Service\\Rabbitmq, RabbitmqConfig, configman, service_rabbitmq_rabbitmqconfig, configman_service_serviceconfig_ce, configman_service_rabbitmq_rabbitmqconfig_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Configman_Service_Rabbitmq_RabbitmqConfig, parse) {

	HashTable *_1;
	HashPosition _0;
	zval *configure_param = NULL, *rs_config = NULL, *config = NULL, *rabbit_config = NULL, *host = NULL, *port = NULL, *user = NULL, *password = NULL, *vhost = NULL, **_2, *_3, *_4, *_5, *_6, *_7, *_8 = NULL;
	zval *configure = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configure_param);

	zephir_get_arrval(configure, configure_param);
	ZEPHIR_INIT_VAR(rs_config);
	array_init(rs_config);


	zephir_is_iterable(configure, &_1, &_0, 0, 0, "configman/service/rabbitmq/RabbitmqConfig.zep", 22);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(config, _2);
		ZEPHIR_INIT_NVAR(rabbit_config);
		zephir_fast_explode_str(rabbit_config, SL(" "), config, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_3, rabbit_config, 0, PH_NOISY | PH_READONLY, "configman/service/rabbitmq/RabbitmqConfig.zep", 13 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(host);
		zephir_fast_explode_str(host, SL("="), _3, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_4, rabbit_config, 1, PH_NOISY | PH_READONLY, "configman/service/rabbitmq/RabbitmqConfig.zep", 14 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(port);
		zephir_fast_explode_str(port, SL("="), _4, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_5, rabbit_config, 2, PH_NOISY | PH_READONLY, "configman/service/rabbitmq/RabbitmqConfig.zep", 15 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(user);
		zephir_fast_explode_str(user, SL("="), _5, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_6, rabbit_config, 3, PH_NOISY | PH_READONLY, "configman/service/rabbitmq/RabbitmqConfig.zep", 16 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(password);
		zephir_fast_explode_str(password, SL("="), _6, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_7, rabbit_config, 4, PH_NOISY | PH_READONLY, "configman/service/rabbitmq/RabbitmqConfig.zep", 17 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(vhost);
		zephir_fast_explode_str(vhost, SL("="), _7, LONG_MAX TSRMLS_CC);
		ZEPHIR_INIT_NVAR(rs_config);
		zephir_create_array(rs_config, 5, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_8);
		zephir_array_fetch_long(&_8, host, 1, PH_NOISY, "configman/service/rabbitmq/RabbitmqConfig.zep", 19 TSRMLS_CC);
		zephir_array_fast_append(rs_config, _8);
		ZEPHIR_OBS_NVAR(_8);
		zephir_array_fetch_long(&_8, port, 1, PH_NOISY, "configman/service/rabbitmq/RabbitmqConfig.zep", 19 TSRMLS_CC);
		zephir_array_fast_append(rs_config, _8);
		ZEPHIR_OBS_NVAR(_8);
		zephir_array_fetch_long(&_8, user, 1, PH_NOISY, "configman/service/rabbitmq/RabbitmqConfig.zep", 19 TSRMLS_CC);
		zephir_array_fast_append(rs_config, _8);
		ZEPHIR_OBS_NVAR(_8);
		zephir_array_fetch_long(&_8, password, 1, PH_NOISY, "configman/service/rabbitmq/RabbitmqConfig.zep", 19 TSRMLS_CC);
		zephir_array_fast_append(rs_config, _8);
		ZEPHIR_OBS_NVAR(_8);
		zephir_array_fetch_long(&_8, vhost, 1, PH_NOISY, "configman/service/rabbitmq/RabbitmqConfig.zep", 19 TSRMLS_CC);
		zephir_array_fast_append(rs_config, _8);
	}
	RETURN_CCTOR(rs_config);

}

