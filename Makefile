#############################################################################
# Makefile for building: cpprest
# Generated by qmake (3.0) (Qt 5.2.1)
# Project:  cpprest.pro
# Template: subdirs
# Command: /usr/lib/x86_64-linux-gnu/qt5/bin/qmake -spec linux-g++-64 CONFIG+=debug -o Makefile cpprest.pro
#############################################################################

MAKEFILE      = Makefile

first: make_first
QMAKE         = /usr/lib/x86_64-linux-gnu/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
SUBTARGETS    =  \
		sub-cpprest \
		sub-example \
		sub-test


sub-cpprest-qmake_all:  FORCE
	@test -d cpprest/ || mkdir -p cpprest/
	cd cpprest/ && $(QMAKE) /media/psf/Home/Developer/cpprest/cpprest/cpprest.pro -spec linux-g++-64 CONFIG+=debug -o Makefile
	cd cpprest/ && $(MAKE) -f Makefile qmake_all
sub-cpprest: FORCE
	@test -d cpprest/ || mkdir -p cpprest/
	cd cpprest/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/cpprest/cpprest.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile
sub-cpprest-make_first: FORCE
	@test -d cpprest/ || mkdir -p cpprest/
	cd cpprest/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/cpprest/cpprest.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile 
sub-cpprest-all: FORCE
	@test -d cpprest/ || mkdir -p cpprest/
	cd cpprest/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/cpprest/cpprest.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile all
sub-cpprest-clean: FORCE
	@test -d cpprest/ || mkdir -p cpprest/
	cd cpprest/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/cpprest/cpprest.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-cpprest-distclean: FORCE
	@test -d cpprest/ || mkdir -p cpprest/
	cd cpprest/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/cpprest/cpprest.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-cpprest-install_subtargets: FORCE
	@test -d cpprest/ || mkdir -p cpprest/
	cd cpprest/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/cpprest/cpprest.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile install
sub-cpprest-uninstall_subtargets: FORCE
	@test -d cpprest/ || mkdir -p cpprest/
	cd cpprest/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/cpprest/cpprest.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-example-qmake_all:  FORCE
	@test -d example/ || mkdir -p example/
	cd example/ && $(QMAKE) /media/psf/Home/Developer/cpprest/example/example.pro -spec linux-g++-64 CONFIG+=debug -o Makefile
	cd example/ && $(MAKE) -f Makefile qmake_all
sub-example: FORCE
	@test -d example/ || mkdir -p example/
	cd example/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/example/example.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile
sub-example-make_first: FORCE
	@test -d example/ || mkdir -p example/
	cd example/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/example/example.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile 
sub-example-all: FORCE
	@test -d example/ || mkdir -p example/
	cd example/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/example/example.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile all
sub-example-clean: FORCE
	@test -d example/ || mkdir -p example/
	cd example/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/example/example.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-example-distclean: FORCE
	@test -d example/ || mkdir -p example/
	cd example/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/example/example.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-example-install_subtargets: FORCE
	@test -d example/ || mkdir -p example/
	cd example/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/example/example.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile install
sub-example-uninstall_subtargets: FORCE
	@test -d example/ || mkdir -p example/
	cd example/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/example/example.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-test-qmake_all:  FORCE
	@test -d test/ || mkdir -p test/
	cd test/ && $(QMAKE) /media/psf/Home/Developer/cpprest/test/test.pro -spec linux-g++-64 CONFIG+=debug -o Makefile
	cd test/ && $(MAKE) -f Makefile qmake_all
sub-test: FORCE
	@test -d test/ || mkdir -p test/
	cd test/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/test/test.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile
sub-test-make_first: FORCE
	@test -d test/ || mkdir -p test/
	cd test/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/test/test.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile 
sub-test-all: FORCE
	@test -d test/ || mkdir -p test/
	cd test/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/test/test.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile all
sub-test-clean: FORCE
	@test -d test/ || mkdir -p test/
	cd test/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/test/test.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile clean
sub-test-distclean: FORCE
	@test -d test/ || mkdir -p test/
	cd test/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/test/test.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile distclean
sub-test-install_subtargets: FORCE
	@test -d test/ || mkdir -p test/
	cd test/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/test/test.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile install
sub-test-uninstall_subtargets: FORCE
	@test -d test/ || mkdir -p test/
	cd test/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/test/test.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile uninstall

Makefile: cpprest.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/shell-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		cpprest.pro
	$(QMAKE) -spec linux-g++-64 CONFIG+=debug -o Makefile cpprest.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/shell-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
cpprest.pro:
qmake: FORCE
	@$(QMAKE) -spec linux-g++-64 CONFIG+=debug -o Makefile cpprest.pro

qmake_all: sub-cpprest-qmake_all sub-example-qmake_all sub-test-qmake_all FORCE

make_first: sub-cpprest-make_first sub-example-make_first sub-test-make_first FORCE
all: sub-cpprest-all sub-example-all sub-test-all FORCE
clean: sub-cpprest-clean sub-example-clean sub-test-clean FORCE
distclean: sub-cpprest-distclean sub-example-distclean sub-test-distclean FORCE
	-$(DEL_FILE) Makefile
install_subtargets: sub-cpprest-install_subtargets sub-example-install_subtargets sub-test-install_subtargets FORCE
uninstall_subtargets: sub-cpprest-uninstall_subtargets sub-example-uninstall_subtargets sub-test-uninstall_subtargets FORCE

sub-cpprest-check:
	@test -d cpprest/ || mkdir -p cpprest/
	cd cpprest/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/cpprest/cpprest.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile check
sub-example-check:
	@test -d example/ || mkdir -p example/
	cd example/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/example/example.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile check
sub-test-check:
	@test -d test/ || mkdir -p test/
	cd test/ && ( test -e Makefile || $(QMAKE) /media/psf/Home/Developer/cpprest/test/test.pro -spec linux-g++-64 CONFIG+=debug -o Makefile ) && $(MAKE) -f Makefile check
check: sub-cpprest-check sub-example-check sub-test-check
install: install_subtargets  FORCE

uninstall:  uninstall_subtargets FORCE

FORCE:

