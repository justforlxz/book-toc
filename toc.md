1. 国产处理器与操作系统概况 （10 ~ 15页）

    * 处理器简史 （算筹、算盘、查表、计算尺、机械计算机、电子计算机、芯片、CISC/RISC/架构、指令集）

    * 操作系统简史 （S360、Unix、Windows、Linux、BSD、MacOS、Android、iOS、VxWorks、Fuchsia、seL4）

    * Linux基础与简史 （Linux内核/发行版/开源/GPL协议）

    * 国产处理器与操作系统的必要性（棱镜门、ME、WannaCry、Meltdown、Spectre、中兴事件等）

    * 国产处理器与操作系统简史：汉芯、龙芯、申威、飞腾、兆芯等，红旗、麒麟系列、深度、SylixOS，与主流系统的比较等
2. Linux下的软件开发 （10-15）

    * 安装配置（基于15.9安装系统，分别在物理机上安装单系统、物理机上安装多系统、VirtualBox里安装，基本的使用介绍、使用apt-get与应用商店安装软件）（5-10）

    * 常见的开发环境配置（安装库头文件、使用vim、git、gcc/g++、gdb、make等开发简单的程序：hello, world）（2）

    * 代码目录结构设计：LICENSE、README （2）

    * 使用git进行版本管理（2）
3. Qt5应用程序开发基础 （10页左右）

    * QtCreator的安装与使用 （5）

    * 开发Qt版的hello world （2）

    * Qt5 项目和模块简介（1）

    * Qt项目的代码文件说明，以及如何使用qmake与make进行手工编译（2）
4. 使用Qt开发图形界面软件（35-45页）
    * Qt 元编程简介 （2）
    * signal/slot （1-2）
    * 常见界面元素的使用（10）
    * 使用 QML 与 QSS（10-15）
    * 使用QtWebkit与QtWebEngine开发内嵌浏览器的软件（5）
    * 应用程序图标规范（1）
    * 支持高分屏、触屏手势、托盘图标等（5）
    * Desktop 文件规范（1）
5. 使用Qt开发扩展功能 （25页左右）

    * 文件处理 (文本、INI）（6）

    * 多线程（2）

    * DBus（2）

    * IPC（2）

    * 数据库（2）

    * 图形图像（4）

    * 开发共享库与系统服务（5）
6. 优化Qt应用软件（20-25页）

    * 程序权限鉴定（PAM Polkit）（5-10）

    * 应用程序的国际化（2）

    * 编写单元测试（5）

    * Qt5 插件系统（5）
7. 使用DTK开发应用程序（20-30页）

    * DTK 简介（2）

    * 创建 DTK 程序框架（1）

    * 使用 DTK 中的图形控件（5-10）

    * DTK 中的设置界面框架（3）

    * 在 DTK 中的 DBus（2）

    * 给文件管理器编写插件（3）

    * 给任务栏编写插件（3）
8. 调试与调优（40-50页）

    * gdb的简单使用（5-10）
    * 在QtCreator里进行调试和调优 （5-10）
    * 使用perf进行性能分析（5-10）
    * 使用google-perftools进行性能分析（5）
    * 使用gprof进行性能剖析（5）
    * 使用valgrind与sanitizer进行内存分析（5-10）
9. 维护与发布（40-50页）

    * 创建代码仓库（使用github、gitlab）与进行版本管理（issues、PR、webhooks、分支、tag）（10）

    * 发布（依赖性分析、debian打包与flatpak打包）（15）

    * 代码审核与持续集成（gerrit、jenkins、docker）（15-25）
10. 应用软件的迁移

  * 从Windows迁移到Linux

      * 现状、Windows与Linux的差异、DeepinWine、Mono、驱动、Web前端、Web后端

  * 从Android迁移到Linux

  * 从x86迁移到国产处理器

      * 多架构支持
      
      * 通用的迁移方法
      
      * 交叉编译
      
      * 常见问题
11. 常见问题

   * 多架构平台下开发的常见问题与资源

   * Qt开发的常见问题 （5）

   * DTK接口简要参考 （5）

   * 其它开发工具：VSCode、JetBrains系列工具、Eclipse等

   * Linux开发常用资源（包括deb/rpm的差异比较）