# configman_php_extension
基础服务统一配置工具php扩展

#Installation
    phpize
    ./configure
    sudo make && make install
    
    [configman]
    extension=configman.so
    
#Runtime Configuration

以mysql为例，如果mysql的db配置在/home/mysql下，则php.ini

    configman.config_path=/home
