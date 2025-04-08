cmake_minimum_required(VERSION 3.30)
project(BancoFinal)

set(CMAKE_CXX_STANDARD 20)

add_executable(BancoFinal main.cpp
        Banco.cpp
        Banco.h
        Cliente.cpp
        Cliente.h
        Cuenta.cpp
        Cuenta.h
        Ahorro.cpp
        Ahorro.h
        Corriente.cpp
        Corriente.h)
