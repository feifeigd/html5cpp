@echo off
:: 创建build目录
if not exist build_win mkdir build_win
pushd build_win
cmake -G "Visual Studio 10 2010 Win64" ..
popd
@pause
