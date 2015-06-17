PHP_ARG_ENABLE(configman, whether to enable configman, [ --enable-configman   Enable Configman])

if test "$PHP_CONFIGMAN" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, CONFIGMAN_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_CONFIGMAN, 1, [Whether you have Configman])
	configman_sources="configman.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c configman/baseserviceconfig.zep.c
	configman/service/serviceconfig.zep.c
	configman/service/memcache/memcacheconfig.zep.c
	configman/service/mysql/mysqlconfig.zep.c
	configman/service/rabbitmq/rabbitmqconfig.zep.c
	configman/service/redis/redisconfig.zep.c "
	PHP_NEW_EXTENSION(configman, $configman_sources, $ext_shared,, )
	PHP_SUBST(CONFIGMAN_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([configman], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([configman], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/configman], [php_CONFIGMAN.h])

fi
