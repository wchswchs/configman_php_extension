# configman_php_extension
基础服务统一配置工具php扩展

#install
    phpize
    sudo make && make install
    
    [configman]
    extension=configman.so
    
#runtime configuration

如果mysql等服务的配置在/home下，则php.ini

    configman.config_path=/home
