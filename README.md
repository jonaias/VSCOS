VSCOS
=====

VSCOS stands for *V*ery *S*imple *C*ooperative *O*perating *S*ystem and its main goal is to provide a KISS [Cooperative OS](http://en.wikipedia.org/wiki/Computer_multitasking#Cooperative_multitasking) for ARM Cortex-M3/4 uC. 

#### Main Idea ####

VSCOS main idea is enabling executing soft Real Time tasks while doing hard Real Time tasks inside interrupts. 

Variables can be shared between soft and hard Real Time functions as long as operations involving them are atomic and each shared variable are independent of other shared variable (To avoid race conditions).


#### Toolchain ####

The used Toolchain is [Eclipse CDT](http://eclipse.org/) + [GNU ARM Eclipse plugin](http://gnuarmeclipse.livius.net/blog/) as IDE 
and [GNU Tools for ARM Embedded Processors](https://launchpad.net/gcc-arm-embedded) (GCC) as compiler/linker.

#### Porting to other architectures ####

As long as **sysTickTimer** is atomically incremented (ARM Cortex M3/M4 has LDRD/STRD instructions to load/store double words) and an interrupt is assigned to increment it. 


#### History ####

VSCOS was developed inside Spectra Tecnologia which gently opened code as retribution to great work done by many Open Source projects.
