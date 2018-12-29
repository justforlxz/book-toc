1. 国产处理器与操作系统概况 （10 ~ 15页）

    * 处理器简史 （算筹、算盘、查表、计算尺、机械计算机、电子计算机、芯片、CISC/RISC/架构、指令集）

    * 操作系统简史 （S360、Unix、Windows、Linux、BSD、MacOS、Android、iOS、VxWorks、Fuchsia、seL4）
    
    * Linux基础与简史 （Linux内核/发行版/开源/GPL协议）

    * 国产处理器与操作系统的必要性（棱镜门、ME、WannaCry、Meltdown、Spectre、中兴事件等）
    
    * 国产处理器与操作系统简史：汉芯、龙芯、申威、飞腾、兆芯等，红旗、麒麟系列、深度、SylixOS，与主流系统的比较等

2. Linux下的软件开发 

    * 安装配置（基于15.9安装系统，分别在物理机上安装单系统、物理机上安装多系统、VirtualBox里安装，基本的使用介绍、使用apt-get与应用商店安装软件）

    * 常见的开发环境配置（使用vim、git、gcc/g++、gdb、make等开发简单的程序：hello, world）

    * 代码目录结构设计：LICENSE、README
    
    * 使用git进行版本管理

3. Qt5应用程序开发基础

    * QtCreator的安装与使用

    * 开发Qt版的hello world

    * Qt5 项目和模块简介

    * Qt项目的代码文件说明，以及如何使用qmake与make进行手工编译

4. 使用Qt开发图形界面软件

    * signal/slot

    * 常见界面元素的使用

    * 使用 QML 与 QSS

    * 应用程序图标规范

    * 支持高分屏、触屏手势、托盘图标等
    
    * Desktop 文件规范

5. 使用Qt开发扩展功能

    * 文件处理 (文本、INI、图像）

    * 多线程

    * DBus

    * IPC

    * 数据库

    * 图形图像

    * 开发共享库

6. 优化Qt应用软件

    * 程序权限鉴定（PAM Polkit）

    * 应用程序的国际化

    * 编写单元测试

    * Qt5 插件系统

7. 使用DTK开发应用程序

    * DTK 简介

    * 创建 DTK 程序框架

    * 使用 DTK 中的图形控件

    * DTK 中的设置界面框架

    * 在 DTK 中的 DBus

    * 给文件管理器编写插件

    * 给任务栏编写插件

8. 调试与调优

    * 在QtCreator里进行调试和调优
    
    * gdb的简单使用
    
    * 使用gprof进行性能剖析
    
    * 使用google-perftools进行性能分析
    
    * 使用perf进行性能分析
    
    * 使用valgrind与sanitizer进行内存分析

9. 维护与发布

    * 创建代码仓库（使用github、gitlab与gitea）与进行版本管理（issues、PR、webgooks、分支、tag）

    * 发布（依赖性分析、debian打包与flatpak打包）
    
    * 代码审核与持续集成（gerrit、jenkins、docker）

10. 应用软件的迁移

    * 从Windows迁移到Linux
    
        * DeepinWine、Mono、驱动、Web前端、Web后端
    
    * 从Android迁移到Linux
    
    * 从x86迁移到国产处理器
    
        * 多架构支持
        
        * 通用的迁移方法
        
        * 交叉编译
        
        * 常见问题

11. 常见问题

   * 多架构平台下开发的常见问题与资源

   * Qt开发的常见问题

   * DTK接口简要参考

   * 其它开发工具：VSCode、JetBrains系列工具、Eclipse等

   * Linux开发常用资源（包括deb/rpm的差异比较）
