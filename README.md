# configman_php_extension
基础服务统一配置工具php扩展

#Installation
    phpize
    ./configure
    sudo make && make install
    
    [configman]
    extension=configman.so
    
#Runtime Configuration

如果mysql等服务的配置在/home下，则php.ini

    configman.config_path=/home
