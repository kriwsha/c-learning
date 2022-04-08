# Домашняя работа №1

### Задание:

1. Написать программу, определяющую, является ли заданный файл т.н. Rarjpeg-ом (изображением, в конец которого дописан архив), и выводящую список файлов в архиве, если заданный файл таковым является.
2. Для простоты подразумевается формат архива zip, а не rar.
3. Сторонние библиотеки не использовать.

###### Требования:
1. Создано консольное приложение, принимающее аргументом командной строки входной файл.
2. Приложение корректно обрабатывает ошибки доступа к файлу.
3. Приложение корректно подсчитывает и выводит на экран информацию о том, сколько раз в файле встречается каждое слово, которое есть в файле.
4. Код компилируется без warning'ов с ключами компилятора -Wall -Wextra -Wpedantic -std=c11.
5. Далее успешность определяется code review.

### Результат

###### Zip File:
````
input file path: ~\hw1\test\zipjpeg.jpg
file name: jpeg-9d/
file name: jpeg-9d/jmemname.c
file name: jpeg-9d/makermak.vc6
file name: jpeg-9d/jpegint.h
file name: jpeg-9d/jconfig.mac
file name: jpeg-9d/wrjpgcom.c
file name: jpeg-9d/config.guess
file name: jpeg-9d/install-sh
file name: jpeg-9d/jmemsys.h
file name: jpeg-9d/jdmarker.c
file name: jpeg-9d/rdbmp.c
file name: jpeg-9d/jddctmgr.c
file name: jpeg-9d/jpeglib.h
file name: jpeg-9d/makewdep.vc6
file name: jpeg-9d/rdswitch.c
file name: jpeg-9d/jquant1.c
file name: jpeg-9d/makefile.manx
file name: jpeg-9d/jcprepct.c
file name: jpeg-9d/makedmak.vc6
file name: jpeg-9d/jconfig.sas
file name: jpeg-9d/jcmaster.c
file name: jpeg-9d/jdtrans.c
file name: jpeg-9d/jdarith.c
file name: jpeg-9d/makerfil.v16
file name: jpeg-9d/Makefile.in
file name: jpeg-9d/jcparam.c
file name: jpeg-9d/jidctfst.c
file name: jpeg-9d/makecdep.vc6
file name: jpeg-9d/jfdctint.c
file name: jpeg-9d/jconfig.wat
file name: jpeg-9d/compile
file name: jpeg-9d/makefile.b32
file name: jpeg-9d/configure.ac
file name: jpeg-9d/maketdep.vc6
file name: jpeg-9d/jdmerge.c
file name: jpeg-9d/jconfig.cfg
file name: jpeg-9d/makejvcx.v16
file name: jpeg-9d/makejdsw.vc6
file name: jpeg-9d/jdsample.c
file name: jpeg-9d/cjpeg.c
file name: jpeg-9d/cderror.h
file name: jpeg-9d/rdppm.c
file name: jpeg-9d/rdjpgcom.c
file name: jpeg-9d/jpegtran.1
file name: jpeg-9d/jcmainct.c
file name: jpeg-9d/makefile.vms
file name: jpeg-9d/makefile.vs
file name: jpeg-9d/testimg.gif
file name: jpeg-9d/jcapimin.c
file name: jpeg-9d/makeddep.vc6
file name: jpeg-9d/jcinit.c
file name: jpeg-9d/usage.txt
file name: jpeg-9d/makerdep.vc6
file name: jpeg-9d/wrjpgcom.1
file name: jpeg-9d/jcmarker.c
file name: jpeg-9d/jversion.h
file name: jpeg-9d/makefile.mms
file name: jpeg-9d/makewmak.vc6
file name: jpeg-9d/jmemdosa.asm
file name: jpeg-9d/makedvcx.v16
file name: jpeg-9d/cdjpeg.h
file name: jpeg-9d/wrtarga.c
file name: jpeg-9d/jfdctflt.c
file name: jpeg-9d/jidctint.c
file name: jpeg-9d/djpeg.1
file name: jpeg-9d/jdct.h
file name: jpeg-9d/testimg.ppm
file name: jpeg-9d/jcarith.c
file name: jpeg-9d/transupp.h
file name: jpeg-9d/testimg.bmp
file name: jpeg-9d/makvms.opt
file name: jpeg-9d/rdtarga.c
file name: jpeg-9d/makefile.wat
file name: jpeg-9d/libjpeg.pc.in
file name: jpeg-9d/jchuff.c
file name: jpeg-9d/jutils.c
file name: jpeg-9d/makeasln.v16
file name: jpeg-9d/makefile.unix
file name: jpeg-9d/testimg.jpg
file name: jpeg-9d/jccoefct.c
file name: jpeg-9d/makeddsp.vc6
file name: jpeg-9d/jconfig.vc
file name: jpeg-9d/wrgif.c
file name: jpeg-9d/makejsln.v16
file name: jpeg-9d/makefile.vc
file name: jpeg-9d/jconfig.bcc
file name: jpeg-9d/configure
file name: jpeg-9d/makeproj.mac
file name: jpeg-9d/testimgp.jpg
file name: jpeg-9d/makervcx.v16
file name: jpeg-9d/libjpeg.map
file name: jpeg-9d/aclocal.m4
file name: jpeg-9d/makecfil.v16
file name: jpeg-9d/wrbmp.c
file name: jpeg-9d/makejdep.vc6
file name: jpeg-9d/jdhuff.c
file name: jpeg-9d/jidctflt.c
file name: jpeg-9d/structure.txt
file name: jpeg-9d/jmemnobs.c
file name: jpeg-9d/makecvcx.v16
file name: jpeg-9d/makejdsp.vc6
file name: jpeg-9d/jquant2.c
file name: jpeg-9d/jdcolor.c
file name: jpeg-9d/coderules.txt
file name: jpeg-9d/jdmainct.c
file name: jpeg-9d/rdgif.c
file name: jpeg-9d/example.c
file name: jpeg-9d/makedfil.v16
file name: jpeg-9d/jcapistd.c
file name: jpeg-9d/maketfil.v16
file name: jpeg-9d/change.log
file name: jpeg-9d/jconfig.st
file name: jpeg-9d/jdapistd.c
file name: jpeg-9d/jdatasrc.c
file name: jpeg-9d/config.sub
file name: jpeg-9d/djpeg.c
file name: jpeg-9d/rdjpgcom.1
file name: jpeg-9d/missing
file name: jpeg-9d/jdcoefct.c
file name: jpeg-9d/makefile.dj
file name: jpeg-9d/makefile.mc6
file name: jpeg-9d/testprog.jpg
file name: jpeg-9d/Makefile.am
file name: jpeg-9d/jmemmgr.c
file name: jpeg-9d/makefile.sas
file name: jpeg-9d/rdrle.c
file name: jpeg-9d/jmorecfg.h
file name: jpeg-9d/depcomp
file name: jpeg-9d/makdjpeg.st
file name: jpeg-9d/jinclude.h
file name: jpeg-9d/jdmaster.c
file name: jpeg-9d/rdcolmap.c
file name: jpeg-9d/makewdsp.vc6
file name: jpeg-9d/makerdsp.vc6
file name: jpeg-9d/makeadsw.vc6
file name: jpeg-9d/jaricom.c
file name: jpeg-9d/jdinput.c
file name: jpeg-9d/jconfig.vms
file name: jpeg-9d/jctrans.c
file name: jpeg-9d/jcomapi.c
file name: jpeg-9d/makewvcx.v16
file name: jpeg-9d/makefile.bcc
file name: jpeg-9d/jcsample.c
file name: jpeg-9d/jfdctfst.c
file name: jpeg-9d/jerror.h
file name: jpeg-9d/jmemdos.c
file name: jpeg-9d/wizard.txt
file name: jpeg-9d/transupp.c
file name: jpeg-9d/makecdsp.vc6
file name: jpeg-9d/ckconfig.c
file name: jpeg-9d/jmemmac.c
file name: jpeg-9d/makecmak.vc6
file name: jpeg-9d/jpegtran.c
file name: jpeg-9d/filelist.txt
file name: jpeg-9d/cjpeg.1
file name: jpeg-9d/README
file name: jpeg-9d/maketvcx.v16
file name: jpeg-9d/jconfig.dj
file name: jpeg-9d/makcjpeg.st
file name: jpeg-9d/makejmak.vc6
file name: jpeg-9d/jmemansi.c
file name: jpeg-9d/install.txt
file name: jpeg-9d/ltmain.sh
file name: jpeg-9d/wrrle.c
file name: jpeg-9d/jconfig.manx
file name: jpeg-9d/maketdsp.vc6
file name: jpeg-9d/jconfig.mc6
file name: jpeg-9d/jcdctmgr.c
file name: jpeg-9d/ar-lib
file name: jpeg-9d/jdapimin.c
file name: jpeg-9d/makljpeg.st
file name: jpeg-9d/jccolor.c
file name: jpeg-9d/jerror.c
file name: jpeg-9d/makewfil.v16
file name: jpeg-9d/jdpostct.c
file name: jpeg-9d/wrppm.c
file name: jpeg-9d/testorig.jpg
file name: jpeg-9d/makefile.ansi
file name: jpeg-9d/jdatadst.c
file name: jpeg-9d/cdjpeg.c
file name: jpeg-9d/jconfig.txt
file name: jpeg-9d/libjpeg.txt
file name: jpeg-9d/makejfil.v16
file name: jpeg-9d/maketmak.vc6
file name: jpeg-9d/maktjpeg.st
this is zipjpeg

Process finished with exit code 0
````

###### Non Zip File:
````
input file path: ~\hw1\test\non-zipjpeg.jpg
this is non-zipjpeg.
````